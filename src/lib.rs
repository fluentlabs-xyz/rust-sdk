extern crate core;

use crate::binding::evm_address;

pub mod binding;
pub mod types;

#[derive(Debug)]
struct A {
    value: i32,
}

/// Allocate memory into the module's linear memory
/// and return the offset to the start of the block.
#[no_mangle]
pub fn alloc(len: usize) -> *mut u8 {
    // create a new mutable buffer with capacity `len`
    let mut buf = Vec::with_capacity(len);
    // take a mutable pointer to the buffer
    let ptr = buf.as_mut_ptr();
    // take ownership of the memory block and
    // ensure that its destructor is not
    // called when the object goes out of scope
    // at the end of the function
    std::mem::forget(buf);
    // return the pointer so the runtime
    // can write data at this offset
    return ptr;
}

#[no_mangle]
pub extern "C" fn main(input: i32) -> i32 {

    // let a = A { value: 0 };
    // println!("{:?}", a);
    // let b = a;
    // println!("{:?}", a);

    let arr = alloc(input as usize);

    core::arch::wasm32::memory_grow::<0>(1);

    let raw_str = String::from("test");
    let str_1 = raw_str.as_str();
    let str_2 = "test 123";

    // let addr = evm_address();
    // let a = A { value: input };
    // a.value.clone() * a.value

    0
}