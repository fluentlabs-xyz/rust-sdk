use wasm0x_zkwasmsdk::evm_address;

#[no_mangle]
pub extern "C" fn main(_input: i32) -> i32 {
    let addr = evm_address();
    let mut sum = 0;
    for b in addr {
        sum += b as i32;
    }
    sum
}