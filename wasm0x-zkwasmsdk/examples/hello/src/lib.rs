use wasm0x_zkwasmsdk::*;

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
    let mut sum = 0;
    for b in val {
        sum += b as i32;
    }
    sum
}

fn test_timestamp() -> i32 {
    let val = evm_timestamp();
    return val as i32;
}

#[no_mangle]
pub extern "C" fn main(input: i32) -> i32 {
    let mut res = 0;
    if input & 1 != 0 {
        res += test_address();
    }
    if input & 2 != 0 {
        res += test_call_value();
    }
    if input & 4 != 0 {
        res += test_timestamp();
    }
    res
}