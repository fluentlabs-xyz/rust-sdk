#ifndef _WASMSDK_UINT256_H_
#define _WASMSDK_UINT256_H_

#include <wasmsdk/memory.h>
#include <wasmsdk/system.h>

WASMSDK_BEGIN_NS

class uint256 {
public:
    static const int L = 256;
    static const int P = 4;
public: /* default constructors */
    inline uint256() {
        this->values[0] = 0;
        this->values[1] = 0;
        this->values[2] = 0;
        this->values[3] = 0;
    }
    inline uint256(const uint256 & value) {
        this->values[0] = value.values[0];
        this->values[1] = value.values[1];
        this->values[2] = value.values[2];
        this->values[3] = value.values[3];
    }
    inline uint256(uint256 &&) = default;

public: /* primitive types */
    inline explicit uint256(uint64 value) {
        this->values[0] = value;
        this->values[1] = 0;
        this->values[2] = 0;
        this->values[3] = 0;
    }

public: /* special constructors */
    inline uint256(uint64 a, uint64 b, uint64 c, uint64 d) {
        this->values[0] = a;
        this->values[1] = b;
        this->values[2] = c;
        this->values[3] = d;
    }

    inline uint256(uint64 a, uint64 b) {
        this->values[0] = a;
        this->values[1] = b;
        this->values[2] = 0;
        this->values[3] = 0;
    }

public: /* assignments */
    inline uint256 &operator=(const uint256 &right) = default;

    inline uint256 &operator=(uint256 &&right) noexcept = default;

public: /* binary operators */
    inline uint256 operator+(const uint256 &right) const {
        uint256 result(0, 0, 0, 0);
        for (int i = 0; i < P; i++) {
            bool overflow = false;
            uint64 sum = this->values[i] + right.values[i];
            overflow |= sum < this->values[i];
            sum += result.values[i];
            overflow |= result.values[i] && sum == 0;
            if (overflow && i + 1 < P) {
                result.values[i + 1]++;
            }
            result.values[i] = sum;
        }
        return result;
    }

    inline uint256 operator-(const uint256 &right) const {
        return *this + ~right + uint256(1ULL);
    }

    inline uint256 operator/(const uint256 &right) const {
        uint256 result;
        _divMod(*this, right, &result, nullptr);
        return result;
    }

    inline uint256 operator*(const uint256 &right) const {
        uint64 a[8], b[8], c[8] = {0, 0, 0, 0, 0, 0, 0, 0};
        for (int i = 0; i < 4; ++i) {
            a[2 * i] = values[i] & 0xffffffffu;
            a[2 * i + 1] = values[i] >> 32u;
            b[2 * i] = right.values[i] & 0xffffffffu;
            b[2 * i + 1] = right.values[i] >> 32u;
        }
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; i + j < 8; ++j) {
                uint64 p = a[i] * b[j];
                c[i + j] += p & 0xffffffffu;
                if (i + j < 7) c[i + j + 1] += p >> 32u;
            }
        }
        for (int i = 0; i < 8; ++i) {
            if (i < 7) c[i + 1] += c[i] >> 32u;
            c[i] &= 0xffffffffu;
        }
        return {
            c[0] | (c[1] << 32u),
            c[2] | (c[3] << 32u),
            c[4] | (c[5] << 32u),
            c[6] | (c[7] << 32u)
        };
    }

    inline uint256 operator%(const uint256 &right) const {
        uint256 result;
        _divMod(*this, right, nullptr, &result);
        return result;
    }

    inline uint256 operator&(const uint256 &right) const {
        uint256 result{
            this->values[0] & right.values[0],
            this->values[1] & right.values[1],
            this->values[2] & right.values[2],
            this->values[3] & right.values[3],
        };
        return result;
    }

    inline uint256 operator|(const uint256 &right) const {
        uint256 result{
            this->values[0] | right.values[0],
            this->values[1] | right.values[1],
            this->values[2] | right.values[2],
            this->values[3] | right.values[3],
        };
        return result;
    }

    inline uint256 operator^(const uint256 &right) const {
        uint256 result{
            this->values[0] ^ right.values[0],
            this->values[1] ^ right.values[1],
            this->values[2] ^ right.values[2],
            this->values[3] ^ right.values[3],
        };
        return result;
    }

    inline uint256 operator<<(const uint64 &shift) const {
        if (shift > 64) {
            system_halt(HALT_CODE_INVALID_ARGUMENT); // FIXME: big shift
        }
        uint256 result;
        if (!shift) {
            return *this;
        }
        uint64 carry = 0;
        for (int i = 0; i < P; i++) {
            uint64 r = this->values[i] << shift;
            result.values[i] = r | carry;
            if (i < P - 1) {
                carry = this->values[i] >> (64u - shift);
            }
        }
        return result;
    }

    inline uint256 operator>>(const uint64 &shift) const {
        uint256 result;
        if (!shift) {
            return *this;
        }
        uint64 carry = 0;
        for (int i = 0; i < P; i++) {
            uint64 r = this->values[i] >> shift;
            if (i > 0) {
                result.values[i - 1] |= this->values[i] << (64 - shift);
            }
            result.values[i] = r | carry;
        }
        return result;
    }

public: /* binary assignment operators */
    uint256 &operator+=(const uint256 &right) {
        *this = *this + right;
        return *this;
    }

    uint256 &operator-=(const uint256 &right) {
        *this = *this - right;
        return *this;
    }

    uint256 &operator/=(const uint256 &right) {
        *this = *this / right;
        return *this;
    }

    uint256 &operator*=(const uint256 &right) {
        *this = *this * right;
        return *this;
    }

    uint256 &operator%=(const uint256 &right) {
        *this = *this % right;
        return *this;
    }

    uint256 &operator&=(const uint256 &right) {
        *this = *this & right;
        return *this;
    }

    uint256 &operator|=(const uint256 &right) {
        *this = *this | right;
        return *this;
    }

    uint256 &operator^=(const uint256 &right) {
        *this = *this ^ right;
        return *this;
    }

    uint256 &operator<<=(const uint64 &shift) {
        *this = *this << shift;
        return *this;
    }

    uint256 &operator>>=(const uint64 &shift) {
        *this = *this >> shift;
        return *this;
    }

public: /* increment and decrement operators */
    uint256 &operator++() {
        *this = *this + uint256(1UL);
        return *this;
    }

    const uint256 operator++(int) {
        uint256 result = *this;
        *this += uint256(1UL);
        return result;
    }

    uint256 &operator--() {
        *this = *this - uint256(1UL);
        return *this;
    }

    const uint256 operator--(int) {
        uint256 result = *this;
        *this -= uint256(1UL);
        return result;
    }

public: /* comparision operators */
    bool operator>(const uint256 &right) const {
        for (int i = P - 1; i >= 0; i--) {
            if (this->values[i] == right.values[i]) {
                continue;
            }
            return this->values[i] > right.values[i];
        }
        return false;
    }

    bool operator>=(const uint256 &right) const {
        for (int i = P - 1; i >= 0; i--) {
            if (this->values[i] == right.values[i]) {
                continue;
            }
            return this->values[i] >= right.values[i];
        }
        return true;
    }

    bool operator<(const uint256 &right) const {
        for (int i = P - 1; i >= 0; i--) {
            if (this->values[i] == right.values[i]) {
                continue;
            }
            return this->values[i] < right.values[i];
        }
        return false;
    }

    bool operator<=(const uint256 &right) const {
        for (int i = P - 1; i >= 0; i--) {
            if (this->values[i] == right.values[i]) {
                continue;
            }
            return this->values[i] <= right.values[i];
        }
        return true;
    }

    bool operator==(const uint256 &right) const {
        for (int i = 0; i < P; i++) {
            if (this->values[i] != right.values[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const uint256 &right) const {
        return !(*this == right);
    }

public: /* unary operators */
    uint256 operator+() const {
        return *this;
    }

    uint256 operator-() const {
        return ~*this + uint256(1UL);
    }

    bool operator!() const {
        uint64 a = 0;
        for (unsigned long value : this->values) {
            a |= value;
        }
        return !(bool) a;
    }

    explicit operator bool() const {
        return values[0] || values[1] || values[2] || values[3];
    }

    uint256 operator~() const {
        uint256 result;
        for (int i = 0; i < P; i++) {
            result.values[i] = ~this->values[i];
        }
        return result;
    }

public: /* random access operator */
    inline const uint64& operator[](int offset) const {
        if (offset < 0 || offset > P - 1) {
            system_halt(HALT_CODE_OUT_OF_RANGE);
        }
        return this->values[offset];
    }
    inline uint64& operator[](int offset) {
        if (offset < 0 || offset > P - 1) {
            system_halt(HALT_CODE_OUT_OF_RANGE);
        }
        return this->values[offset];
    }

public: /* methods */

    int bitLength() const {
        for (int i = P - 1; i >= 0; i--) {
            if (!this->values[i]) {
                continue;
            }
            return 64 * i + _highestBit(this->values[i]) + 1;
        }
        return 0;
    }

private:
    static int _highestBit(uint64 n) {
        int res = 0;
        if (n >> 32u) res += 32, n >>= 32u;
        if (n >> 16u) res += 16, n >>= 16u;
        if (n >> 8u) res += 8, n >>= 8u;
        if (n >> 4u) res += 4, n >>= 4;
        if (n >> 2u) res += 2, n >>= 2u;
        if (n >> 1u) res += 1, n >>= 1u;
        return res;
    }

    int testBit(int x) const {
        return (int) ((values[x / 64] >> uint32(x % 64)) & 1ULL);
    }

    static void _divMod(const uint256 &left, const uint256 &right, uint256 *div, uint256 *mod) {
        /* check for zero division */
        if (right == uint256(0)) {
            system_halt(HALT_CODE_ZERO_DIVISION);
        }
        /* check for one division */
        if (right == uint256(1)) {
            if (div != nullptr) {
                *div = left;
            }
            if (mod != nullptr) {
                *mod = uint256(0);
            }
            return;
        }
        /* check a & b equability */
        if (left == right) {
            if (div != nullptr) {
                *div = uint256(1);
            }
            if (mod != nullptr) {
                *mod = uint256(0);
            }
            return;
        }
        /* check a < b or a is zero */
        if (left == uint256(0) || left < right) {
            if (div != nullptr) {
                *div = uint256(0);
            }
            if (mod != nullptr) {
                *mod = left;
            }
            return;
        }
        uint256 first(0), second(0);
        for (int x = left.bitLength() - 1; x >= 0; x--) {
            first <<= 1;
            second <<= 1;
            if (left.testBit(x)) {
                second++;
            }
            if (!(second >= right)) {
                continue;
            }
            second -= right;
            first++;
        }
        if (div != nullptr) {
            *div = first;
        }
        if (mod != nullptr) {
            *mod = second;
        }
    }

public:
    uint64 values[P]{
        0, 0, 0, 0
    };
};

WASMSDK_END_NS

#endif // ~_WASMSDK_UINT256