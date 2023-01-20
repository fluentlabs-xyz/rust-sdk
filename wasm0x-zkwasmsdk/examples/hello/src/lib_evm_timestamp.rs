use wasm0x_zkwasmsdk::evm_timestamp;
use wasm0x_zkwasmsdk::Uint64;

#[no_mangle]
pub extern "C" fn main(_input: i32) -> Uint64 {
    let ts = evm_timestamp();
    ts
}