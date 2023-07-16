#![no_std]
#![no_main]

use wasm0x_zkwasmsdk::*;

#[no_mangle]
pub extern "C" fn _math_add(a: [u64; 4], b: [u64; 4]) -> [u64; 4] {
    let mut result: [u64; 4] = [0; 4];
    for i in 0..4 {
        let mut overflow = false;
        let mut sum = a[i] + b[i];
        overflow |= sum < a[i];
        sum += result[i];
        overflow |= result[i] != 0 && sum == 0;
        if overflow && i + 1 < 4 {
            result[i + 1] += 1;
        }
        result[i] = sum;
    }
    result
}

#[no_mangle]
pub extern "C" fn _math_mul(a: [u64; 4], b: [u64; 4]) -> [u64; 4] {
    let mut a: [u64; 8] = [0; 8];
    let mut b: [u64; 8] = [0; 8];
    let mut c: [u64; 8] = [0; 8];
    for i in 0..4 {
        a[2 * i] = a[i] & 0xffffffff;
        a[2 * i + 1] = a[i] >> 32;
        b[2 * i] = b[i] & 0xffffffff;
        b[2 * i + 1] = b[i] >> 32;
    }
    for i in 0..8 {
        let mut j = 0;
        for j in (i+j)..8 {
            let p = a[i] * b[j];
            c[i + j] += p & 0xffffffff;
            if i + j < 7 {
                c[i + j + 1] += p >> 32;
            }
        }
    }
    for i in 0..8 {
        if i < 7 {
            c[i + 1] += c[i] >> 32;
        }
        c[i] &= 0xffffffff;
    }
    return [
        c[0] | (c[1] << 32),
        c[2] | (c[3] << 32),
        c[4] | (c[5] << 32),
        c[6] | (c[7] << 32)
    ];
}