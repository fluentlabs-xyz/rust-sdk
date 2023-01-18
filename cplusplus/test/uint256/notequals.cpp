#include <gtest/gtest.h>

#include <wasmsdk/uint256.h>

using namespace wasmsdk;

TEST(Comparison, not_equals){
    EXPECT_EQ(!(uint256(0xdeadbeefULL) != uint256(0xdeadbeefULL)), true);
    EXPECT_EQ( (uint256(0xdeadbeefULL) != uint256(0xfee1baadULL)), true);
}

TEST(External, not_equals){
    const bool     t   = true;
    const bool     f   = false;
    const uint8  u8  = 0xaaULL;
    const uint16 u16 = 0xaaaaULL;
    const uint32 u32 = 0xaaaaaaaaULL;
    const uint64 u64 = 0xaaaaaaaaaaaaaaaaULL;

    EXPECT_EQ((uint256(t)   != uint256(f)),   true);
    EXPECT_EQ((uint256(f)   != uint256(t)),   true);
    EXPECT_EQ((uint256(u8)  != uint256(u64)), true);
    EXPECT_EQ((uint256(u16) != uint256(u32)), true);
    EXPECT_EQ((uint256(u32) != uint256(u16)), true);
    EXPECT_EQ((uint256(u64) != uint256(u8)),  true);

    EXPECT_EQ((uint256(t)   != uint256(t)),   false);
    EXPECT_EQ((uint256(f)   != uint256(f)),   false);
    EXPECT_EQ((uint256(u8)  != uint256(u8)),  false);
    EXPECT_EQ((uint256(u16) != uint256(u16)), false);
    EXPECT_EQ((uint256(u32) != uint256(u32)), false);
    EXPECT_EQ((uint256(u64) != uint256(u64)), false);
}