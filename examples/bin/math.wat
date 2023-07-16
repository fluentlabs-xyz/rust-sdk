(module
  (type (;0;) (func (param i32) (result i64)))
  (type (;1;) (func (param i32 i32 i32) (result i32)))
  (type (;2;) (func (param i32 i32) (result i32)))
  (type (;3;) (func (param i32 i32)))
  (type (;4;) (func (param i32 i64 i64 i64 i64 i64 i64 i64 i64)))
  (type (;5;) (func (param i32)))
  (type (;6;) (func (param i32 i32 i32 i32) (result i32)))
  (import "env" "_evm_return" (func (;0;) (type 3)))
  (func (;1;) (type 4) (param i32 i64 i64 i64 i64 i64 i64 i64 i64)
    (local i32 i32 i32 i32)
    global.get 0
    i32.const 96
    i32.sub
    local.tee 9
    i32.const 64
    i32.add
    i32.const 8
    i32.add
    i64.const 0
    i64.store
    local.get 9
    i32.const 80
    i32.add
    i64.const 0
    i64.store
    local.get 9
    i32.const 64
    i32.add
    i32.const 24
    i32.add
    i64.const 0
    i64.store
    local.get 9
    local.get 4
    i64.store offset=24
    local.get 9
    local.get 3
    i64.store offset=16
    local.get 9
    local.get 2
    i64.store offset=8
    local.get 9
    local.get 1
    i64.store
    local.get 9
    local.get 8
    i64.store offset=56
    local.get 9
    local.get 7
    i64.store offset=48
    local.get 9
    local.get 6
    i64.store offset=40
    local.get 9
    local.get 5
    i64.store offset=32
    local.get 9
    i64.const 0
    i64.store offset=64
    i32.const 0
    local.set 10
    block  ;; label = @1
      loop  ;; label = @2
        local.get 10
        i32.const 32
        i32.eq
        br_if 1 (;@1;)
        block  ;; label = @3
          local.get 9
          i32.const 32
          i32.add
          local.get 10
          i32.add
          i64.load
          local.tee 4
          local.get 9
          local.get 10
          i32.add
          i64.load
          i64.add
          local.tee 3
          local.get 4
          i64.lt_u
          local.get 9
          i32.const 64
          i32.add
          local.get 10
          i32.add
          local.tee 11
          i64.load
          local.tee 4
          i64.const 0
          i64.ne
          local.get 3
          local.get 4
          i64.add
          local.tee 4
          i64.eqz
          i32.and
          i32.or
          i32.const 1
          i32.ne
          br_if 0 (;@3;)
          local.get 10
          i32.const 24
          i32.eq
          br_if 0 (;@3;)
          local.get 11
          i32.const 8
          i32.add
          local.tee 12
          local.get 12
          i64.load
          i64.const 1
          i64.add
          i64.store
        end
        local.get 11
        local.get 4
        i64.store
        local.get 10
        i32.const 8
        i32.add
        local.set 10
        br 0 (;@2;)
      end
    end
    local.get 0
    local.get 9
    i64.load offset=88
    i64.store offset=24
    local.get 0
    local.get 9
    i64.load offset=80
    i64.store offset=16
    local.get 0
    local.get 9
    i64.load offset=72
    i64.store offset=8
    local.get 0
    local.get 9
    i64.load offset=64
    i64.store)
  (func (;2;) (type 4) (param i32 i64 i64 i64 i64 i64 i64 i64 i64)
    (local i32 i32 i32 i32 i32 i32 i32 i32 i32 i64 i64 i64 i64 i64 i64 i32 i32)
    global.get 0
    i32.const 192
    i32.sub
    local.tee 9
    global.set 0
    i32.const 0
    local.set 10
    local.get 9
    i32.const 0
    i32.const 64
    call 11
    local.tee 11
    i32.const 64
    i32.add
    i32.const 0
    i32.const 64
    call 11
    drop
    local.get 11
    i32.const 128
    i32.add
    i32.const 0
    i32.const 64
    call 11
    drop
    i32.const 0
    local.set 9
    block  ;; label = @1
      loop  ;; label = @2
        block  ;; label = @3
          local.get 10
          i32.const 64
          i32.ne
          br_if 0 (;@3;)
          local.get 11
          i32.const 64
          i32.add
          local.set 12
          i32.const 0
          local.set 13
          local.get 11
          i32.const 128
          i32.add
          local.set 14
          i32.const 56
          local.set 15
          i32.const 64
          local.set 16
          i32.const 0
          local.set 10
          br 2 (;@1;)
        end
        local.get 11
        local.get 10
        i32.add
        local.tee 17
        local.get 11
        local.get 9
        i32.add
        local.tee 16
        i64.load32_u
        i64.store
        local.get 11
        i32.const 64
        i32.add
        local.get 10
        i32.add
        local.tee 12
        local.get 11
        i32.const 64
        i32.add
        local.get 9
        i32.add
        local.tee 14
        i64.load32_u
        i64.store
        local.get 17
        i32.const 8
        i32.add
        local.get 16
        i64.load32_u offset=4
        i64.store
        local.get 12
        i32.const 8
        i32.add
        local.get 14
        i64.load32_u offset=4
        i64.store
        local.get 10
        i32.const 16
        i32.add
        local.set 10
        local.get 9
        i32.const 8
        i32.add
        local.set 9
        br 0 (;@2;)
      end
    end
    loop  ;; label = @1
      block  ;; label = @2
        local.get 10
        i32.const 8
        i32.ne
        br_if 0 (;@2;)
        i32.const 0
        local.set 10
        block  ;; label = @3
          loop  ;; label = @4
            local.get 10
            i32.const 64
            i32.eq
            br_if 1 (;@3;)
            block  ;; label = @5
              block  ;; label = @6
                local.get 10
                i32.const 56
                i32.ne
                br_if 0 (;@6;)
                local.get 11
                i64.load32_u offset=184
                local.set 18
                br 1 (;@5;)
              end
              local.get 11
              i32.const 128
              i32.add
              local.get 10
              i32.add
              local.tee 9
              i32.const 8
              i32.add
              local.tee 17
              local.get 17
              i64.load
              local.get 9
              i64.load
              local.tee 18
              i64.const 32
              i64.shr_u
              i64.add
              i64.store
            end
            local.get 11
            i32.const 128
            i32.add
            local.get 10
            i32.add
            local.get 18
            i64.const 4294967295
            i64.and
            i64.store
            local.get 10
            i32.const 8
            i32.add
            local.set 10
            br 0 (;@4;)
          end
        end
        local.get 11
        i64.load offset=128
        local.set 18
        local.get 11
        i64.load offset=136
        local.set 19
        local.get 11
        i64.load offset=144
        local.set 20
        local.get 11
        i64.load offset=152
        local.set 21
        local.get 11
        i64.load offset=160
        local.set 22
        local.get 11
        i64.load offset=168
        local.set 23
        local.get 0
        local.get 11
        i64.load offset=184
        i64.const 32
        i64.shl
        local.get 11
        i64.load offset=176
        i64.or
        i64.store offset=24
        local.get 0
        local.get 22
        local.get 23
        i64.const 32
        i64.shl
        i64.or
        i64.store offset=16
        local.get 0
        local.get 20
        local.get 21
        i64.const 32
        i64.shl
        i64.or
        i64.store offset=8
        local.get 0
        local.get 18
        local.get 19
        i64.const 32
        i64.shl
        i64.or
        i64.store
        local.get 11
        i32.const 192
        i32.add
        global.set 0
        return
      end
      local.get 10
      i32.const 1
      i32.add
      local.set 24
      local.get 11
      local.get 10
      i32.const 3
      i32.shl
      i32.add
      local.set 25
      i32.const 0
      local.set 10
      local.get 13
      local.set 9
      block  ;; label = @2
        loop  ;; label = @3
          local.get 16
          local.get 10
          i32.eq
          br_if 1 (;@2;)
          block  ;; label = @4
            local.get 9
            i32.const 7
            i32.gt_u
            br_if 0 (;@4;)
            local.get 14
            local.get 10
            i32.add
            local.tee 17
            local.get 17
            i64.load
            local.get 12
            local.get 10
            i32.add
            i64.load
            local.get 25
            i64.load
            i64.mul
            local.tee 18
            i64.const 4294967295
            i64.and
            i64.add
            i64.store
            block  ;; label = @5
              local.get 15
              local.get 10
              i32.eq
              br_if 0 (;@5;)
              local.get 17
              i32.const 8
              i32.add
              local.tee 17
              local.get 17
              i64.load
              local.get 18
              i64.const 32
              i64.shr_u
              i64.add
              i64.store
            end
            local.get 9
            i32.const 1
            i32.add
            local.set 9
            local.get 10
            i32.const 8
            i32.add
            local.set 10
            br 1 (;@3;)
          end
        end
        local.get 9
        call 3
        unreachable
      end
      local.get 16
      i32.const -8
      i32.add
      local.set 16
      local.get 15
      i32.const -16
      i32.add
      local.set 15
      local.get 14
      i32.const 16
      i32.add
      local.set 14
      local.get 13
      i32.const 2
      i32.add
      local.set 13
      local.get 12
      i32.const 8
      i32.add
      local.set 12
      local.get 24
      local.set 10
      br 0 (;@1;)
    end)
  (func (;3;) (type 5) (param i32)
    (local i32)
    global.get 0
    i32.const 48
    i32.sub
    local.tee 1
    global.set 0
    local.get 1
    i32.const 8
    i32.store offset=4
    local.get 1
    local.get 0
    i32.store
    local.get 1
    i32.const 8
    i32.add
    i32.const 12
    i32.add
    i32.const 2
    i32.store
    local.get 1
    i32.const 28
    i32.add
    i32.const 2
    i32.store
    local.get 1
    i32.const 32
    i32.add
    i32.const 12
    i32.add
    i32.const 1
    i32.store
    local.get 1
    i32.const 1048628
    i32.store offset=16
    local.get 1
    i32.const 0
    i32.store offset=8
    local.get 1
    i32.const 1
    i32.store offset=36
    local.get 1
    local.get 1
    i32.const 32
    i32.add
    i32.store offset=24
    local.get 1
    local.get 1
    i32.store offset=40
    local.get 1
    local.get 1
    i32.const 4
    i32.add
    i32.store offset=32
    local.get 1
    i32.const 8
    i32.add
    call 4
    unreachable)
  (func (;4;) (type 5) (param i32)
    i32.const 1048576
    i32.const 1048644
    call 5
    unreachable)
  (func (;5;) (type 3) (param i32 i32)
    block  ;; label = @1
      block  ;; label = @2
        local.get 0
        local.get 1
        i32.load offset=12
        call_indirect (type 0)
        i64.const -8527728395957036344
        i64.ne
        br_if 0 (;@2;)
        local.get 0
        i32.load
        local.get 0
        i32.load offset=4
        call 0
        br 1 (;@1;)
      end
      i32.const 1048860
      i32.const 14
      call 0
    end
    loop  ;; label = @1
      br 0 (;@1;)
    end)
  (func (;6;) (type 5) (param i32))
  (func (;7;) (type 0) (param i32) (result i64)
    i64.const 8180665819223137622)
  (func (;8;) (type 2) (param i32 i32) (result i32)
    (local i32 i32 i64 i64 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32)
    global.get 0
    i32.const 48
    i32.sub
    local.tee 2
    global.set 0
    i32.const 39
    local.set 3
    block  ;; label = @1
      block  ;; label = @2
        local.get 0
        i64.load32_u
        local.tee 4
        i64.const 10000
        i64.ge_u
        br_if 0 (;@2;)
        local.get 4
        local.set 5
        br 1 (;@1;)
      end
      i32.const 39
      local.set 3
      loop  ;; label = @2
        local.get 2
        i32.const 9
        i32.add
        local.get 3
        i32.add
        local.tee 0
        i32.const -4
        i32.add
        local.get 4
        i64.const 10000
        i64.div_u
        local.tee 5
        i64.const 55536
        i64.mul
        local.get 4
        i64.add
        i32.wrap_i64
        local.tee 6
        i32.const 65535
        i32.and
        i32.const 100
        i32.div_u
        local.tee 7
        i32.const 1
        i32.shl
        i32.const 1048660
        i32.add
        i32.load16_u align=1
        i32.store16 align=1
        local.get 0
        i32.const -2
        i32.add
        local.get 7
        i32.const -100
        i32.mul
        local.get 6
        i32.add
        i32.const 65535
        i32.and
        i32.const 1
        i32.shl
        i32.const 1048660
        i32.add
        i32.load16_u align=1
        i32.store16 align=1
        local.get 3
        i32.const -4
        i32.add
        local.set 3
        local.get 4
        i64.const 99999999
        i64.gt_u
        local.set 0
        local.get 5
        local.set 4
        local.get 0
        br_if 0 (;@2;)
      end
    end
    block  ;; label = @1
      local.get 5
      i32.wrap_i64
      local.tee 0
      i32.const 99
      i32.le_u
      br_if 0 (;@1;)
      local.get 2
      i32.const 9
      i32.add
      local.get 3
      i32.const -2
      i32.add
      local.tee 3
      i32.add
      local.get 5
      i32.wrap_i64
      local.tee 6
      i32.const 65535
      i32.and
      i32.const 100
      i32.div_u
      local.tee 0
      i32.const -100
      i32.mul
      local.get 6
      i32.add
      i32.const 65535
      i32.and
      i32.const 1
      i32.shl
      i32.const 1048660
      i32.add
      i32.load16_u align=1
      i32.store16 align=1
    end
    block  ;; label = @1
      block  ;; label = @2
        local.get 0
        i32.const 10
        i32.lt_u
        br_if 0 (;@2;)
        local.get 2
        i32.const 9
        i32.add
        local.get 3
        i32.const -2
        i32.add
        local.tee 3
        i32.add
        local.get 0
        i32.const 1
        i32.shl
        i32.const 1048660
        i32.add
        i32.load16_u align=1
        i32.store16 align=1
        br 1 (;@1;)
      end
      local.get 2
      i32.const 9
      i32.add
      local.get 3
      i32.const -1
      i32.add
      local.tee 3
      i32.add
      local.get 0
      i32.const 48
      i32.add
      i32.store8
    end
    i32.const 39
    local.get 3
    i32.sub
    local.set 8
    i32.const 1
    local.set 0
    i32.const 43
    i32.const 1114112
    local.get 1
    i32.load offset=24
    local.tee 6
    i32.const 1
    i32.and
    local.tee 7
    select
    local.set 9
    local.get 6
    i32.const 29
    i32.shl
    i32.const 31
    i32.shr_s
    i32.const 1048576
    i32.and
    local.set 10
    local.get 2
    i32.const 9
    i32.add
    local.get 3
    i32.add
    local.set 11
    block  ;; label = @1
      block  ;; label = @2
        local.get 1
        i32.load offset=8
        br_if 0 (;@2;)
        local.get 1
        i32.load
        local.tee 3
        local.get 1
        i32.const 4
        i32.add
        i32.load
        local.tee 6
        local.get 9
        local.get 10
        call 9
        br_if 1 (;@1;)
        local.get 3
        local.get 11
        local.get 8
        local.get 6
        i32.load offset=12
        call_indirect (type 1)
        local.set 0
        br 1 (;@1;)
      end
      block  ;; label = @2
        block  ;; label = @3
          block  ;; label = @4
            block  ;; label = @5
              block  ;; label = @6
                local.get 1
                i32.const 12
                i32.add
                i32.load
                local.tee 12
                local.get 8
                local.get 7
                i32.add
                local.tee 0
                i32.le_u
                br_if 0 (;@6;)
                local.get 6
                i32.const 8
                i32.and
                br_if 4 (;@2;)
                local.get 12
                local.get 0
                i32.sub
                local.tee 0
                local.set 13
                i32.const 1
                local.get 1
                i32.load8_u offset=32
                local.tee 3
                local.get 3
                i32.const 3
                i32.eq
                select
                i32.const 3
                i32.and
                local.tee 3
                br_table 3 (;@3;) 1 (;@5;) 2 (;@4;) 3 (;@3;)
              end
              i32.const 1
              local.set 0
              local.get 1
              i32.load
              local.tee 3
              local.get 1
              i32.const 4
              i32.add
              i32.load
              local.tee 6
              local.get 9
              local.get 10
              call 9
              br_if 4 (;@1;)
              local.get 3
              local.get 11
              local.get 8
              local.get 6
              i32.load offset=12
              call_indirect (type 1)
              local.set 0
              br 4 (;@1;)
            end
            i32.const 0
            local.set 13
            local.get 0
            local.set 3
            br 1 (;@3;)
          end
          local.get 0
          i32.const 1
          i32.shr_u
          local.set 3
          local.get 0
          i32.const 1
          i32.add
          i32.const 1
          i32.shr_u
          local.set 13
        end
        local.get 3
        i32.const 1
        i32.add
        local.set 3
        local.get 1
        i32.const 4
        i32.add
        i32.load
        local.set 7
        local.get 1
        i32.load offset=28
        local.set 6
        local.get 1
        i32.load
        local.set 1
        block  ;; label = @3
          loop  ;; label = @4
            local.get 3
            i32.const -1
            i32.add
            local.tee 3
            i32.eqz
            br_if 1 (;@3;)
            local.get 1
            local.get 6
            local.get 7
            i32.load offset=16
            call_indirect (type 2)
            i32.eqz
            br_if 0 (;@4;)
          end
          i32.const 1
          local.set 0
          br 2 (;@1;)
        end
        i32.const 1
        local.set 0
        local.get 6
        i32.const 1114112
        i32.eq
        br_if 1 (;@1;)
        local.get 1
        local.get 7
        local.get 9
        local.get 10
        call 9
        br_if 1 (;@1;)
        local.get 1
        local.get 11
        local.get 8
        local.get 7
        i32.load offset=12
        call_indirect (type 1)
        br_if 1 (;@1;)
        i32.const 0
        local.set 3
        block  ;; label = @3
          loop  ;; label = @4
            block  ;; label = @5
              local.get 13
              local.get 3
              i32.ne
              br_if 0 (;@5;)
              local.get 13
              local.set 3
              br 2 (;@3;)
            end
            local.get 3
            i32.const 1
            i32.add
            local.set 3
            local.get 1
            local.get 6
            local.get 7
            i32.load offset=16
            call_indirect (type 2)
            i32.eqz
            br_if 0 (;@4;)
          end
          local.get 3
          i32.const -1
          i32.add
          local.set 3
        end
        local.get 3
        local.get 13
        i32.lt_u
        local.set 0
        br 1 (;@1;)
      end
      local.get 1
      i32.load offset=28
      local.set 14
      local.get 1
      i32.const 48
      i32.store offset=28
      local.get 1
      i32.load8_u offset=32
      local.set 15
      i32.const 1
      local.set 0
      local.get 1
      i32.const 1
      i32.store8 offset=32
      local.get 1
      i32.load
      local.tee 6
      local.get 1
      i32.const 4
      i32.add
      i32.load
      local.tee 13
      local.get 9
      local.get 10
      call 9
      br_if 0 (;@1;)
      local.get 3
      local.get 12
      i32.add
      local.get 7
      i32.sub
      i32.const -38
      i32.add
      local.set 3
      block  ;; label = @2
        loop  ;; label = @3
          local.get 3
          i32.const -1
          i32.add
          local.tee 3
          i32.eqz
          br_if 1 (;@2;)
          local.get 6
          i32.const 48
          local.get 13
          i32.load offset=16
          call_indirect (type 2)
          i32.eqz
          br_if 0 (;@3;)
          br 2 (;@1;)
        end
      end
      local.get 6
      local.get 11
      local.get 8
      local.get 13
      i32.load offset=12
      call_indirect (type 1)
      br_if 0 (;@1;)
      local.get 1
      local.get 15
      i32.store8 offset=32
      local.get 1
      local.get 14
      i32.store offset=28
      i32.const 0
      local.set 0
    end
    local.get 2
    i32.const 48
    i32.add
    global.set 0
    local.get 0)
  (func (;9;) (type 6) (param i32 i32 i32 i32) (result i32)
    (local i32)
    block  ;; label = @1
      block  ;; label = @2
        block  ;; label = @3
          local.get 2
          i32.const 1114112
          i32.eq
          br_if 0 (;@3;)
          i32.const 1
          local.set 4
          local.get 0
          local.get 2
          local.get 1
          i32.load offset=16
          call_indirect (type 2)
          br_if 1 (;@2;)
        end
        local.get 3
        br_if 1 (;@1;)
        i32.const 0
        local.set 4
      end
      local.get 4
      return
    end
    local.get 0
    local.get 3
    i32.const 0
    local.get 1
    i32.load offset=12
    call_indirect (type 1))
  (func (;10;) (type 1) (param i32 i32 i32) (result i32)
    (local i32 i32 i32)
    block  ;; label = @1
      block  ;; label = @2
        local.get 2
        i32.const 15
        i32.gt_u
        br_if 0 (;@2;)
        local.get 0
        local.set 3
        br 1 (;@1;)
      end
      local.get 0
      i32.const 0
      local.get 0
      i32.sub
      i32.const 3
      i32.and
      local.tee 4
      i32.add
      local.set 5
      block  ;; label = @2
        local.get 4
        i32.eqz
        br_if 0 (;@2;)
        local.get 0
        local.set 3
        loop  ;; label = @3
          local.get 3
          local.get 1
          i32.store8
          local.get 3
          i32.const 1
          i32.add
          local.tee 3
          local.get 5
          i32.lt_u
          br_if 0 (;@3;)
        end
      end
      local.get 5
      local.get 2
      local.get 4
      i32.sub
      local.tee 4
      i32.const -4
      i32.and
      local.tee 2
      i32.add
      local.set 3
      block  ;; label = @2
        local.get 2
        i32.const 1
        i32.lt_s
        br_if 0 (;@2;)
        local.get 1
        i32.const 255
        i32.and
        i32.const 16843009
        i32.mul
        local.set 2
        loop  ;; label = @3
          local.get 5
          local.get 2
          i32.store
          local.get 5
          i32.const 4
          i32.add
          local.tee 5
          local.get 3
          i32.lt_u
          br_if 0 (;@3;)
        end
      end
      local.get 4
      i32.const 3
      i32.and
      local.set 2
    end
    block  ;; label = @1
      local.get 2
      i32.eqz
      br_if 0 (;@1;)
      local.get 3
      local.get 2
      i32.add
      local.set 5
      loop  ;; label = @2
        local.get 3
        local.get 1
        i32.store8
        local.get 3
        i32.const 1
        i32.add
        local.tee 3
        local.get 5
        i32.lt_u
        br_if 0 (;@2;)
      end
    end
    local.get 0)
  (func (;11;) (type 1) (param i32 i32 i32) (result i32)
    local.get 0
    local.get 1
    local.get 2
    call 10)
  (table (;0;) 4 4 funcref)
  (memory (;0;) 17)
  (global (;0;) (mut i32) (i32.const 1048576))
  (global (;1;) i32 (i32.const 1048874))
  (global (;2;) i32 (i32.const 1048880))
  (export "memory" (memory 0))
  (export "_math_add" (func 1))
  (export "_math_mul" (func 2))
  (export "__data_end" (global 1))
  (export "__heap_base" (global 2))
  (elem (;0;) (i32.const 1) func 8 6 7)
  (data (;0;) (i32.const 1048576) "index out of bounds: the len is  but the index is \00\00\00\00\10\00 \00\00\00 \00\10\00\12\00\00\00\02\00\00\00\00\00\00\00\01\00\00\00\03\00\00\0000010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899panic occurred"))
