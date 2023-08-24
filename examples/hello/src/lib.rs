#![no_std]

extern crate alloc;

use alloc::alloc::alloc;
use core::alloc::{GlobalAlloc, Layout};
use wasm0x_zkwasmsdk::*;
use wasm0x_zkwasmsdk::alloc::ALLOC;

#[no_mangle]
pub extern "C" fn main(input: i32) -> i32 {
    let current_address = evm_address();
    unsafe {
        let mut layout = Layout::new::<u32>();
        let ptr = alloc(layout);
        *(ptr as *mut u32) = input as u32;
    }
    0
}