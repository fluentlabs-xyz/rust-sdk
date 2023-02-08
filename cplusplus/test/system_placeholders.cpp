#include <cstdlib>
#include <cstdio>

#include <wasmsdk/system.h>

WASMSDK_BEGIN_NS

void system_halt(HaltCode haltCode) {
    printf("program has halted with code: %d", haltCode);
    exit(haltCode);
}

//int get_call_value(int) { return 0; }

//int get_call_size() { return 0; }

//void copy_call_value(int, int, void *) {}

int invoke_contract(void *, void *, int, void *, int) { return 0; }

void write_log(void*, int) {}

void save_storage(void*, void*) {}

void load_storage(void*, void*) {}

void set_return(void*, int) {}

void get_sender(void*) {}

void write_event(void*, void*, int) {}

void crypto_keccak256(void*, int, void*) {
}

WASMSDK_END_NS