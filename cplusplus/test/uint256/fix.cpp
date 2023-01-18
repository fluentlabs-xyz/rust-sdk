#include <gtest/gtest.h>

#include <wasmsdk/uint256.h>

using namespace wasmsdk;

TEST(Arithmetic, increment){
    uint256 value(0);
    EXPECT_EQ(++value, uint256(1));
    EXPECT_EQ(value++, uint256(1));
    EXPECT_EQ(++value, uint256(3));
}

TEST(Arithmetic, decrement){
    uint256 value(0);
    EXPECT_EQ(--value, uint256(0xffffffffffffffffULL, 0xffffffffffffffffULL, 0xffffffffffffffffULL, 0xffffffffffffffffULL));
    EXPECT_EQ(value--, uint256(0xffffffffffffffffULL, 0xffffffffffffffffULL, 0xffffffffffffffffULL, 0xffffffffffffffffULL));
    EXPECT_EQ(--value, uint256(0xfffffffffffffffdULL, 0xffffffffffffffffULL, 0xffffffffffffffffULL, 0xffffffffffffffffULL));
}