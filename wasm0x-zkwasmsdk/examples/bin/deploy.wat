(module
  (type (;0;) (func (param i32 i32)))
  (type (;1;) (func (param i32) (result i32)))
  (import "env" "_evm_return" (func $_evm_return (type 0)))
  (func $main (type 1) (param i32) (result i32)
    i32.const 1048576
    i32.const 170
    call $_evm_return
    i32.const 0)
  (table (;0;) 1 1 funcref)
  (memory (;0;) 17)
  (global $__stack_pointer (mut i32) (i32.const 1048576))
  (global (;1;) i32 (i32.const 1048746))
  (global (;2;) i32 (i32.const 1048752))
  (export "memory" (memory 0))
  (export "main" (func $main))
  (export "__data_end" (global 1))
  (export "__heap_base" (global 2))
  (data $.rodata (i32.const 1048576) "\00asm\01\00\00\00\01\0b\02`\02\7f\7f\00`\01\7f\01\7f\02\13\01\03env\0b_evm_return\00\00\03\02\01\01\04\05\01p\01\01\01\05\03\01\00\11\06\19\03\7f\01A\80\80\c0\00\0b\7f\00A\8b\80\c0\00\0b\7f\00A\90\80\c0\00\0b\07,\04\06memory\02\00\04main\00\01\0a__data_end\03\01\0b__heap_base\03\02\0a\0f\01\0d\00A\80\80\c0\00A\0b\10\00A\00\0b\0b\14\01\00A\80\80\c0\00\0b\0bHello, Ankr"))
