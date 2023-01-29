(module
  (type (;0;) (func (param i32 i32)))
  (type (;1;) (func (param i32) (result i32)))
  (import "env" "_evm_return" (func $_evm_return (type 0)))
  (func $main (type 1) (param i32) (result i32)
    i32.const 1048576
    i32.const 12
    call $_evm_return
    i32.const 0)
  (table (;0;) 1 1 funcref)
  (memory (;0;) 17)
  (global $__stack_pointer (mut i32) (i32.const 1048576))
  (global (;1;) i32 (i32.const 1048588))
  (global (;2;) i32 (i32.const 1048592))
  (export "memory" (memory 0))
  (export "main" (func $main))
  (export "__data_end" (global 1))
  (export "__heap_base" (global 2))
  (data $.rodata (i32.const 1048576) "Hello, World"))
