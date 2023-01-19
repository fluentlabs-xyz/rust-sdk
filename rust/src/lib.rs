extern crate core;

use crate::binding::evm_address;

pub mod binding;
pub mod types;

#[no_mangle]
pub extern "C" fn main(_input: i32) -> i32 {
    let addr = evm_address();
    let mut addr_vec = vec![];
    for b in addr {
        addr_vec.push(b);
    }
    let mut sum = 0;
    for b in addr_vec {
        sum += b as i32;
    }
    sum

    // let mut data = Vec::new();
    // data.push(input);
    // return data.len() as i32;

    // let a = A { value: 0 };
    // println!("{:?}", a);
    // let b = a;
    // println!("{:?}", a);

    // let arr = alloc(input as usize);
    //
    // core::arch::wasm32::memory_grow::<0>(1);
    //
    // let raw_str = String::from("test");
    // let str_1 = raw_str.as_str();
    // let str_2 = "test 123";

    // let addr = evm_address();
    // let a = A { value: input };
    // a.value.clone() * a.value
}