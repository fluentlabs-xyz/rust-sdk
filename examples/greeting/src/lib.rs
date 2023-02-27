#![no_std]

use wasm0x_zkwasmsdk::*;

#[no_mangle]
pub extern "C" fn main() {
    let hello_world = "Hello, World";
    evm_return(hello_world.as_ptr(), hello_world.len() as u32);
}