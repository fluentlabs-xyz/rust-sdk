use wasm0x_zkwasmsdk::evm_call_value;
use wasm0x_zkwasmsdk::Uint256;

#[no_mangle]
pub extern "C" fn main(_input: i32) -> Uint256 {
    let cv = evm_call_value();
    cv
}