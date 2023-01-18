#include <gtest/gtest.h>

#include <wasmsdk/uint256.h>

using namespace wasmsdk;

TEST(Arithmetic, divide){
    const uint256 big    (0xfedbca9876543210ULL);
    const uint256 small  (0xffffULL);
    const uint256 res_val(0xfedcc9753fc9ULL);

    EXPECT_EQ(small / small, uint256(1));
    EXPECT_EQ(small / big,   uint256(0));

    EXPECT_EQ(big   / big,   uint256(1));
}

TEST(External, divide){
    uint256    t  = uint256(true);
    uint256    f  = uint256(false);
    uint256   u8  = uint256(0xaaULL);
    uint256  u16  = uint256(0xaaaaULL);
    uint256  u32  = uint256(0xaaaaaaaaULL);
    uint256  u64  = uint256(0xaaaaaaaaaaaaaaaaULL);

    const uint256 val(0x7bULL);

    EXPECT_EQ(t    /  val, uint256(0));
    EXPECT_EQ(f    /  val, uint256(0));
    EXPECT_EQ(u8   /  val, uint256(0x1ULL));
    EXPECT_EQ(u16  /  val, uint256(0x163ULL));
    EXPECT_EQ(u32  /  val, uint256(0x163356bULL));
    EXPECT_EQ(u64  /  val, uint256(0x163356b88ac0de0ULL));

    EXPECT_EQ(t    /= val, uint256(0));
    EXPECT_EQ(f    /= val, uint256(0));
    EXPECT_EQ(u8   /= val, (uint256)  0x1ULL);
    EXPECT_EQ(u16  /= val, (uint256) 0x163ULL);
    EXPECT_EQ(u32  /= val, (uint256) 0x163356bULL);
    EXPECT_EQ(u64  /= val, (uint256) 0x163356b88ac0de0ULL);
}
