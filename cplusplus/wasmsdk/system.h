#ifndef _WASMSDK_SYSTEM_H_
#define _WASMSDK_SYSTEM_H_

#include <wasmsdk/define.h>

WASMSDK_BEGIN_NS

typedef enum {
    HALT_CODE_INVALID_ARGUMENT = 0,
    HALT_CODE_ZERO_DIVISION = 1,
    HALT_CODE_BUFFER_OVERFLOW = 2,
    HALT_CODE_OUT_OF_RANGE = 3,
    HALT_CODE_INSUFFICIENT_BALANCE = 4,
    HALT_CODE_UNKNOWN_METHOD = 5,
    HALT_CODE_INVALID_ABI_ENCODED = 6,
    HALT_CODE_ASSERTION_FAILED = 7,
    HALT_CODE_ARRAY_OVERFLOW = 8,
} HaltCode;

WASMSDK_EXPORT {
    void system_halt(HaltCode haltCode);
    int get_call_value(int call_data_offset);
    int get_call_size();
    void get_transferred_funds(void* data_offset);
    void get_block_number(void* data_offset);
    void get_transaction_hash(void* data_offset);
    void get_block_hash(void* data_offset);
    void copy_call_value(int from_offset, int to_offset, void* memory_offset);
    int invoke_contract(void* address_offset, void* input_offset, int input_length, void* value_offset, int return_value_offset);
    void write_log(void* data_offset, int data_length);
    void save_storage(void* key_offset, void* value_offset);
    void load_storage(void* key_offset, void* value_offset);
    void set_return(void* data_offset, int data_length);
    void get_sender(void* data_offset);
    void write_event(void* signature_offset, void* value_offset, int value_length);
}

WASMSDK_END_NS

#endif // ~_WASMSDK_SYSTEM_H_