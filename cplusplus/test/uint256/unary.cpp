#include <gtest/gtest.h>

#include <wasmsdk/uint256.h>

using namespace wasmsdk;

TEST(Arithmetic, unary_plus){
    const uint256 value(0x12345ULL);
    EXPECT_EQ(+value, value);
}

TEST(Arithmetic, unary_minus){
    const uint256 val(1);
    const uint256 neg = -val;
    EXPECT_EQ(-val, neg);
    EXPECT_EQ(-neg, val);
    EXPECT_EQ(neg, uint256(0xffffffffffffffffULL, 0xffffffffffffffffULL, 0xffffffffffffffffULL, 0xffffffffffffffffULL));
}