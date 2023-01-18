#ifndef _WASMSDK_STORAGE_H_
#define _WASMSDK_STORAGE_H_

#include <wasmsdk/define.h>
#include <wasmsdk/uint256.h>
#include <wasmsdk/abi.h>
#include <wasmsdk/pearson.h>
#include <wasmsdk/crypto.h>

WASMSDK_BEGIN_NS

static void keccak256_sum(uint8* hash, int delta) {
    constexpr int HASH_SIZE = 32;
    constexpr int UINT256_SIZE = 256;
    bool check_max_hash = true;
    for (int i = 0; i < HASH_SIZE - 2; ++i) {
        if (hash[i] != 0xff) {
            check_max_hash = false;
        }
    }
    if (check_max_hash) {
        return;
    }
    const uint8 deltas[2] = {uint8(delta % UINT256_SIZE), uint8(delta / UINT256_SIZE)};
    for (int i = 0; i < 2; ++i) {
        uint8 remainder = 0;
        for (int j = HASH_SIZE - i - 1; j >= 0; --j) {
            int sum = hash[j] + (j == HASH_SIZE - i - 1 ? deltas[i] : 0) + remainder;
            remainder = uint8(sum / hash[j]);
            hash[j] = uint8(sum % UINT256_SIZE);
        }
    }
}

template<typename K, typename V>
static V load_from_storage(uint8 m, const K &key) {
    constexpr int KEY_SIZE = _args_size_calculator_<K>::value;
    constexpr int VAL_SIZE = _args_size_calculator_<V>::value;
    /* check that key and value are types with static sizes */
    //static_assert(KEY_SIZE >= 0, "This function can't serialize keys with dynamic size");
    //static_assert(VAL_SIZE >= 0, "This function can't deserialize values with dynamic size");
    /* encode key and with to array with mapping prefix */
    const int total_size = (KEY_SIZE == -1 ? abi<K>::length(key) : KEY_SIZE) + 1;
    uint8 packed_key[total_size];
    abi<K>::encode(key, packed_key + 1);
    packed_key[0] = m;
    /* calculate super hash for this key */
    constexpr int BUFFER_SIZE_WORDS = VAL_SIZE == -1 ? 1 : (VAL_SIZE + 31) / 32;
    uint32 buffer_length = 0;
    static_assert(BUFFER_SIZE_WORDS <= 256 * 256, "Maximum allowed value size is 2048 KiB");
    uint8 data[(VAL_SIZE == -1 ? 1 : BUFFER_SIZE_WORDS) * 32];
    //uint8 data[BUFFER_SIZE_WORDS * 32];
    uint8 super_hash[32];
    crypto_keccak256(packed_key, total_size, super_hash);
    if (VAL_SIZE == -1) {
        load_storage(super_hash, data);
        uint32 length;
        abi<uint32>::decode(data, length);
        buffer_length = (length + 35) / 32;
//        data = static_cast<uint8*>(realloc(data, 32 * buffer_length * sizeof(data)));
        keccak256_sum(super_hash, 1);
    }
    for (int i = (VAL_SIZE == -1); i < (BUFFER_SIZE_WORDS == 1 ? buffer_length : BUFFER_SIZE_WORDS); ++i) {
        /*packed_key[KEY_SIZE + 1] = static_cast<uint8>(i % 256);
        packed_key[KEY_SIZE + 2] = static_cast<uint8>(i / 256);*/
        load_storage(super_hash, data + i * 32);
        keccak256_sum(super_hash, 1);
    }
    /* decode value */
    V value;
    abi<V>::decode(data, value);
    return value;
}

template<typename V>
static inline V load_from_storage(uint8 m) {
    return load_from_storage<address, V>(m, address());
}

template <typename K, typename V>
static void save_to_storage(uint8 m, const K& key, const V& value) {
    constexpr int KEY_SIZE = _args_size_calculator_<K>::value;
    constexpr int VAL_SIZE = _args_size_calculator_<V>::value;
    /* check that key and value are types with static sizes */
    //static_assert(KEY_SIZE >= 0, "This function can't serialize keys with dynamic size");
    //static_assert(VAL_SIZE >= 0, "This function can't deserialize values with dynamic size");
    /* pack value */

    const int total_size_k = (KEY_SIZE == -1 ? abi<K>::length(key) : KEY_SIZE) + 1;
    const int total_size_v = (VAL_SIZE == -1 ? abi<V>::length(value) : VAL_SIZE);
    uint8 packed_value[total_size_v];
    abi<V>::encode(value, packed_value);
    /* encode key and with to array with mapping prefix */
    uint8 packed_key[total_size_k + 1];
    abi<K>::encode(key, packed_key + 1);
    packed_key[0] = m;
    /* calculate super hash for this key */
    constexpr int BUFFER_SIZE_WORDS = (total_size_v + 31) / 32;
    static_assert(BUFFER_SIZE_WORDS <= 256 * 256, "Maximum allowed value size is 2048 KiB");
    uint8 super_hash[32];
    crypto_keccak256(packed_key, total_size_k + 1, super_hash);
    for (int i = 0; i < BUFFER_SIZE_WORDS; ++i) {
        /*packed_key[KEY_SIZE + 1] = static_cast<uint8>(i % 256);
        packed_key[KEY_SIZE + 2] = static_cast<uint8>(i / 256);*/
        keccak256_sum(super_hash, 1);
        save_storage(super_hash, packed_value + i * 32);

    }
}

template<typename V>
static inline void save_to_storage(uint8 m, const V& value) {
    save_to_storage<address, V>(m, address(), value);
}

template <typename V>
class property {
public:
    explicit constexpr property(uint8 m) : _m(m) {
    }
public:
    inline property& operator= (const V& value) {
        save_to_storage<address, V>(this->_m, address(), value);
        return *this;
    }
    inline operator V () {
        return load_from_storage<address, V>(this->_m, address());
    }
private:
    uint8 _m;
};

template <typename K, typename V>
class storage {
public:
    explicit storage(uint8 m) : _m(m) {
    }
    ~storage() {
    }
public:
    inline const V& operator[] (const K& key) const {
        return load_from_storage<K, V>(this->_m, key);
    }
    struct _value_assigner_ : V {
        _value_assigner_(uint8 m, const K& key, const V& val) : V(val), _key(key), _m(m) {
        }
        inline _value_assigner_& operator=(const V& value) {
            V::operator=(value);
            save_to_storage<K, V>(this->_m, this->_key, value);
            return *this;
        }
        const K& _key;
        uint8 _m;
    };
    inline _value_assigner_ operator[] (const K& key) {
        V value = load_from_storage<K, V>(this->_m, key);
        return _value_assigner_{ this->_m, key, value };
    }
private:
    uint8 _m;
};

/**
 * This is dynamic storage_array
 *
 * @tparam T type of storage_array element
 */
template <typename V>
class storage_array : public storage<uint32, V> {
public:
    storage_array(const storage_array &) = default;
    storage_array(storage_array &&) noexcept = default;

    explicit storage_array(uint8 m, uint32 length = 0) {
        this->_m = m;
        save_to_storage<uint32, uint32>(this->_m, 0, length);
        for (uint32 i = 0; i < length; ++i) {
            this->operator[](i) = V();
        }
    }
    ~storage_array() {
    }

public:
    inline uint32 length() const {
        return load_from_storage<uint32, uint32>(this->_m, 0);
    }

    inline void clear() {
        save_to_storage<uint32, uint32>(this->_m, 0, 0);
    }

    inline const V& operator[] (uint32 i) const {
        if (i < 0 || i >= this->length()) {
            system_halt(HALT_CODE_BUFFER_OVERFLOW);
        }
        return load_from_storage<uint32, V>(this->_m, i + 1);
    }

    struct _value_assigner_ : V {
        _value_assigner_(uint8 m, uint32 i, const V& val) : V(val), _i(i), _m(m) {
        }
        inline _value_assigner_& operator=(const V& value) {
            V::operator=(value);
            save_to_storage<uint32, V>(this->_m, this->_i + 1, value);
            return *this;
        }
        uint32 _i;
        uint8 _m;
    };

    inline _value_assigner_ operator[] (uint32 i) {
        V value = load_from_storage<uint32, V>(this->_m, i + 1);
        return _value_assigner_{ this->_m, i, value };
    }

    inline void push(const V& a) {
        save_to_storage<uint32, uint32>(this->_m, 0, this->length() + 1);
        this->operator[](this->length()) = a;
    }
private:
    uint8 _m;
};

WASMSDK_END_NS

#endif // ~_WASMSDK_STORAGE_H_