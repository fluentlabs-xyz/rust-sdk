#include <gtest/gtest.h>

#include <wasmsdk/uint256.h>

using namespace wasmsdk;

TEST(BitWise, or){
    uint256 t  ((bool)     true);
    uint256 f  ((bool)     false);
    uint256 u8 ((uint8)  0xaaULL);
    uint256 u16((uint16) 0xaaaaULL);
    uint256 u32((uint32) 0xaaaaaaaaULL);
    uint256 u64((uint64) 0xaaaaaaaaaaaaaaaaULL);

    const uint256 val(0xf0f0f0f0f0f0f0f0ULL, 0xf0f0f0f0f0f0f0f0ULL);

    EXPECT_EQ(t   |  val, uint256(0xf0f0f0f0f0f0f0f1ULL, 0xf0f0f0f0f0f0f0f0ULL));
    EXPECT_EQ(f   |  val, uint256(0xf0f0f0f0f0f0f0f0ULL, 0xf0f0f0f0f0f0f0f0ULL));
    EXPECT_EQ(u8  |  val, uint256(0xf0f0f0f0f0f0f0faULL, 0xf0f0f0f0f0f0f0f0ULL));
    EXPECT_EQ(u16 |  val, uint256(0xf0f0f0f0f0f0fafaULL, 0xf0f0f0f0f0f0f0f0ULL));
    EXPECT_EQ(u32 |  val, uint256(0xf0f0f0f0fafafafaULL, 0xf0f0f0f0f0f0f0f0ULL));
    EXPECT_EQ(u64 |  val, uint256(0xfafafafafafafafaULL, 0xf0f0f0f0f0f0f0f0ULL));

    EXPECT_EQ(t   |= val, uint256(0xf0f0f0f0f0f0f0f1ULL, 0xf0f0f0f0f0f0f0f0ULL));
    EXPECT_EQ(f   |= val, uint256(0xf0f0f0f0f0f0f0f0ULL, 0xf0f0f0f0f0f0f0f0ULL));
    EXPECT_EQ(u8  |= val, uint256(0xf0f0f0f0f0f0f0faULL, 0xf0f0f0f0f0f0f0f0ULL));
    EXPECT_EQ(u16 |= val, uint256(0xf0f0f0f0f0f0fafaULL, 0xf0f0f0f0f0f0f0f0ULL));
    EXPECT_EQ(u32 |= val, uint256(0xf0f0f0f0fafafafaULL, 0xf0f0f0f0f0f0f0f0ULL));
    EXPECT_EQ(u64 |= val, uint256(0xfafafafafafafafaULL, 0xf0f0f0f0f0f0f0f0ULL));

    // zero
    EXPECT_EQ(uint256() | val, val);
}

TEST(External, or){
    uint256     t   = (uint256) true;
    uint256     f   = (uint256) false;
    uint256  u8  = (uint256) 0xaa;
    uint256 u16 = (uint256) 0xaaaa;
    uint256 u32 = (uint256) 0xaaaaaaaaULL;
    uint256 u64 = (uint256) 0xaaaaaaaaaaaaaaaaULL;

    const uint256 val(0xf0f0f0f0f0f0f0f0ULL, 0xf0f0f0f0f0f0f0f0ULL);

    EXPECT_EQ(t   |  val, uint256(0xf0f0f0f0f0f0f0f1ULL, 0xf0f0f0f0f0f0f0f0ULL));
    EXPECT_EQ(f   |  val, uint256(0xf0f0f0f0f0f0f0f0ULL, 0xf0f0f0f0f0f0f0f0ULL));
    EXPECT_EQ(u8  |  val, uint256(0xf0f0f0f0f0f0f0faULL, 0xf0f0f0f0f0f0f0f0ULL));
    EXPECT_EQ(u16 |  val, uint256(0xf0f0f0f0f0f0fafaULL, 0xf0f0f0f0f0f0f0f0ULL));
    EXPECT_EQ(u32 |  val, uint256(0xf0f0f0f0fafafafaULL, 0xf0f0f0f0f0f0f0f0ULL));
    EXPECT_EQ(u64 |  val, uint256(0xfafafafafafafafaULL, 0xf0f0f0f0f0f0f0f0ULL));

    EXPECT_EQ(t   |= val, uint256(0xf0f0f0f0f0f0f0f1ULL, 0xf0f0f0f0f0f0f0f0ULL));
    EXPECT_EQ(f   |= val, uint256(0xf0f0f0f0f0f0f0f0ULL, 0xf0f0f0f0f0f0f0f0ULL));
    EXPECT_EQ(u8  |= val, uint256(0xf0f0f0f0f0f0f0faULL, 0xf0f0f0f0f0f0f0f0ULL));
    EXPECT_EQ(u16 |= val, uint256(0xf0f0f0f0f0f0fafaULL, 0xf0f0f0f0f0f0f0f0ULL));
    EXPECT_EQ(u32 |= val, uint256(0xf0f0f0f0fafafafaULL, 0xf0f0f0f0f0f0f0f0ULL));
    EXPECT_EQ(u64 |= val, uint256(0xfafafafafafafafaULL, 0xf0f0f0f0f0f0f0f0ULL));

    // zero
    EXPECT_EQ(uint256() | val, val);
}
