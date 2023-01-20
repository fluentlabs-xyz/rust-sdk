use wasm0x_zkwasmsdk::*;

const ADDRESS__FUNCTION_FLAG: i32 = 1 << 0;
const CALLVALUE__FUNCTION_FLAG: i32 = 1 << 1;
const TIMESTAMP__FUNCTION_FLAG: i32 = 1 << 2;
const BALANCE__FUNCTION_FLAG: i32 = 1 << 3;
const CALLER__FUNCTION_FLAG: i32 = 1 << 4;
const ORIGIN__FUNCTION_FLAG: i32 = 1 << 5;

fn test_address() -> i32 {
    let val = evm_address();
    let mut sum = 0;
    for b in val {
        sum += b as i32;
    }
    sum
}

fn test_call_value() -> i32 {
    let val = evm_call_value();
    val.bit_length() as i32
}

fn test_timestamp() -> i32 {
    let val = evm_timestamp();
    return val as i32;
}

fn test_balance(address: &Address) -> i32 {
    let val = evm_balance(address);
    let mut sum = 0;
    for b in val {
        sum += b as i32;
    }
    sum
}

fn test_caller() -> i32 {
    let val = evm_caller();
    let mut sum = 0;
    for b in val {
        sum += b as i32;
    }
    sum
}

fn test_origin() -> i32 {
    let val = evm_origin();
    let mut sum = 0;
    for b in val {
        sum += b as i32;
    }
    sum
}

#[no_mangle]
pub extern "C" fn main(input: i32) -> i32 {
    let mut res = 0;
    if input & ADDRESS__FUNCTION_FLAG != 0 {
        res += test_address();
    }
    if input & CALLVALUE__FUNCTION_FLAG != 0 {
        res += test_call_value();
    }
    if input & TIMESTAMP__FUNCTION_FLAG != 0 {
        res += test_timestamp();
    }
    if input & BALANCE__FUNCTION_FLAG != 0 {
        let address: Address = [1; 20];
        res += test_balance(&address);
    }
    if input & CALLER__FUNCTION_FLAG != 0 {
        res += test_caller();
    }
    if input & ORIGIN__FUNCTION_FLAG != 0 {
        res += test_origin();
    }
    res
}