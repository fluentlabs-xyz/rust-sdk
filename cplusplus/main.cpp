#include <wasmsdk/wasmsdk.h>

using namespace wasmsdk;

struct A {
    uint64 a;
    uint256 b;
};
WASMSDK_ABI_STRUCT(A, a, b)

struct B {
    A a;
};
WASMSDK_ABI_STRUCT(B, a)

#include <iostream>
#include <memory>

void crypto_keccak256(void*, int, void*) {
}

struct HelloWorld {
    string name;
};
WASMSDK_ABI_STRUCT(HelloWorld, name)

WASMSDK_ABI("helloWorld(HelloWorld)", "void")
static string erc20_hello_world(const HelloWorld& helloWorld) {
    return helloWorld.name;
}

int char2int(char input)
{
    if(input >= '0' && input <= '9')
        return input - '0';
    if(input >= 'A' && input <= 'F')
        return input - 'A' + 10;
    if(input >= 'a' && input <= 'f')
        return input - 'a' + 10;
    throw std::invalid_argument("Invalid input string");
}

void hex2bin(const char* src, char* target)
{
    while(*src && src[1])
    {
        *(target++) = char2int(*src)*16 + char2int(src[1]);
        src += 2;
    }
}

extern "C"
int get_call_size() {
    return 4 + 7;
}

extern "C"
void copy_call_value(int, int, void* memory_offset) {
    hex2bin("03000000414141", (char*)memory_offset);
}

int main() {

    // 030000414141

//    invoke_contract_method(erc20_hello_world);

    char buf[1024];
    abi<string>::encode(string{ "Hello, World" }, (uint8*)buf);

    return_value(string{ "Hello, World" });

    B a{ {1, uint256(2) << 63} };
    const auto SIZE = _args_size_calculator_<A>::value;
    uint8 buffer[SIZE];
    abi<B>::encode(a, buffer);
    B b;
    abi<B>::decode(buffer, b);

    std::cout << 0;

    return 0;
}