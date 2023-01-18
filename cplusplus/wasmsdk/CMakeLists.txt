add_library(wasmsdk INTERFACE)
target_sources(wasmsdk INTERFACE
        ${CMAKE_SOURCE_DIR}/wasmsdk/abi.h
        ${CMAKE_SOURCE_DIR}/wasmsdk/address.h
        ${CMAKE_SOURCE_DIR}/wasmsdk/array.h
        ${CMAKE_SOURCE_DIR}/wasmsdk/assert.h
        ${CMAKE_SOURCE_DIR}/wasmsdk/crypto.h
        ${CMAKE_SOURCE_DIR}/wasmsdk/contract.h
        ${CMAKE_SOURCE_DIR}/wasmsdk/define.h
        ${CMAKE_SOURCE_DIR}/wasmsdk/wasmsdk.h
        ${CMAKE_SOURCE_DIR}/wasmsdk/storage.h
        ${CMAKE_SOURCE_DIR}/wasmsdk/math.h
        ${CMAKE_SOURCE_DIR}/wasmsdk/string.h
        ${CMAKE_SOURCE_DIR}/wasmsdk/memory.h
        ${CMAKE_SOURCE_DIR}/wasmsdk/system.h
        ${CMAKE_SOURCE_DIR}/wasmsdk/traits.h
        ${CMAKE_SOURCE_DIR}/wasmsdk/bytes.h
        ${CMAKE_SOURCE_DIR}/wasmsdk/uint256.h
        ${CMAKE_SOURCE_DIR}/wasmsdk/visit.h
)
