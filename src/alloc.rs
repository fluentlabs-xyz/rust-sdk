extern crate wee_alloc;

// Use `wee_alloc` as the global allocator.
#[global_allocator]
pub static ALLOC: wee_alloc::WeeAlloc = wee_alloc::WeeAlloc::INIT;
