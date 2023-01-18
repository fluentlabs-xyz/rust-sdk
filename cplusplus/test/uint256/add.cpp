#include <gtest/gtest.h>

#include <wasmsdk/uint256.h>

using namespace wasmsdk;

TEST(Arithmetic, add){
    uint256 low (1, 0);
    uint256 high(0, 1);

    EXPECT_EQ(low  + low,  uint256(2));
    EXPECT_EQ(low  + high, uint256(1, 1));
    EXPECT_EQ(high + high, uint256(0, 2));

    EXPECT_EQ(low  += low,  uint256(2));
    EXPECT_EQ(low  += high, uint256(2, 1));
    EXPECT_EQ(high += low,  uint256(2, 2));

    uint256 hundred(0x6bc75e2d63100000ULL, 0x5ULL, 0, 0);
    uint256 two_hundred(0xd78ebc5ac6200000ULL, 0xaULL, 0, 0);
    EXPECT_EQ(hundred + hundred, two_hundred);
    EXPECT_EQ(hundred += hundred, two_hundred);
}

TEST(External, add){
    uint256     t     = uint256(true);
    uint256     f     = uint256(false);
    uint256  u8    = uint256(0xaaULL);
    uint256 u16   = uint256(0xaaaaULL);
    uint256 u32   = uint256(0xaaaaaaaaULL);
    uint256 u64   = uint256(0xaaaaaaaaaaaaaaaaULL);

    const uint256 val(0xf0f0f0f0f0f0f0f0ULL, 0xf0f0f0f0f0f0f0f0ULL, 0xf0f0f0f0f0f0f0f0ULL, 0xf0f0f0f0f0f0f0f0ULL);

    EXPECT_EQ(t    +  val, uint256(0xf0f0f0f0f0f0f0f1ULL, 0xf0f0f0f0f0f0f0f0ULL, 0xf0f0f0f0f0f0f0f0ULL, 0xf0f0f0f0f0f0f0f0ULL));
    EXPECT_EQ(f    +  val, uint256(0xf0f0f0f0f0f0f0f0ULL, 0xf0f0f0f0f0f0f0f0ULL, 0xf0f0f0f0f0f0f0f0ULL, 0xf0f0f0f0f0f0f0f0ULL));
    EXPECT_EQ(u8   +  val, uint256(0xf0f0f0f0f0f0f19aULL, 0xf0f0f0f0f0f0f0f0ULL, 0xf0f0f0f0f0f0f0f0ULL, 0xf0f0f0f0f0f0f0f0ULL));
    EXPECT_EQ(u16  +  val, uint256(0xf0f0f0f0f0f19b9aULL, 0xf0f0f0f0f0f0f0f0ULL, 0xf0f0f0f0f0f0f0f0ULL, 0xf0f0f0f0f0f0f0f0ULL));
    EXPECT_EQ(u32  +  val, uint256(0xf0f0f0f19b9b9b9aULL, 0xf0f0f0f0f0f0f0f0ULL, 0xf0f0f0f0f0f0f0f0ULL, 0xf0f0f0f0f0f0f0f0ULL));
    EXPECT_EQ(u64  +  val, uint256(0x9b9b9b9b9b9b9b9aULL, 0xf0f0f0f0f0f0f0f1ULL, 0xf0f0f0f0f0f0f0f0ULL, 0xf0f0f0f0f0f0f0f0ULL));
}
