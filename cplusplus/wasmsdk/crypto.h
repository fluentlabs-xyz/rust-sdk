#ifndef _WASMSDK_CRYPTO_H_
#define _WASMSDK_CRYPTO_H_

#include <wasmsdk/define.h>

WASMSDK_BEGIN_NS

WASMSDK_EXPORT {
    void crypto_keccak256(void* data_offset, int data_length, void* result_offset);
    void crypto_sha256(void* data_offset, int data_length, void* result_offset);
    void crypto_ripemd160(void* data_offset, int data_length, void* result_offset);
    void crypto_murmur3(void* data_offset, int data_length, void* result_offset, int seed);
    void crypto_recover(void* data_offset, int data_length, void* result_offset);
    void crypto_verify(void* data_offset, int data_length, void* result_offset);
}

WASMSDK_END_NS

#endif // ~_WASMSDK_CRYPTO_H_