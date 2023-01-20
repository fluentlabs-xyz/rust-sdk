(module
  (type (;0;) (func (param i32 i32)))
  (type (;1;) (func (param i32) (result i32)))
  (import "env" "_evm_return" (func $_evm_return (type 0)))
  (func $main (type 1) (param i32) (result i32)
    i32.const 1048576
    i32.const 398
    call $_evm_return
    i32.const 0)
  (table (;0;) 1 1 funcref)
  (memory (;0;) 17)
  (global $__stack_pointer (mut i32) (i32.const 1048576))
  (global (;1;) i32 (i32.const 1048974))
  (global (;2;) i32 (i32.const 1048976))
  (export "memory" (memory 0))
  (export "main" (func $main))
  (export "__data_end" (global 1))
  (export "__heap_base" (global 2))
  (data $.rodata (i32.const 1048576) "\00asm\01\00\00\00\01\0a\02`\01\7f\00`\01\7f\01\7f\02\14\01\03env\0c_evm_address\00\00\03\03\02\01\00\04\05\01p\01\01\01\05\03\01\00\10\06\19\03\7f\01A\80\80\c0\00\0b\7f\00A\80\80\c0\00\0b\7f\00A\80\80\c0\00\0b\07,\04\06memory\02\00\04main\00\01\0a__data_end\03\01\0b__heap_base\03\02\0a\87\02\02\e2\01\01\15\7f#\00A k\22\01$\00 \01A\0cj\10\02 \01-\00\0d!\02 \01-\00\0c!\03 \01-\00\0e!\04 \01-\00\0f!\05 \01-\00\10!\06 \01-\00\11!\07 \01-\00\12!\08 \01-\00\13!\09 \01-\00\14!\0a \01-\00\15!\0b \01-\00\16!\0c \01-\00\17!\0d \01-\00\18!\0e \01-\00\19!\0f \01-\00\1a!\10 \01-\00\1b!\11 \01-\00\1c!\12 \01-\00\1d!\13 \01-\00\1e!\14 \01-\00\1f!\15 \01A j$\00 \15 \14 \13 \12 \11 \10 \0f \0e \0d \0c \0b \0a \09 \08 \07 \06 \05 \04 \03 \02jjjjjjjjjjjjjjjjjjj\0b!\00 \00B\007\00\00 \00A\10jA\006\00\00 \00A\08jB\007\00\00 \00\10\00\0b"))
