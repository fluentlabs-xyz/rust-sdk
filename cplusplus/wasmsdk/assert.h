#ifndef _WASMSDK_ASSERT_H_
#define _WASMSDK_ASSERT_H_

#include <wasmsdk/system.h>
#include "define.h"

WASMSDK_BEGIN_NS

static inline void assert(bool value, HaltCode haltCode = HALT_CODE_ASSERTION_FAILED) {
    if (!value) {
        system_halt(haltCode);
    }
}

WASMSDK_END_NS

#endif // ~_WASMSDK_ASSERT_H_