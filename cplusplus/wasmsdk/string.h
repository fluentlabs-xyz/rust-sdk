#ifndef _WASMSDK_STRING_H_
#define _WASMSDK_STRING_H_

#include <wasmsdk/array.h>

WASMSDK_BEGIN_NS

class string : public array<int8> {
public:
    static uint32 strlen(const char *src) {
        uint32 result = 0;
        for (; *src; src++) {
            ++result;
        }
        return result;
    }
public:
    string() : string("", 0) {
    }
    string(const int8* buffer) : string(buffer, strlen(buffer)) {
    }
    string(const int8* buffer, uint32 length) {
        copy(buffer, length);
    }
    string(const string &right) : array(right) {
    }
    string(string&&) = default;
    ~string() {
    }
public:
    friend string operator+(const string& left, const string& right) {
        string result{ left };
        result.resize(left.length() + right.length());
        memory::copy(result.buffer(), left.length(), right.buffer(), 0, right.length());
        return result;
    }
    friend string& operator+=(string& left, const string& right) {
        left.resize(left.length() + right.length());
        memory::copy(left.buffer(), left.length(), right.buffer(), 0, right.length());
        return left;
    }
};

WASMSDK_END_NS

#endif // ~_WASMSDK_STRING_H_