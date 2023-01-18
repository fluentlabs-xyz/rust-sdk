#include <gtest/gtest.h>

#include <wasmsdk/uint256.h>

using namespace wasmsdk;

TEST(BitShift, left){
    // operator<<
    uint256 val(0x1);
    uint64 exp_val = 1;
    for(uint8 i = 0; i < 64; i++){
        EXPECT_EQ(val << i, uint256(exp_val << i));
    }

    uint256 zero(0);
    for(uint8 i = 0; i < 64; i++){
        EXPECT_EQ(zero << i, uint256(0));
    }

    // operator<<=
    for(uint8 i = 0; i < 63; i++){ // 1 is already a bit
        EXPECT_EQ(val  <<=  1, uint256(exp_val <<= 1));
    }

    for(uint8 i = 0; i < 63; i++){
        EXPECT_EQ(zero <<=  1, uint256(0));
    }
}

TEST(External, shift_left){
    uint256      t    = uint256(true);
    uint256      f    = uint256(false);
    uint256   u8   = uint256(0xffULL);
    uint256  u16  = uint256(0xffffULL);
    uint256  u32  = uint256(0xffffffffULL);
    uint256  u64  = uint256(0xffffffffffffffffULL);

    EXPECT_EQ(t    << 0, t);
    EXPECT_EQ(f    << 0, f);
    EXPECT_EQ(u8   << 0, u8);
    EXPECT_EQ(u16  << 0, u16);
    EXPECT_EQ(u32  << 0, u32);
    EXPECT_EQ(u64  << 0, u64);

    EXPECT_EQ(t    <<= 0, t);
    EXPECT_EQ(f    <<= 0, f);
    EXPECT_EQ(u8   <<= 0, u8);
    EXPECT_EQ(u16  <<= 0, u16);
    EXPECT_EQ(u32  <<= 0, u32);
    EXPECT_EQ(u64  <<= 0, u64);

    EXPECT_EQ(t    << 1, uint256(t)    << 1);
    EXPECT_EQ(f    << 1, uint256(f)    << 1);
    EXPECT_EQ(u8   << 1, uint256(u8)   << 1);
    EXPECT_EQ(u16  << 1, uint256(u16)  << 1);
    EXPECT_EQ(u32  << 1, uint256(u32)  << 1);
    EXPECT_EQ(u64  << 1, uint256(u64)  << 1);

    EXPECT_EQ(t    <<= 1, (uint256) 2);
    EXPECT_EQ(f    <<= 1, (uint256) 0);
    EXPECT_EQ(u8   <<= 1, (uint256) 0x1feULL);
    EXPECT_EQ(u16  <<= 1, (uint256) 0x1fffeULL);
    EXPECT_EQ(u32  <<= 1, (uint256) 0x1fffffffeULL);
    EXPECT_EQ(u64  <<= 1, uint256(0xfffffffffffffffeULL, 0x1UL));

    EXPECT_EQ(u8   << (7),   uint256(0xff00ULL));
    EXPECT_EQ(u16  << (15),  uint256(0xffff0000ULL));
    EXPECT_EQ(u32  << (31),  uint256(0xffffffff00000000ULL));
    EXPECT_EQ(u64  << (63),  uint256(0x0000000000000000ULL, 0xffffffffffffffff, 0x0000000000000000ULL, 0x0000000000000000ULL));

    EXPECT_EQ(u8   <<= (7),   uint256(0xff00ULL));
    EXPECT_EQ(u16  <<= (15),  uint256(0xffff0000));
    EXPECT_EQ(u32  <<= (31),  uint256(0xffffffff00000000));
    EXPECT_EQ(u64  <<= (63),  uint256(0x0000000000000000, 0xffffffffffffffff));
}
