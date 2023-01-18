#ifndef _WASMSDK_ARRAY_H_
#define _WASMSDK_ARRAY_H_

#include <wasmsdk/define.h>
#include <wasmsdk/memory.h>
#include <wasmsdk/system.h>

WASMSDK_BEGIN_NS

/**
 * This is dynamic array
 *
 * @tparam T type of array element
 */
template <typename T>
class array {
    static constexpr uint32 INIT_CAPACITY = 10;
public:
    array() : _buffer(new T[INIT_CAPACITY]), _length(0), _capacity(INIT_CAPACITY) {
    }
    array(const array &) = default;
    array(array &&) = default;

public:
    explicit array(uint32 length) : _length(length) {
        if (this->_length > INIT_CAPACITY) {
            this->_buffer = new T[length];
            this->_capacity = this->_length;
        } else {
            this->_capacity = INIT_CAPACITY;
            this->_buffer = new T[INIT_CAPACITY];
        }
    }

public:
    void resize(uint32 length) {
        auto* buffer = new T[length];
        memory::copy(buffer, this->_buffer, length < this->_length ? length : this->_length);
        delete[] this->_buffer;
        this->_buffer = buffer;
        this->_length = this->_capacity = length;
    }
    void copy(const T* data, uint32 length) {
        delete[] this->_buffer;
        this->_buffer = new T[length];
        memory::copy(this->_buffer, data, length);
        this->_length = this->_capacity = length;
    }

public:
    inline const T& operator[](int i) const {
        if (i < 0 || static_cast<uint32>(i) >= this->_length) {
            system_halt(HALT_CODE_BUFFER_OVERFLOW);
        }
        return this->_buffer[i];
    }

    inline T& operator[](int i) {
        if (i < 0 || static_cast<uint32>(i) >= this->_length) {
            system_halt(HALT_CODE_BUFFER_OVERFLOW);
        }
        return this->_buffer[i];
    }
public:
    inline const T *buffer() const {
        return this->_buffer;
    }
    inline T *buffer() {
        return this->_buffer;
    }
    inline uint32 length() const {
        return this->_length;
    }
    inline void push_back(const T& a) {
        if (this->_length == this->_capacity) {
            this->_capacity <<= 1;
            resize(this->_capacity);
        }
        this->_buffer[this->_length++] = a;
    }

private:
    T *_buffer;
    uint32 _length;
    uint32 _capacity;
};

/**
 * This is static array
 *
 * @tparam T type of array element
 * @tparam S size of array
 */
template <typename T, uint32 S>
class fixed_array {
public:
    static const uint32 SIZE = S;
public:
    fixed_array() = default;
    fixed_array(const fixed_array<T, S> &) = default;
    fixed_array(fixed_array<T, S> &&) noexcept = default;

public:
    explicit fixed_array(T* buffer, uint32 length = S) {
        if (length > S) {
            system_halt(HALT_CODE_BUFFER_OVERFLOW);
        }
        memory::copy(this->_buffer, buffer, length);
    }

public:
    void copy(const T* data, int32 length = S) {
        if (length > S) {
            system_halt(HALT_CODE_BUFFER_OVERFLOW);
        }
        memory::copy(this->_buffer, data, length);
    }

public:
    inline const T& operator[](int i) const {
        if (i < 0 || static_cast<uint32>(i) >= S) {
            system_halt(HALT_CODE_BUFFER_OVERFLOW);
        }
        return this->_buffer[i];
    }

    inline T& operator[](int i) {
        if (i < 0 || static_cast<uint32>(i) >= S) {
            system_halt(HALT_CODE_BUFFER_OVERFLOW);
        }
        return this->_buffer[i];
    }
public:
    inline const T *buffer() const {
        return this->_buffer;
    }

    inline T *buffer() {
        return this->_buffer;
    }

    inline int32 length() const {
        return S;
    }

private:
    T _buffer[S]{0};
};

WASMSDK_END_NS

#endif // ~_WASMSDK_ARRAY_H_