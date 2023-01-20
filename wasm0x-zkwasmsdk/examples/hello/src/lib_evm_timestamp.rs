use wasm0x_zkwasmsdk::evm_timestamp;
use wasm0x_zkwasmsdk::Uint64;

#[no_mangle]
pub extern "C" fn main(_input: i32) -> i32 {
    let ts = evm_timestamp();
    let mut sum = 0;
    for b in ts {
        sum += b as i32;
    }
    sum
}