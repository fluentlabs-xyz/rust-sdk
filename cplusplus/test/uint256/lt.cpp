#include <gtest/gtest.h>

#include <wasmsdk/uint256.h>

using namespace wasmsdk;

TEST(Comparison, less_than){
    const uint256 big  (0xffffffffffffffffULL, 0xffffffffffffffffULL);
    const uint256 small(0x0000000000000000ULL, 0x0000000000000000ULL);

    EXPECT_EQ(small < small, false);
    EXPECT_EQ(small < big,    true);

    EXPECT_EQ(big < small,   false);
    EXPECT_EQ(big < big,     false);
}

#define unsigned_compare_lt(Z)                                            \
do                                                                        \
{                                                                         \
    static_assert(std::is_unsigned <Z>::value, "Type must be signed");    \
                                                                          \
    const Z small = std::numeric_limits <Z>::min();                       \
    const Z big   = std::numeric_limits <Z>::max();                       \
                                                                          \
    const uint256 int_small(small);                                     \
    const uint256 int_big(big);                                         \
                                                                          \
    EXPECT_EQ(uint256(small) < int_small, false);                       \
    EXPECT_EQ(uint256(small) < int_big,   true);                        \
                                                                          \
    EXPECT_EQ(uint256(big) < int_small,   false);                       \
    EXPECT_EQ(uint256(big) < int_big,     false);                       \
}                                                                         \
while (0)

#define signed_compare_lt(Z)                                              \
do                                                                        \
{                                                                         \
    static_assert(std::is_signed <Z>::value, "Type must be signed");      \
                                                                          \
    const Z small =  1;                                                   \
    const Z big = std::numeric_limits <Z>::max();                         \
                                                                          \
    const uint256 int_small(small);                                     \
    const uint256 int_big(big);                                         \
                                                                          \
    EXPECT_EQ(uint256(small) < int_small, false);                       \
    EXPECT_EQ(uint256(small) < int_big,   true);                        \
                                                                          \
    EXPECT_EQ(uint256(big) < int_small,   false);                       \
    EXPECT_EQ(uint256(big) < int_big,     false);                       \
}                                                                         \
while (0)

TEST(External, less_than){
    unsigned_compare_lt(bool);
    unsigned_compare_lt(uint8);
    unsigned_compare_lt(uint16);
    unsigned_compare_lt(uint32);
    unsigned_compare_lt(uint64);
    signed_compare_lt(int8);
    signed_compare_lt(int16);
    signed_compare_lt(int32);
    signed_compare_lt(int64);
}
