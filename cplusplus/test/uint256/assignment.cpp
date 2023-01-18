#include <gtest/gtest.h>

#include <wasmsdk/uint256.h>

using namespace wasmsdk;

TEST(Assignment, all){
    const uint256 t_1   = uint256(true);
    const uint256 f_1   = uint256(false);
    const uint256 u8_1  = uint256(0x01);
    const uint256 u16_1 = uint256(0x0123);
    const uint256 u32_1 = uint256(0x01234567);
    const uint256 u64_1 = uint256(0x0123456789abcdef);

    uint256 t_2   = uint256(0);
    uint256 f_2   = uint256(0);
    uint256 u8_2  = uint256(0);
    uint256 u16_2 = uint256(0);
    uint256 u32_2 = uint256(0);
    uint256 u64_2 = uint256(0);

    t_2 = t_1;
    f_2 = f_1;
    u8_2 = u8_1;
    u16_2 = u16_1;
    u32_2 = u32_1;
    u64_2 = u64_1;

    EXPECT_EQ(t_1, t_2);
    EXPECT_EQ(f_1, f_2);
    EXPECT_EQ(u8_1, u8_2);
    EXPECT_EQ(u16_1, u16_2);
    EXPECT_EQ(u32_1, u32_2);
    EXPECT_EQ(u64_1, u64_2);
}