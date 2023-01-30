(module
  (type (;0;) (func (param i32)))
  (type (;1;) (func (param i32 i32)))
  (type (;2;) (func (param i32) (result i32)))
  (import "env" "_evm_address" (func (;0;) (type 0)))
  (import "env" "_evm_timestamp" (func (;1;) (type 0)))
  (import "env" "_evm_balance" (func (;2;) (type 1)))
  (import "env" "_evm_caller" (func (;3;) (type 0)))
  (import "env" "_evm_origin" (func (;4;) (type 0)))
  (func (;5;) (type 2) (param i32) (result i32)
    (local i32 i32 i32 i32 i32)
    global.get 0
    i32.const 128
    i32.sub
    local.tee 1
    global.set 0
    i32.const 0
    local.set 2
    block  ;; label = @1
      local.get 0
      i32.const 1
      i32.and
      i32.eqz
      br_if 0 (;@1;)
      i32.const 0
      local.set 2
      local.get 1
      i32.const 56
      i32.add
      i32.const 16
      i32.add
      local.tee 3
      i32.const 0
      i32.store
      local.get 1
      i32.const 64
      i32.add
      local.tee 4
      i64.const 0
      i64.store
      local.get 1
      i64.const 0
      i64.store offset=56
      local.get 1
      i32.const 56
      i32.add
      call 0
      local.get 1
      i32.const 88
      i32.add
      i32.const 16
      i32.add
      local.get 4
      i64.load
      i64.store
      local.get 1
      i32.const 112
      i32.add
      local.get 3
      i32.load
      i32.store
      local.get 1
      i64.const 85899345920
      i64.store offset=88
      local.get 1
      local.get 1
      i64.load offset=56
      i64.store offset=96
      loop  ;; label = @2
        local.get 1
        i32.const 24
        i32.add
        local.get 1
        i32.const 88
        i32.add
        call 6
        local.get 1
        i32.load8_u offset=24
        i32.const 1
        i32.and
        i32.eqz
        br_if 1 (;@1;)
        local.get 2
        local.get 1
        i32.load8_u offset=25
        i32.const 255
        i32.and
        i32.add
        local.set 2
        br 0 (;@2;)
      end
    end
    block  ;; label = @1
      local.get 0
      i32.const 4
      i32.and
      i32.eqz
      br_if 0 (;@1;)
      local.get 1
      i64.const 0
      i64.store offset=88
      local.get 1
      i32.const 88
      i32.add
      call 1
      local.get 2
      local.get 1
      i32.load offset=88
      i32.add
      local.set 2
    end
    block  ;; label = @1
      local.get 0
      i32.const 8
      i32.and
      i32.eqz
      br_if 0 (;@1;)
      local.get 1
      i32.const 32
      i32.add
      i32.const 16
      i32.add
      i32.const 16843009
      i32.store
      local.get 1
      i32.const 32
      i32.add
      i32.const 8
      i32.add
      i64.const 72340172838076673
      i64.store
      local.get 1
      i64.const 72340172838076673
      i64.store offset=32
      local.get 1
      i32.const 56
      i32.add
      i32.const 24
      i32.add
      local.tee 3
      i64.const 0
      i64.store
      local.get 1
      i32.const 56
      i32.add
      i32.const 16
      i32.add
      local.tee 4
      i64.const 0
      i64.store
      local.get 1
      i32.const 56
      i32.add
      i32.const 8
      i32.add
      local.tee 5
      i64.const 0
      i64.store
      local.get 1
      i64.const 0
      i64.store offset=56
      local.get 1
      i32.const 32
      i32.add
      local.get 1
      i32.const 56
      i32.add
      call 2
      local.get 1
      i32.const 88
      i32.add
      i32.const 16
      i32.add
      local.get 5
      i64.load
      i64.store
      local.get 1
      i32.const 88
      i32.add
      i32.const 24
      i32.add
      local.get 4
      i64.load
      i64.store
      local.get 1
      i32.const 120
      i32.add
      local.get 3
      i64.load
      i64.store
      local.get 1
      i64.const 137438953472
      i64.store offset=88
      local.get 1
      local.get 1
      i64.load offset=56
      i64.store offset=96
      local.get 1
      i32.const 88
      i32.add
      i32.const 8
      i32.add
      local.set 4
      i32.const 0
      local.set 3
      block  ;; label = @2
        loop  ;; label = @3
          local.get 1
          i32.const 16
          i32.add
          local.get 1
          i32.const 88
          i32.add
          call 7
          local.get 1
          i32.load offset=16
          i32.eqz
          br_if 1 (;@2;)
          local.get 3
          local.get 4
          local.get 1
          i32.load offset=20
          i32.add
          i32.load8_u
          i32.add
          local.set 3
          br 0 (;@3;)
        end
      end
      local.get 3
      local.get 2
      i32.add
      local.set 2
    end
    block  ;; label = @1
      local.get 0
      i32.const 16
      i32.and
      i32.eqz
      br_if 0 (;@1;)
      i32.const 0
      local.set 3
      local.get 1
      i32.const 56
      i32.add
      i32.const 16
      i32.add
      local.tee 4
      i32.const 0
      i32.store
      local.get 1
      i32.const 64
      i32.add
      local.tee 5
      i64.const 0
      i64.store
      local.get 1
      i64.const 0
      i64.store offset=56
      local.get 1
      i32.const 56
      i32.add
      call 3
      local.get 1
      i32.const 88
      i32.add
      i32.const 16
      i32.add
      local.get 5
      i64.load
      i64.store
      local.get 1
      i32.const 112
      i32.add
      local.get 4
      i32.load
      i32.store
      local.get 1
      i64.const 85899345920
      i64.store offset=88
      local.get 1
      local.get 1
      i64.load offset=56
      i64.store offset=96
      block  ;; label = @2
        loop  ;; label = @3
          local.get 1
          i32.const 8
          i32.add
          local.get 1
          i32.const 88
          i32.add
          call 6
          local.get 1
          i32.load8_u offset=8
          i32.const 1
          i32.and
          i32.eqz
          br_if 1 (;@2;)
          local.get 3
          local.get 1
          i32.load8_u offset=9
          i32.const 255
          i32.and
          i32.add
          local.set 3
          br 0 (;@3;)
        end
      end
      local.get 3
      local.get 2
      i32.add
      local.set 2
    end
    block  ;; label = @1
      local.get 0
      i32.const 32
      i32.and
      i32.eqz
      br_if 0 (;@1;)
      i32.const 0
      local.set 3
      local.get 1
      i32.const 56
      i32.add
      i32.const 16
      i32.add
      local.tee 4
      i32.const 0
      i32.store
      local.get 1
      i32.const 64
      i32.add
      local.tee 0
      i64.const 0
      i64.store
      local.get 1
      i64.const 0
      i64.store offset=56
      local.get 1
      i32.const 56
      i32.add
      call 4
      local.get 1
      i32.const 88
      i32.add
      i32.const 16
      i32.add
      local.get 0
      i64.load
      i64.store
      local.get 1
      i32.const 112
      i32.add
      local.get 4
      i32.load
      i32.store
      local.get 1
      i64.const 85899345920
      i64.store offset=88
      local.get 1
      local.get 1
      i64.load offset=56
      i64.store offset=96
      block  ;; label = @2
        loop  ;; label = @3
          local.get 1
          local.get 1
          i32.const 88
          i32.add
          call 6
          local.get 1
          i32.load8_u
          i32.const 1
          i32.and
          i32.eqz
          br_if 1 (;@2;)
          local.get 3
          local.get 1
          i32.load8_u offset=1
          i32.const 255
          i32.and
          i32.add
          local.set 3
          br 0 (;@3;)
        end
      end
      local.get 3
      local.get 2
      i32.add
      local.set 2
    end
    local.get 1
    i32.const 128
    i32.add
    global.set 0
    local.get 2)
  (func (;6;) (type 1) (param i32 i32)
    (local i32 i32)
    global.get 0
    i32.const 16
    i32.sub
    local.tee 2
    global.set 0
    local.get 2
    i32.const 8
    i32.add
    local.get 1
    call 7
    block  ;; label = @1
      block  ;; label = @2
        local.get 2
        i32.load offset=8
        local.tee 3
        br_if 0 (;@2;)
        br 1 (;@1;)
      end
      local.get 1
      local.get 2
      i32.load offset=12
      i32.add
      i32.const 8
      i32.add
      i32.load8_u
      local.set 1
    end
    local.get 0
    local.get 1
    i32.store8 offset=1
    local.get 0
    local.get 3
    i32.const 0
    i32.ne
    i32.store8
    local.get 2
    i32.const 16
    i32.add
    global.set 0)
  (func (;7;) (type 1) (param i32 i32)
    (local i32 i32)
    i32.const 0
    local.set 2
    block  ;; label = @1
      local.get 1
      i32.load offset=4
      local.get 1
      i32.load
      local.tee 3
      i32.eq
      br_if 0 (;@1;)
      i32.const 1
      local.set 2
      local.get 1
      local.get 3
      i32.const 1
      i32.add
      i32.store
    end
    local.get 0
    local.get 3
    i32.store offset=4
    local.get 0
    local.get 2
    i32.store)
  (memory (;0;) 16)
  (global (;0;) (mut i32) (i32.const 1048576))
  (global (;1;) i32 (i32.const 1048576))
  (global (;2;) i32 (i32.const 1048576))
  (export "memory" (memory 0))
  (export "main" (func 5))
  (export "__data_end" (global 1))
  (export "__heap_base" (global 2)))
