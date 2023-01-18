#ifndef _WASMSDK_BYTES_H_
#define _WASMSDK_BYTES_H_

#include <wasmsdk/array.h>

WASMSDK_BEGIN_NS

/**
 * Bytes is dynamic array with uint8 (byte) elements
 */
using bytes = array<uint8>;

/**
 * Bytes* is static arrays with uint8 (byte) elements
 * with fixed size
 */
using bytes1 = fixed_array<uint8, 1>;
using bytes2 = fixed_array<uint8, 2>;
using bytes3 = fixed_array<uint8, 3>;
using bytes4 = fixed_array<uint8, 4>;
using bytes5 = fixed_array<uint8, 5>;
using bytes6 = fixed_array<uint8, 6>;
using bytes7 = fixed_array<uint8, 7>;
using bytes8 = fixed_array<uint8, 8>;
using bytes9 = fixed_array<uint8, 9>;
using bytes10 = fixed_array<uint8, 10>;
using bytes11 = fixed_array<uint8, 11>;
using bytes12 = fixed_array<uint8, 12>;
using bytes13 = fixed_array<uint8, 13>;
using bytes14 = fixed_array<uint8, 14>;
using bytes15 = fixed_array<uint8, 15>;
using bytes16 = fixed_array<uint8, 16>;
using bytes17 = fixed_array<uint8, 17>;
using bytes18 = fixed_array<uint8, 18>;
using bytes19 = fixed_array<uint8, 19>;
using bytes20 = fixed_array<uint8, 20>;
using bytes21 = fixed_array<uint8, 21>;
using bytes22 = fixed_array<uint8, 22>;
using bytes23 = fixed_array<uint8, 23>;
using bytes24 = fixed_array<uint8, 24>;
using bytes25 = fixed_array<uint8, 25>;
using bytes26 = fixed_array<uint8, 26>;
using bytes27 = fixed_array<uint8, 27>;
using bytes28 = fixed_array<uint8, 28>;
using bytes29 = fixed_array<uint8, 29>;
using bytes30 = fixed_array<uint8, 30>;
using bytes31 = fixed_array<uint8, 31>;
using bytes32 = fixed_array<uint8, 32>;

WASMSDK_END_NS

#endif // ~_WASMSDK_BYTES_H_