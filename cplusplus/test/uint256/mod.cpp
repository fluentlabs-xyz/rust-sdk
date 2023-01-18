#include <gtest/gtest.h>

#include <wasmsdk/uint256.h>

using namespace wasmsdk;

TEST(Arithmetic, modulo){
    // has remainder
    const uint256 val    (0xffffffffffffffffULL, 0xffffffffffffffffULL, 0xffffffffffffffffULL, 0xffffffffffffffffULL);
    const uint256 val_mod(0xfedcba9876543210ULL);

    EXPECT_EQ(val % val_mod, uint256(0x63794f9d55c8d29f));

    // no remainder
    const uint256 val_0  (0xfedcba9876543210, 0, 0, 0);
    EXPECT_EQ(val_0 % val_mod, uint256(0));
}

TEST(External, modulo){
    uint256      t    = uint256(true);
    uint256      f    = uint256(false);
    uint256   u8   = uint256(0xaaULL);
    uint256  u16  = uint256(0xaaaaULL);
    uint256  u32  = uint256(0xaaaaaaaaULL);
    uint256  u64  = uint256(0xaaaaaaaaaaaaaaaaULL);

    const uint256 val(0xd03ULL); // prime

    EXPECT_EQ(t    %  val, (uint256)true);
    EXPECT_EQ(f    %  val, (uint256)false);
    EXPECT_EQ(u8   %  val, uint256(0xaaULL));
    EXPECT_EQ(u16  %  val, uint256(0x183ULL));
    EXPECT_EQ(u32  %  val, uint256(0x249ULL));
    EXPECT_EQ(u64  %  val, uint256(0xc7fULL));

    EXPECT_EQ(t    %= val, (uint256)true);
    EXPECT_EQ(f    %= val, (uint256)false);
    EXPECT_EQ(u8   %= val, (uint256)   0xaaULL);
    EXPECT_EQ(u16  %= val, (uint256)  0x183ULL);
    EXPECT_EQ(u32  %= val, (uint256)  0x249ULL);
    EXPECT_EQ(u64  %= val, (uint256)  0xc7fULL);
}