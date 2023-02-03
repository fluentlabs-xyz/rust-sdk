#![no_std]
#![feature(lang_items)]

pub mod alloc;
pub mod binding;
pub mod types;
pub mod panic;

pub use binding::*;
pub use types::*;

#[lang = "eh_personality"]
extern "C" fn eh_personality() {}