cmake_minimum_required(VERSION 3.10)
project(wasmsdk)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Werror -Wno-unused-function -fno-rtti")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -fsanitize=address -fsanitize=undefined")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

include_directories(${CMAKE_SOURCE_DIR})

add_subdirectory(wasmsdk)

add_executable(wasmsdklib main.cpp test/system_placeholders.cpp)
target_link_libraries(wasmsdklib wasmsdk)

add_subdirectory(test)