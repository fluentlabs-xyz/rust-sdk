#include <gtest/gtest.h>

#include <wasmsdk/uint256.h>

using namespace wasmsdk;

TEST(Arithmetic, subtract){
    uint256 big  (0xffffffffffffffffULL, 0xffffffffffffffffULL, 0xffffffffffffffffULL, 0xffffffffffffffffULL);
    const uint256 small(0x0000000000000001ULL, 0x0000000000000000ULL);

    EXPECT_EQ(small - small, uint256(0));
    EXPECT_EQ(small - big,   uint256(0x0000000000000002ULL, 0x0000000000000000ULL, 0x0000000000000000ULL, 0x0000000000000000ULL));
    EXPECT_EQ(big   - small, uint256(0xfffffffffffffffeULL, 0xffffffffffffffffULL, 0xffffffffffffffffULL, 0xffffffffffffffffULL));
    EXPECT_EQ(big   - big,   uint256(0));
}

TEST(External, subtract){
    uint256   t  = (uint256) true;
    uint256   f  = (uint256) false;
    uint256  u8  = (uint256) 0xaaULL;
    uint256 u16  = (uint256) 0xaaaaULL;
    uint256 u32  = (uint256) 0xaaaaaaaaULL;
    uint256 u64  = (uint256) 0xaaaaaaaaaaaaaaaaULL;

    const uint256 val(0xf0f0f0f0f0f0f0f0ULL, 0xf0f0f0f0f0f0f0f0ULL, 0xf0f0f0f0f0f0f0f0ULL, 0xf0f0f0f0f0f0f0f0ULL);

    EXPECT_EQ(t    -  val, uint256(0x0f0f0f0f0f0f0f11ULL, 0x0f0f0f0f0f0f0f0fULL, 0x0f0f0f0f0f0f0f0fULL, 0x0f0f0f0f0f0f0f0fULL));
    EXPECT_EQ(f    -  val, uint256(0x0f0f0f0f0f0f0f10ULL, 0x0f0f0f0f0f0f0f0fULL, 0x0f0f0f0f0f0f0f0fULL, 0x0f0f0f0f0f0f0f0fULL));
    EXPECT_EQ(u8   -  val, uint256(0x0f0f0f0f0f0f0fbaULL, 0x0f0f0f0f0f0f0f0fULL, 0x0f0f0f0f0f0f0f0fULL, 0x0f0f0f0f0f0f0f0fULL));
    EXPECT_EQ(u16  -  val, uint256(0x0f0f0f0f0f0fb9baULL, 0x0f0f0f0f0f0f0f0fULL, 0x0f0f0f0f0f0f0f0fULL, 0x0f0f0f0f0f0f0f0fULL));
    EXPECT_EQ(u32  -  val, uint256(0x0f0f0f0fb9b9b9baULL, 0x0f0f0f0f0f0f0f0fULL, 0x0f0f0f0f0f0f0f0fULL, 0x0f0f0f0f0f0f0f0fULL));
    EXPECT_EQ(u64  -  val, uint256(0xb9b9b9b9b9b9b9baULL, 0x0f0f0f0f0f0f0f0fULL, 0x0f0f0f0f0f0f0f0fULL, 0x0f0f0f0f0f0f0f0fULL));

    EXPECT_EQ(t    -= val, uint256(0x0f0f0f0f0f0f0f11ULL, 0x0f0f0f0f0f0f0f0fULL, 0x0f0f0f0f0f0f0f0fULL, 0x0f0f0f0f0f0f0f0fULL));
    EXPECT_EQ(f    -= val, uint256(0x0f0f0f0f0f0f0f10ULL, 0x0f0f0f0f0f0f0f0fULL, 0x0f0f0f0f0f0f0f0fULL, 0x0f0f0f0f0f0f0f0fULL));
    EXPECT_EQ(u8   -= val, uint256(0x0f0f0f0f0f0f0fbaULL, 0x0f0f0f0f0f0f0f0fULL, 0x0f0f0f0f0f0f0f0fULL, 0x0f0f0f0f0f0f0f0fULL));
    EXPECT_EQ(u16  -= val, uint256(0x0f0f0f0f0f0fb9baULL, 0x0f0f0f0f0f0f0f0fULL, 0x0f0f0f0f0f0f0f0fULL, 0x0f0f0f0f0f0f0f0fULL));
    EXPECT_EQ(u32  -= val, uint256(0x0f0f0f0fb9b9b9baULL, 0x0f0f0f0f0f0f0f0fULL, 0x0f0f0f0f0f0f0f0fULL, 0x0f0f0f0f0f0f0f0fULL));
    EXPECT_EQ(u64  -= val, uint256(0xb9b9b9b9b9b9b9baULL, 0x0f0f0f0f0f0f0f0fULL, 0x0f0f0f0f0f0f0f0fULL, 0x0f0f0f0f0f0f0f0fULL));
}