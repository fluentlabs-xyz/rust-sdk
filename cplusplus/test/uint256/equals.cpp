#include <gtest/gtest.h>

#include <wasmsdk/uint256.h>

using namespace wasmsdk;

TEST(Comparison, equals){
    EXPECT_EQ( (uint256(0xdeadbeefULL) == uint256(0xdeadbeefULL)), true);
    EXPECT_EQ(!(uint256(0xdeadbeefULL) == uint256(0xfee1baadULL)), true);
}

TEST(External, equals){
    const bool     t   = true;
    const bool     f   = false;
    const uint8  u8  = 0xaaULL;
    const uint16 u16 = 0xaaaaULL;
    const uint32 u32 = 0xaaaaaaaaULL;
    const uint64 u64 = 0xaaaaaaaaaaaaaaaaULL;

    EXPECT_EQ(uint256(t),   uint256(t));
    EXPECT_EQ(uint256(f),   uint256(f));
    EXPECT_EQ(uint256(u8),  uint256(u8));
    EXPECT_EQ(uint256(u16), uint256(u16));
    EXPECT_EQ(uint256(u32), uint256(u32));
    EXPECT_EQ(uint256(u64), uint256(u64));
}
