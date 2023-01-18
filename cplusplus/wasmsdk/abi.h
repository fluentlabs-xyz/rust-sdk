#ifndef _WASMSDK_ABI_H_
#define _WASMSDK_ABI_H_

#include <wasmsdk/array.h>
#include <wasmsdk/uint256.h>
#include <wasmsdk/bytes.h>
#include <wasmsdk/address.h>
#include <wasmsdk/string.h>
#include <wasmsdk/visit.h>
#include <wasmsdk/traits.h>

WASMSDK_BEGIN_NS

/**
 * Args size calculator allows you to calculate
 * size of elements in bytes.
 *
 * Example:
 * _args_size_calculator_<address>::value;
 *
 * Or even for variadic templates:
 * _args_size_calculator_<address, uint32, uint256>::value;
 *
 * If one of types has -1 size (dynamic size) than -1
 * will be returned.
 *
 * @tparam Args
 */
template<typename... Args>
struct _args_size_calculator_ {
    static_assert(true, "unsupported type");
};

template<>
struct _args_size_calculator_<> {
    static const int value = 0;
};
template<>
struct _args_size_calculator_<void> {
    static const int value = 0;
};

template<> struct _args_size_calculator_<uint256> { static const int value = 32; };
template<> struct _args_size_calculator_<uint64> { static const int value = 8; };
template<> struct _args_size_calculator_<int64> { static const int value = 8; };
template<> struct _args_size_calculator_<uint32> { static const int value = 4; };
template<> struct _args_size_calculator_<int32> { static const int value = 4; };
template<> struct _args_size_calculator_<uint16> { static const int value = 2; };
template<> struct _args_size_calculator_<int16> { static const int value = 2; };
template<> struct _args_size_calculator_<uint8> { static const int value = 1; };
template<> struct _args_size_calculator_<int8> { static const int value = 1; };
template<> struct _args_size_calculator_<bytes> { static const int value = -1; };
template<> struct _args_size_calculator_<string> { static const int value = -1; };

template<> struct _args_size_calculator_<bytes1> { static const int value = 1; };
template<> struct _args_size_calculator_<bytes2> { static const int value = 2; };
template<> struct _args_size_calculator_<bytes3> { static const int value = 3; };
template<> struct _args_size_calculator_<bytes4> { static const int value = 4; };
template<> struct _args_size_calculator_<bytes5> { static const int value = 5; };
template<> struct _args_size_calculator_<bytes6> { static const int value = 6; };
template<> struct _args_size_calculator_<bytes7> { static const int value = 7; };
template<> struct _args_size_calculator_<bytes8> { static const int value = 8; };
template<> struct _args_size_calculator_<bytes9> { static const int value = 9; };
template<> struct _args_size_calculator_<bytes10> { static const int value = 10; };
template<> struct _args_size_calculator_<bytes11> { static const int value = 11; };
template<> struct _args_size_calculator_<bytes12> { static const int value = 12; };
template<> struct _args_size_calculator_<bytes13> { static const int value = 13; };
template<> struct _args_size_calculator_<bytes14> { static const int value = 14; };
template<> struct _args_size_calculator_<bytes15> { static const int value = 15; };
template<> struct _args_size_calculator_<bytes16> { static const int value = 16; };
template<> struct _args_size_calculator_<bytes17> { static const int value = 17; };
template<> struct _args_size_calculator_<bytes18> { static const int value = 18; };
template<> struct _args_size_calculator_<bytes19> { static const int value = 19; };
template<> struct _args_size_calculator_<bytes20> { static const int value = 20; };
template<> struct _args_size_calculator_<bytes21> { static const int value = 21; };
template<> struct _args_size_calculator_<bytes22> { static const int value = 22; };
template<> struct _args_size_calculator_<bytes23> { static const int value = 23; };
template<> struct _args_size_calculator_<bytes24> { static const int value = 24; };
template<> struct _args_size_calculator_<bytes25> { static const int value = 25; };
template<> struct _args_size_calculator_<bytes26> { static const int value = 26; };
template<> struct _args_size_calculator_<bytes27> { static const int value = 27; };
template<> struct _args_size_calculator_<bytes28> { static const int value = 28; };
template<> struct _args_size_calculator_<bytes29> { static const int value = 29; };
template<> struct _args_size_calculator_<bytes30> { static const int value = 30; };
template<> struct _args_size_calculator_<bytes31> { static const int value = 31; };
template<> struct _args_size_calculator_<bytes32> { static const int value = 32; };

template<> struct _args_size_calculator_<bool > { static const int value = 1; };

template<typename T, typename... Args>
struct _args_size_calculator_<T, Args...> {
    static const int value =
            _args_size_calculator_<T>::value != -1 && _args_size_calculator_<Args...>::value != -1 ?
                    _args_size_calculator_<T>::value + _args_size_calculator_<Args...>::value : -1;
};

/**
 * Argument decoder is a template structure that
 * decodes and encodes values from input stream
 *
 * @tparam T
 */
template<typename T>
struct abi;

template<typename T>
struct _reinterpret_cast_abi_ {
    static const int32 SIZE = _args_size_calculator_<T>::value;
    static inline uint8* encode(const T& input, uint8 *result) {
        *((T*) result) = input;
        return result + SIZE;
    }
    static inline const uint8* decode(const uint8 *in, T& result) {
        result = *((const T*) in);
        return in + SIZE;
    }
    static inline int32 length(const T&) {
        return SIZE;
    }
};

template<> struct abi<bool> : public _reinterpret_cast_abi_<bool> {};
template<> struct abi<uint64> : public _reinterpret_cast_abi_<uint64> {};
template<> struct abi<int64> : public _reinterpret_cast_abi_<int64> {};
template<> struct abi<uint32> : public _reinterpret_cast_abi_<uint32> {};
template<> struct abi<int32> : public _reinterpret_cast_abi_<int32> {};
template<> struct abi<uint16> : public _reinterpret_cast_abi_<uint16> {};
template<> struct abi<int16> : public _reinterpret_cast_abi_<int16> {};
template<> struct abi<uint8> : public _reinterpret_cast_abi_<uint8> {};
template<> struct abi<int8> : public _reinterpret_cast_abi_<int8> {};

template<>
struct abi<uint256> {
    static const int32 SIZE = _args_size_calculator_<uint256>::value;
    static inline uint8* encode(const uint256& input, uint8* result) {
        for (uint32 i = 0; i < uint256::P; i++) {
            *((uint64*) (result + i * sizeof(uint64))) = input[i];
        }
        return result + SIZE;
    }
    static inline const uint8* decode(const uint8 *in, uint256& result) {
        for (uint32 i = 0; i < uint256::P; i++) {
            result[i] = *((const uint64*) in);
            in += sizeof(uint64);
        }
        return in;
    }
    static inline int32 length(const uint256&) {
        return SIZE;
    }
};

template <typename T>
struct _fixed_array_abi_ {
    static const int32 SIZE = _args_size_calculator_<T>::value;
    static inline uint8* encode(const T &input, uint8 *result) {
        for (uint32 i = 0; i < SIZE; i++) {
            result[i] = static_cast<uint8>(input[i]);
        }
        return result + input.length();
    }
    static inline const uint8* decode(const uint8 *in, T& result) {
        for (uint32 i = 0; i < SIZE; i++) {
            result[i] = in[i];
        }
        return in + T::SIZE;
    }
    static inline int32 length(const T& value) {
        return value.length();
    }
};

template <> struct abi<bytes1> : _fixed_array_abi_<bytes1> {};
template <> struct abi<bytes2> : _fixed_array_abi_<bytes2> {};
template <> struct abi<bytes3> : _fixed_array_abi_<bytes3> {};
template <> struct abi<bytes4> : _fixed_array_abi_<bytes4> {};
template <> struct abi<bytes5> : _fixed_array_abi_<bytes5> {};
template <> struct abi<bytes6> : _fixed_array_abi_<bytes6> {};
template <> struct abi<bytes7> : _fixed_array_abi_<bytes7> {};
template <> struct abi<bytes8> : _fixed_array_abi_<bytes8> {};
template <> struct abi<bytes9> : _fixed_array_abi_<bytes9> {};
template <> struct abi<bytes10> : _fixed_array_abi_<bytes10> {};
template <> struct abi<bytes11> : _fixed_array_abi_<bytes11> {};
template <> struct abi<bytes12> : _fixed_array_abi_<bytes12> {};
template <> struct abi<bytes13> : _fixed_array_abi_<bytes13> {};
template <> struct abi<bytes14> : _fixed_array_abi_<bytes14> {};
template <> struct abi<bytes15> : _fixed_array_abi_<bytes15> {};
template <> struct abi<bytes16> : _fixed_array_abi_<bytes16> {};
template <> struct abi<bytes17> : _fixed_array_abi_<bytes17> {};
template <> struct abi<bytes18> : _fixed_array_abi_<bytes18> {};
template <> struct abi<bytes19> : _fixed_array_abi_<bytes19> {};
template <> struct abi<bytes20> : _fixed_array_abi_<bytes20> {};
template <> struct abi<bytes21> : _fixed_array_abi_<bytes21> {};
template <> struct abi<bytes22> : _fixed_array_abi_<bytes22> {};
template <> struct abi<bytes23> : _fixed_array_abi_<bytes23> {};
template <> struct abi<bytes24> : _fixed_array_abi_<bytes24> {};
template <> struct abi<bytes25> : _fixed_array_abi_<bytes25> {};
template <> struct abi<bytes26> : _fixed_array_abi_<bytes26> {};
template <> struct abi<bytes27> : _fixed_array_abi_<bytes27> {};
template <> struct abi<bytes28> : _fixed_array_abi_<bytes28> {};
template <> struct abi<bytes29> : _fixed_array_abi_<bytes29> {};
template <> struct abi<bytes30> : _fixed_array_abi_<bytes30> {};
template <> struct abi<bytes31> : _fixed_array_abi_<bytes31> {};
template <> struct abi<bytes32> : _fixed_array_abi_<bytes32> {};

template <typename T>
struct _dynamic_array_abi_ {
    static inline uint8* encode(const T &input, uint8 *result) {
        result = abi<uint32>::encode(input.length(), result);
        for (uint32 i = 0; i < input.length(); i++) {
            result[i] = static_cast<uint8>(input[i]);
        }
        return result + input.length();
    }
    static inline const uint8* decode(const uint8 *in, T& result) {
        uint32 length;
        in = abi<uint32>::decode(in, length);
        result.resize(length);
        for (uint32 i = 0; i < length; i++) {
            result[i] = in[i];
        }
        return in + length;
    }
    static inline int32 length(const T& value) {
        return value.length();
    }
};

template<> struct abi<string> : _dynamic_array_abi_<string> {};
template<> struct abi<bytes> : _dynamic_array_abi_<bytes> {};

/* Почему нельзя сделать так? Ты уже реализовывал encode для bytes/string, остается только добавить length для структур
 * и если при операциях в storage _args_size_calculator_ возвращает -1 - создавать буфер длины abi<TYPE>::length() */

WASMSDK_END_NS

#define VISIT_STRUCT_FIELD_DECLTYPE(T) , decltype(T)

#define WASMSDK_ABI_STRUCT(TYPE, ...) \
    VISITABLE_STRUCT(TYPE, __VA_ARGS__); \
    namespace wasmsdk { \
        template<> \
        struct abi<TYPE> { \
        static inline uint8* encode(const TYPE &input, uint8 *result) { \
            visit_struct::for_each(input, [&result](const char*, const auto &value) { \
                result = abi<typename clear_type<decltype(value)>::type>::encode(value, result); \
            }); \
            return result; \
        } \
        static inline const uint8* decode(const uint8 *in, TYPE& result) { \
            visit_struct::for_each(result, [&in](const char*, auto &value) { \
                in = abi<typename clear_type<decltype(value)>::type>::decode(in, value); \
            }); \
            return in; \
        } \
        static inline uint32 length(const TYPE& result) { \
            uint32 length = 0; \
            visit_struct::for_each(result, [&length](const char*, const auto &value) { \
                length += _args_size_calculator_<typename clear_type<decltype(value)>::type>::value; \
            }); \
            return length; \
        } \
        }; \
        template<> \
        struct _args_size_calculator_<TYPE> { \
            static constexpr int value = _args_size_calculator_<void VISIT_STRUCT_PP_MAP_P(TYPE, VISIT_STRUCT_FIELD_DECLTYPE, __VA_ARGS__)>::value; \
        }; \
    }

#endif // ~_WASMSDK_ABI_H_