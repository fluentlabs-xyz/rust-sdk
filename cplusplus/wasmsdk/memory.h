#ifndef _WASMSDK_MEMORY_H_
#define _WASMSDK_MEMORY_H_

#include <wasmsdk/define.h>

#ifndef __wasm__
#  define __builtin_wasm_memory_size(a)
#  define __builtin_wasm_memory_grow(a, b)
#endif

#define WASMSDK_MEMORY_SIZE() __builtin_wasm_memory_size(0)
#define WASMSDK_MEMORY_GROW(SIZE) __builtin_wasm_memory_grow(0, SIZE)

WASMSDK_BEGIN_NS

class memory {
public:
    static const int32 PAGE_SIZE = 65536;
public:
    static void *copy(void *dest, const void *src, int n) {
        return copy(dest, 0, src, 0, n);
    }
    static void *copy(void *dest, int dest_offset, const void *src, int src_offset, int n) {
        auto * _dest = static_cast<char*>(dest);
        const auto * _src = static_cast<const char*>(src);
        for (int i = 0; i < n; i++) {
            _dest[dest_offset + i] = _src[src_offset + i];
        }
        return dest;
    }
public:
    inline static memory& global() {
        static memory _instance;
        return _instance;
    }
private:
    memory() {
        this->_offset = 0;
        this->_page = WASMSDK_MEMORY_SIZE() + 1;
    }
public:
    int32 allocate(int32 length) {
        int32 grow_factor = (length - PAGE_SIZE + this->_offset) / PAGE_SIZE;
        if (grow_factor > 0) {
            WASMSDK_MEMORY_GROW(grow_factor);
            this->_page += grow_factor;
        }
        int32 current_offset = this->_offset;
        this->_offset = (this->_offset + length) % PAGE_SIZE;
        return current_offset;
    }
    void free(uint64 offset) {
        (void)offset;
    }
private:
    int32 _offset;
    int32 _page;
};

WASMSDK_END_NS

#ifdef __wasm__
void* operator new (unsigned long length) {
    return reinterpret_cast<void*>(wasmsdk::memory::global().allocate(static_cast<wasmsdk::int32>(length)));
}
void* operator new[] (unsigned long length) {
    return reinterpret_cast<void*>(wasmsdk::memory::global().allocate(static_cast<wasmsdk::int32>(length)));
}
void operator delete (void* address) {
    wasmsdk::memory::global().free(reinterpret_cast<wasmsdk::uint64>(address));
}
void operator delete[] (void* address) {
    wasmsdk::memory::global().free(reinterpret_cast<wasmsdk::uint64>(address));
}
#endif

#endif // ~_WASMSDK_MEMORY_H_