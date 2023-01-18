//
// Created by skird on 31.01.19.
//

#include <gtest/gtest.h>
#include <wasmsdk/abi.h>

using namespace wasmsdk;

TEST(AbiDecoder, decodeUint64){
    uint64_t array[2] = { 0xdeadbeef, 0xfee1baad };
    uint64 x = 0;
    const uint8 *result = abi<uint64>::decode((const uint8*) array, x);
    ASSERT_EQ(result, (const uint8*)(array + 1));
    ASSERT_EQ(x, array[0]);
    result = abi<uint64>::decode(result, x);
    ASSERT_EQ(result, (const uint8*)(array + 2));
    ASSERT_EQ(x, array[1]);
}

