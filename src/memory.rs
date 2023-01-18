use std::alloc::{GlobalAlloc, Layout};

struct WebAssemblyGlobalAllocator;

static mut MEMORY_OFFSET: u32 = 0;
static mut MEMORY_PAGE: u32 = 0;

const WASM_PAGE_SIZE: u32 = 0x10000;

unsafe impl GlobalAlloc for WebAssemblyGlobalAllocator {
    unsafe fn alloc(&self, layout: Layout) -> *mut u8 {
        if MEMORY_PAGE == 0 {
            MEMORY_PAGE = core::arch::wasm32::memory_size::<0>() as u32 + 1;
        }
        let grow_factor = (layout.size() as u32 - WASM_PAGE_SIZE + MEMORY_OFFSET.clone()) / WASM_PAGE_SIZE;
        if grow_factor > 0 {
            core::arch::wasm32::memory_grow::<0>(grow_factor as usize);
            MEMORY_PAGE += grow_factor
        }
        let current_offset = MEMORY_OFFSET.clone() as u32;
        MEMORY_OFFSET = (current_offset.clone() + layout.size() as u32) % WASM_PAGE_SIZE;
        return current_offset as *mut u8;
    }

    unsafe fn dealloc(&self, _ptr: *mut u8, _layout: Layout) {
        // TODO: "not possible"
    }
}

#[global_allocator]
static GLOBAL: WebAssemblyGlobalAllocator = WebAssemblyGlobalAllocator;
