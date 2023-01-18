#ifndef _WASMSDK_INVOKE_H_
#define _WASMSDK_INVOKE_H_

#include <wasmsdk/system.h>
#include <wasmsdk/abi.h>

WASMSDK_BEGIN_NS

inline uint32 read_method_signature() {
    auto call_data_size = static_cast<uint32>(get_call_size());
    if (call_data_size < 4) {
        return static_cast<uint32>(-1);
    }
    uint8 input[_args_size_calculator_<uint32>::value];
    copy_call_value(0, 4, input);
    uint32 result;
    abi<uint32>::decode(input, result);
    return result;
}

template<typename V, uint32 S>
inline void return_value(const fixed_array<V, S>& value) {
    auto size = static_cast<uint32>(_args_size_calculator_<uint32>::value + value.length());
    uint8 data[S];
    abi<string>::encode(value, data);
    set_return(data, size);
}

template <typename V>
inline void return_value(const V& value) {
    uint8 data[_args_size_calculator_<V>::value];
    abi<V>::encode(value, data);
    set_return(data, sizeof(data));
}

template<>
inline void return_value<string>(const string& value) {
    auto size = static_cast<uint32>(_args_size_calculator_<uint32>::value + value.length());
    auto data = new uint8[size];
    abi<string>::encode(value, data);
    set_return(data, size);
    delete[] data;
}

template<>
inline void return_value<bytes>(const bytes& value) {
    auto size = static_cast<uint32>(_args_size_calculator_<uint32>::value + value.length());
    auto data = new uint8[size];
    abi<bytes>::encode(value, data);
    set_return(data, size);
    delete[] data;
}

inline address get_sender() {
    uint8 data[_args_size_calculator_<address>::value];
    get_sender(data);
    address result;
    abi<address>::decode(data, result);
    return result;
}

/* using initializer lists to avoid unspecified order of arguments evaluation */
template <typename R>
struct _invoke_helper_ {
    template<typename ...T>
    explicit _invoke_helper_(R(*fn)(T...), const T&... args) {
        return_value(fn(args...));
    }
};
template <>
struct _invoke_helper_<void> {
    template<typename ...T>
    explicit _invoke_helper_(void(*fn)(T...), const T&... args) {
        fn(args...);
    }
};

template <typename T>
static inline T _decode_helper_(const uint8 *&in) {
    T result;
    in = abi<T>::decode(in, result);
    return result;
}

template <typename R, typename ...Args>
inline void invoke_contract_method(R(*fn)(Args...)) {
    int32 call_size = get_call_size();
    constexpr int32 args_size = _args_size_calculator_<Args...>::value;
    /* if args size is -1 than we have dynamic types in input or check input length */
    if constexpr (args_size >= 0) {
        assert(args_size + 4 == call_size, HALT_CODE_INVALID_ABI_ENCODED);
        uint8 input[args_size];
        copy_call_value(4, 4 + sizeof(input), input);
        const uint8* ptr = &input[0];
        _invoke_helper_<R>{fn, _decode_helper_<Args>(ptr)...};
    } else {
        assert(call_size >= 4, HALT_CODE_INVALID_ABI_ENCODED);
        auto input = new uint8[call_size - 4];
        copy_call_value(4, call_size, input);
        const uint8* ptr = input;
        _invoke_helper_<R>{fn, _decode_helper_<Args>(ptr)...};
        delete[] input;
    }
}

template <typename R>
inline void invoke_contract_method(R(*fn)()) {
    /* using initializer lists to avoid unspecified order of arguments evaluation */
    _invoke_helper_<R>{fn};
}

WASMSDK_END_NS

#endif // ~_WASMSDK_INVOKE_H_