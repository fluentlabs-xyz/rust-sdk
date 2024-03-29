use crate::types::*;

extern {
    fn _sys_read(offset: u32, len: u32, target: *mut u8);
}

#[inline(always)]
pub fn sys_read_slice(offset: u32, target: &mut [u8]) {
    unsafe {
        _sys_read(offset, target.len() as u32, target.as_mut_ptr())
    }
}

extern {
    fn _evm_stop();
    fn _evm_return(offset: *const u8, size: u32);
    fn _evm_keccak256(offset: *const u8, size: u32, dest: *mut u8);
    fn _evm_address(dest: *mut u8);
    fn _evm_balance(address: *const u8, dest: *mut u8);
    fn _evm_origin(dest: *mut u8);
    fn _evm_caller(dest: *mut u8);
    fn _evm_callvalue(dest: *mut u8);
    fn _evm_calldataload(offset: u32, dest: *mut u8);
    fn _evm_calldatasize(dest: *mut u32);
    fn _evm_calldatacopy(mem_offset: *mut u8, data_offset: *const u8, length: u32);
    fn _evm_codesize(dest: *mut u32);
    fn _evm_codecopy(mem_offset: *mut u8, code_offset: *const u8, length: u32);
    fn _evm_gasprice(dest: *mut u8);
    fn _evm_extcodesize(address: *const u8, dest: *mut u32);
    fn _evm_extcodecopy(address: *const u8, mem_offset: *const u8, code_offset: u32, length: u32);
    fn _evm_extcodehash(address: *const u8, dest: *mut u8);
    fn _evm_returndatasize(dest: *mut u32);
    fn _evm_returndatacopy(mem_offset: *const u8, data_offset: u32, length: u32);
    fn _evm_blockhash(num: u64, dest: *mut u8);
    fn _evm_coinbase(dest: *mut u8);
    fn _evm_timestamp(dest: *mut i64);
    fn _evm_number(dest: *mut u64);
    fn _evm_difficulty(dest: *mut u8);
    fn _evm_gaslimit(dest: *mut u64);
    fn _evm_chainid(dest: *mut u8);
    fn _evm_basefee(dest: *mut u8);
    fn _evm_sload(slot: *const u8, dest: *mut u8);
    fn _evm_sstore(slot: *const u8, value: *const u8);
    fn _evm_log0(data_offset: i32, data_length: u32);
    fn _evm_log1(data_offset: i32, data_length: u32, topic0: *const u8);
    fn _evm_log2(data_offset: i32, data_length: u32, topic0: *const u8, topic1: *const u8);
    fn _evm_log3(data_offset: i32, data_length: u32, topic0: *const u8, topic1: *const u8, topic2: *const u8);
    fn _evm_log4(data_offset: i32, data_length: u32, topic0: *const u8, topic1: *const u8, topic2: *const u8, topic3: *const u8);
    fn _evm_create(value: *const u8, bytecode_offset: *const u8, bytecode_length: u32, dest: *mut u8);
    fn _evm_call(gas: u64, address: *const u8, value: *const u8, input_offset: *const u8, input_length: u32, return_offset: *const u8, return_length: u32, dest: *mut bool);
    fn _evm_callcode(gas: u64, address: *const u8, value: *const u8, input_offset: *const u8, input_length: u32, return_offset: *const u8, return_length: u32, dest: *mut bool);
    fn _evm_delegatecall(gas: u64, address: *const u8, input_offset: *const u8, input_length: u32, return_offset: *const u8, return_length: u32, dest: *mut bool);
    fn _evm_create2(value: *const u8, bytecode_offset: *const u8, bytecode_length: u32, salt: *const u8, dest: *mut u8);
    fn _evm_staticcall(gas: u64, address: *const u8, input_offset: *const u8, input_length: u32, return_offset: *const u8, return_length: u32, dest: *mut bool);
    fn _evm_revert(error_offset: *const u8, error_length: u32);
    fn _evm_selfdestruct(beneficiary: *const u8);
}

#[inline(always)]
pub fn evm_stop() {
    unsafe {
        _evm_stop()
    }
}

#[inline(always)]
pub fn evm_return(offset: *const u8, size: u32) {
    unsafe {
        _evm_return(offset, size)
    }
}

#[inline(always)]
pub fn evm_keccak256(offset: *const u8, size: u32) -> Bytes32 {
    let mut res: Bytes32 = [0; 32];
    unsafe {
        _evm_keccak256(offset, size, res.as_mut_ptr())
    };
    res
}

#[inline(always)]
pub fn evm_address() -> Address {
    let mut res: Address = [0; 20];
    unsafe {
        _evm_address(res.as_mut_ptr())
    };
    res
}

#[inline(always)]
pub fn evm_balance(address: &Address) -> Balance {
    let mut res: Balance = [0; 32];
    unsafe {
        _evm_balance(address.as_ptr(), res.as_mut_ptr())
    };
    res
}

#[inline(always)]
pub fn evm_origin() -> Address {
    let mut res: Address = [0; 20];
    unsafe {
        _evm_origin(res.as_mut_ptr())
    };
    res
}

#[inline(always)]
pub fn evm_caller() -> Address {
    let mut res: Address = [0; 20];
    unsafe {
        _evm_caller(res.as_mut_ptr())
    };
    res
}

#[inline(always)]
pub fn evm_call_value() -> Uint256 {
    let mut bytes: [u8; 32] = [0; 32];
    unsafe {
        _evm_callvalue(bytes.as_mut_ptr())
    }
    Uint256::from_le_bytes(&bytes)
}

#[inline(always)]
pub fn evm_call_data_load(offset: u32) -> Bytes32 {
    let mut res: Bytes32 = [0; 32];
    unsafe {
        _evm_calldataload(offset, res.as_mut_ptr())
    }
    res
}

#[inline(always)]
pub fn evm_call_data_size() -> u32 {
    let mut res: u32 = 0;
    unsafe {
        _evm_calldatasize(&mut res as *mut u32)
    }
    res
}

// pub fn evm_call_data_copy(mem_offset: i32, data_offset: i32, length: u32) {
//     unsafe {
//         _evm_calldatacopy(mem_offset, data_offset, length)
//     }
// }
//
// pub fn evm_code_size() -> u32 {
//     unsafe {
//         _evm_codesize()
//     }
// }
//
// pub fn evm_code_copy(mem_offset: i32, code_offset: i32, length: u32) {
//     unsafe {
//         _evm_codecopy(mem_offset, code_offset, length)
//     }
// }
//
// pub fn evm_gas_price() -> Uint256 {
//     unsafe {
//         _evm_gasprice()
//     }
// }
//
// pub fn evm_ext_code_size(address: Address) -> u32 {
//     unsafe {
//         _evm_extcodesize(address)
//     }
// }
//
// pub fn evm_ext_code_copy(address: Address, mem_offset: i32, code_offset: i32, length: u32) {
//     unsafe {
//         _evm_extcodecopy(address, mem_offset, code_offset, length)
//     }
// }
//
// pub fn evm_ext_code_hash(address: Address) -> Bytes32 {
//     unsafe {
//         _evm_extcodehash(address)
//     }
// }

#[inline(always)]
pub fn evm_return_data_size() -> u32 {
    let mut res: u32 = 0;
    unsafe {
        _evm_returndatasize(&mut res as *mut u32)
    }
    res
}

#[inline(always)]
pub fn evm_return_data_copy(mem_offset: *const u8, data_offset: u32, length: u32) {
    unsafe {
        _evm_returndatacopy(mem_offset, data_offset, length)
    }
}

#[inline(always)]
pub fn evm_block_hash(num: u64) -> BlockHash {
    let mut res: BlockHash = [0; 32];
    unsafe {
        _evm_blockhash(num, res.as_mut_ptr())
    }
    res
}

#[inline(always)]
pub fn evm_coinbase() -> Address {
    let mut res: Address = [0; 20];
    unsafe {
        _evm_coinbase(res.as_mut_ptr())
    }
    res
}

#[inline(always)]
pub fn evm_timestamp() -> i64 {
    let mut res: i64 = 0;
    unsafe {
        _evm_timestamp(&mut res as *mut i64)
    }
    res
}

#[inline(always)]
pub fn evm_number() -> u64 {
    let mut res: u64 = 0;
    unsafe {
        _evm_number(&mut res as *mut u64)
    }
    res
}

#[inline(always)]
pub fn evm_difficulty() -> Uint256 {
    let mut bytes: [u8; 32] = [0; 32];
    unsafe {
        _evm_difficulty(bytes.as_mut_ptr())
    }
    Uint256::from_le_bytes(&bytes)
}

#[inline(always)]
pub fn evm_gas_limit() -> u64 {
    let mut res: u64 = 0;
    unsafe {
        _evm_gaslimit(&mut res as *mut u64)
    }
    res
}

#[inline(always)]
pub fn evm_chain_id() -> Uint256 {
    let mut bytes: [u8; 32] = [0; 32];
    unsafe {
        _evm_chainid(bytes.as_mut_ptr())
    }
    Uint256::from_le_bytes(&bytes)
}

#[inline(always)]
pub fn evm_base_fee() -> Uint256 {
    let mut bytes: [u8; 32] = [0; 32];
    unsafe {
        _evm_basefee(bytes.as_mut_ptr())
    }
    Uint256::from_le_bytes(&bytes)
}

#[inline(always)]
pub fn evm_storage_load(slot: &Bytes32) -> Bytes32 {
    let mut bytes: Bytes32 = [0; 32];
    unsafe {
        _evm_sload(slot.as_ptr(), bytes.as_mut_ptr())
    }
    bytes
}

#[inline(always)]
pub fn evm_storage_store(slot: &Bytes32, value: &Bytes32) {
    unsafe {
        _evm_sstore(slot.as_ptr(), value.as_ptr())
    }
}

#[inline(always)]
pub fn evm_log0(data_offset: i32, data_length: u32) {
    unsafe {
        _evm_log0(data_offset, data_length)
    }
}

// #[inline(always)]
// pub fn evm_log1(data_offset: i32, data_length: u32, topics: [Bytes32; 1]) {
//     unsafe {
//         _evm_log1(data_offset, data_length, topics)
//     }
// }

// pub fn evm_log2(data_offset: i32, data_length: u32, topics: [Bytes32; 2]) {
//     unsafe {
//         _evm_log2(data_offset, data_length, topics)
//     }
// }
//
// pub fn evm_log3(data_offset: i32, data_length: u32, topics: [Bytes32; 3]) {
//     unsafe {
//         _evm_log3(data_offset, data_length, topics)
//     }
// }
//
// pub fn evm_log4(data_offset: i32, data_length: u32, topics: [Bytes32; 4]) {
//     unsafe {
//         _evm_log4(data_offset, data_length, topics)
//     }
// }
//
// pub fn evm_create(value: Uint256, bytecode_offset: i32, bytecode_length: u32) {
//     unsafe {
//         _evm_create(value, bytecode_offset, bytecode_length)
//     }
// }
//
// pub fn evm_call(gas: u64, address: Address, value: Uint256, input_offset: i32, input_length: u32, return_offset: i32, return_length: u32) -> bool {
//     unsafe {
//         _evm_call(gas, address, value, input_offset, input_length, return_offset, return_length)
//     }
// }
//
// pub fn evm_call_code(gas: u64, address: Address, value: Uint256, input_offset: i32, input_length: u32, return_offset: i32, return_length: u32) -> bool {
//     unsafe {
//         _evm_call_code(gas, address, value, input_offset, input_length, return_offset, return_length)
//     }
// }
//
// pub fn evm_delegate_call(gas: u64, address: Address, value: Uint256, input_offset: i32, input_length: u32, return_offset: i32, return_length: u32) -> bool {
//     unsafe {
//         _evm_delegate_call(gas, address, value, input_offset, input_length, return_offset, return_length)
//     }
// }

pub fn evm_create2(value: Uint256, bytecode_offset: i32, bytecode_length: u32, salt: Bytes32) -> Address {
    let mut address: Address = [0; 20];
    unsafe {
        _evm_create2(value, bytecode_offset, bytecode_length, salt, address.as_mut_ptr());
    }
    address
}

// pub fn evm_static_call(gas: u64, address: Address, value: Uint256, input_offset: i32, input_length: u32, return_offset: i32, return_length: u32) -> bool {
//     unsafe {
//         _evm_static_call(gas, address, value, input_offset, input_length, return_offset, return_length)
//     }
// }

#[inline(always)]
pub fn evm_revert(error_offset: *const u8, error_length: u32) {
    unsafe {
        _evm_revert(error_offset, error_length)
    }
}

#[inline(always)]
pub fn evm_self_destruct(beneficiary: &Address) {
    unsafe {
        _evm_selfdestruct(beneficiary.as_ptr())
    }
}