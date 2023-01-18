#ifndef _WASMSDK_DEFINE_H_
#define _WASMSDK_DEFINE_H_

#ifdef __cplusplus
#  define WASMSDK_EXPORT extern "C"
#else
#  define WASMSDK_EXPORT extern
#endif

#define WASMSDK_NORETURN [[noreturn]]

#define WASMSDK_BEGIN_NS \
    namespace wasmsdk {
#define WASMSDK_END_NS \
    }

WASMSDK_BEGIN_NS

#define WASMSDK_ENTRY_POINT \
    extern "C" void start()

#define WASMSDK_UNUSED(param) \
    (void)param;

#define WASMSDK_ABI(signature, returnType)

using boolean = unsigned char;
using byte = unsigned char;
using uint8 = unsigned char;
using int8 = char;
using uint16 = unsigned short;
using int16 = short;
using uint32 = unsigned int;
using int32 = int;
using uint64 = unsigned long long int;
using int64 = long long;

WASMSDK_END_NS

#endif // ~_WASMSDK_DEFINE_H_