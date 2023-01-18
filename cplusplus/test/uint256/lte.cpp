#include <gtest/gtest.h>

#include <wasmsdk/uint256.h>

using namespace wasmsdk;

TEST(Comparison, less_than_or_equals){
    const uint256 big  (0xffffffffffffffffULL, 0xffffffffffffffffULL);
    const uint256 small(0x0000000000000000ULL, 0x0000000000000000ULL);

    EXPECT_EQ(small <= small,  true);
    EXPECT_EQ(small <= big,    true);

    EXPECT_EQ(big <= small,   false);
    EXPECT_EQ(big <= big,      true);
}

#define unsigned_compare_lte(Z)                                           \
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
    EXPECT_EQ(uint256(small) <= int_small, true);                       \
    EXPECT_EQ(uint256(small) <= int_big,   true);                       \
                                                                          \
    EXPECT_EQ(uint256(big) <= int_small,   false);                      \
    EXPECT_EQ(uint256(big) <= int_big,     true);                       \
}                                                                         \
while (0)

#define signed_compare_lte(Z)                                             \
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
    EXPECT_EQ(uint256(small) <= int_small, true);                       \
    EXPECT_EQ(uint256(small) <= int_big,   true);                       \
                                                                          \
    EXPECT_EQ(uint256(big) <= int_small,   false);                      \
    EXPECT_EQ(uint256(big) <= int_big,     true);                       \
}                                                                         \
while (0)

TEST(External, less_than_or_equals){
    unsigned_compare_lte(bool);
    unsigned_compare_lte(uint8);
    unsigned_compare_lte(uint16);
    unsigned_compare_lte(uint32);
    unsigned_compare_lte(uint64);
    signed_compare_lte(int8);
    signed_compare_lte(int16);
    signed_compare_lte(int32);
    signed_compare_lte(int64);
}
