#include <gtest/gtest.h>

#include <wasmsdk/uint256.h>

using namespace wasmsdk;

TEST(Arithmetic, multiply){

    EXPECT_EQ(uint256(3) * uint256(7), uint256(21));

    uint256 val(0xfedbca9876543210ULL);

    EXPECT_EQ(val * val, uint256(0x010e6cd7a44a4100ULL, 0xfdb8e2bacbfe7cefULL, 0x0000000000000000ULL, 0x0000000000000000ULL));

    const uint256 zero = uint256(0);
    EXPECT_EQ(val  * zero, zero);
    EXPECT_EQ(zero * val,  zero);

    const uint256 one = uint256(1);
    EXPECT_EQ(val * one, val);
    EXPECT_EQ(one * val, val);
}

TEST(External, multiply){
    uint256      t    = (uint256) true;
    uint256      f    = (uint256) false;
    uint256   u8   = (uint256) 0xaaULL;
    uint256  u16  = (uint256) 0xaaaaULL;
    uint256  u32  = (uint256) 0xaaaaaaaaULL;
    uint256  u64  = (uint256) 0xaaaaaaaaaaaaaaaaULL;

    const uint256 val(0xf0f0f0f0f0f0f0f0ULL, 0xf0f0f0f0f0f0f0f0ULL, 0xf0f0f0f0f0f0f0f0ULL, 0xf0f0f0f0f0f0f0f0ULL);

    EXPECT_EQ(t    *  val, uint256(0xf0f0f0f0f0f0f0f0ULL, 0xf0f0f0f0f0f0f0f0ULL, 0xf0f0f0f0f0f0f0f0ULL, 0xf0f0f0f0f0f0f0f0ULL));
    EXPECT_EQ(f    *  val, uint256(0x0000000000000000ULL, 0x0000000000000000ULL, 0x0000000000000000ULL, 0x0000000000000000ULL));
    EXPECT_EQ(u8   *  val, uint256(0xffffffffffffff60ULL, 0xffffffffffffffffULL, 0xffffffffffffffffULL, 0xffffffffffffffffULL));
    EXPECT_EQ(u16  *  val, uint256(0xffffffffffff5f60ULL, 0xffffffffffffffffULL, 0xffffffffffffffffULL, 0xffffffffffffffffULL));
    EXPECT_EQ(u32  *  val, uint256(0xffffffff5f5f5f60ULL, 0xffffffffffffffffULL, 0xffffffffffffffffULL, 0xffffffffffffffffULL));
    EXPECT_EQ(u64  *  val, uint256(0x5f5f5f5f5f5f5f60ULL, 0xffffffffffffffffULL, 0xffffffffffffffffULL, 0xffffffffffffffffULL));

    EXPECT_EQ(t    *= val, uint256(0xf0f0f0f0f0f0f0f0ULL, 0xf0f0f0f0f0f0f0f0ULL, 0xf0f0f0f0f0f0f0f0ULL, 0xf0f0f0f0f0f0f0f0ULL));
    EXPECT_EQ(f    *= val, uint256(0x0000000000000000ULL, 0x0000000000000000ULL, 0x0000000000000000ULL, 0x0000000000000000ULL));
    EXPECT_EQ(u8   *= val, uint256(0xffffffffffffff60ULL, 0xffffffffffffffffULL, 0xffffffffffffffffULL, 0xffffffffffffffffULL));
    EXPECT_EQ(u16  *= val, uint256(0xffffffffffff5f60ULL, 0xffffffffffffffffULL, 0xffffffffffffffffULL, 0xffffffffffffffffULL));
    EXPECT_EQ(u32  *= val, uint256(0xffffffff5f5f5f60ULL, 0xffffffffffffffffULL, 0xffffffffffffffffULL, 0xffffffffffffffffULL));
    EXPECT_EQ(u64  *= val, uint256(0x5f5f5f5f5f5f5f60ULL, 0xffffffffffffffffULL, 0xffffffffffffffffULL, 0xffffffffffffffffULL));
}
