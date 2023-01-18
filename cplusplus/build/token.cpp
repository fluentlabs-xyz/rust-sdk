#include <wasmsdk/wasmsdk.h>

using namespace wasmsdk;

WASMSDK_ABI("totalSupply()", "uint256")
static uint256 total_supply() {
    return load_from_storage<uint256>("totalSupply"_m);
}

WASMSDK_ABI("balanceOf(address)", "uint256")
static uint256 balance_of(address owner) {
    return load_from_storage<address, uint256>("balanceOf"_m, owner);
}

WASMSDK_ABI("transfer(address,uint256)", "bool")
static bool transfer(address to, uint256 tokens) {
    /* get sender from execution frame */
    address sender = get_sender();
    /* load sender balance from storage, sub tokens and store to storage */
    uint256 sender_balance = load_from_storage<address, uint256>("balanceOf"_m, sender);
    assert(sender_balance >= tokens, HALT_CODE_INSUFFICIENT_BALANCE);
    sender_balance -= tokens;
    save_to_storage<address, uint256>("balanceOf"_m, sender, sender_balance);
    /* load to balance from storage, add tokens and store to storage */
    uint256 to_balance = load_from_storage<address, uint256>("balanceOf"_m, to);
    to_balance += tokens;
    save_to_storage<address, uint256>("balanceOf"_m, to, to_balance);
    /* ERC-20 token should return true on success */
    return true;
}

WASMSDK_ABI("transferFrom(address,address,uint256)", "void")
static void transfer_from(address from, address to, uint256 value) {
    WASMSDK_UNUSED(from);
    WASMSDK_UNUSED(to);
    WASMSDK_UNUSED(value);
    system_halt(HALT_CODE_UNKNOWN_METHOD);
}

WASMSDK_ABI("approve()", "void")
static void approve() {
    system_halt(HALT_CODE_UNKNOWN_METHOD);
}

WASMSDK_ABI("allowance()", "void")
static void allowance() {
    system_halt(HALT_CODE_UNKNOWN_METHOD);
}

WASMSDK_ABI("mint(address,uint256)", "void")
static void mint(address to, uint256 value) {
    /* change to balance */
    uint256 to_balance = load_from_storage<address, uint256>("balanceOf"_m, to);
    to_balance += value;
    save_to_storage<address, uint256>("balanceOf"_m, to, to_balance);
    /* change total supply */
    uint256 total_supply = load_from_storage<uint256>("totalSupply"_m);
    total_supply += value;
    save_to_storage<uint256>("totalSupply"_m, total_supply);
}

WASMSDK_ABI("name()", "string")
static string name() {
    return "LTK";
}

WASMSDK_ABI("constructor(uint256)", "void")
static void constructor(uint256 amount) {
    save_to_storage<address, uint256>("balanceOf"_m, get_sender(), amount);
    save_to_storage<uint160>("owner"_m, get_sender());
    uint256 signature(0);
    uint32 hello = 0xbadcab1e;
    write_event(&signature, &hello, 4);
}

struct HelloWorld {
    string name;
};
WASMSDK_ABI_STRUCT(HelloWorld, name)

WASMSDK_ABI("helloWorld(HelloWorld)", "void")
static string hello_world(HelloWorld helloWorld) {
    return helloWorld.name;
}

static void fallback() {
    system_halt(HALT_CODE_UNKNOWN_METHOD);
}