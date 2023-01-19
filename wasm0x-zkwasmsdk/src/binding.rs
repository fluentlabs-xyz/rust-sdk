use crate::types::{Address};

// stack virtual machine
// stack depth = 16 items, item size = 32 bytes

// address -> push32(address)

//

extern {
    fn _evm_stop();
    fn _evm_keccak256(offset: *const u8, size: u32, dest: *mut u8);
    fn _evm_address(dest: *mut u8);
    fn _evm_balance(address: *const u8, dest: *mut u8);
    fn _evm_origin(dest: *mut u8);
    fn _evm_caller(dest: *mut u8);

    // fn _evm_call_value() -> Uint256;
    // fn _evm_call_data_load(offset: i32) -> Bytes32;
    // fn _evm_call_data_size() -> u32;
    // fn _evm_call_data_copy(mem_offset: i32, data_offset: i32, length: u32);
    // fn _evm_code_size() -> u32;
    // fn _evm_code_copy(mem_offset: i32, code_offset: i32, length: u32);
    // fn _evm_gas_price() -> Uint256;
    // fn _evm_ext_code_size(address: Address) -> u32;
    // fn _evm_ext_code_copy(address: Address, mem_offset: i32, code_offset: i32, length: u32);
    // fn _evm_ext_code_hash(address: Address) -> Bytes32;

    fn _evm_return_data_size() -> u32;
    fn _evm_return_data_copy(mem_offset: i32, data_offset: i32, length: u32);

    // fn _evm_block_hash(num: u64) -> BlockHash;
    // fn _evm_coinbase() -> Address;
    // fn _evm_timestamp() -> u64;
    // fn _evm_number() -> u64;
    // fn _evm_difficulty() -> Uint256;
    // fn _evm_random() -> Bytes32;
    // fn _evm_gas_limit() -> u64;
    // fn _evm_chain_id() -> Uint256;
    // fn _evm_self_balance() -> Uint256;
    // fn _evm_base_fee() -> u64;
    // fn _evm_storage_load(slot: Bytes32) -> Bytes32;
    // fn _evm_storage_store(slot: Bytes32, value: Bytes32);
    // fn _evm_log0(data_offset: i32, data_length: u32);
    // fn _evm_log1(data_offset: i32, data_length: u32, topics: [Bytes32; 1]);
    // fn _evm_log2(data_offset: i32, data_length: u32, topics: [Bytes32; 2]);
    // fn _evm_log3(data_offset: i32, data_length: u32, topics: [Bytes32; 3]);
    // fn _evm_log4(data_offset: i32, data_length: u32, topics: [Bytes32; 4]);
    // fn _evm_create(value: Uint256, bytecode_offset: i32, bytecode_length: u32);
    // fn _evm_call(gas: u64, address: Address, value: Uint256, input_offset: i32, input_length: u32, return_offset: i32, return_length: u32) -> bool;
    // fn _evm_call_code(gas: u64, address: Address, value: Uint256, input_offset: i32, input_length: u32, return_offset: i32, return_length: u32) -> bool;
    // fn _evm_delegate_call(gas: u64, address: Address, value: Uint256, input_offset: i32, input_length: u32, return_offset: i32, return_length: u32) -> bool;
    // fn _evm_create2(value: Uint256, bytecode_offset: i32, bytecode_length: u32, salt: Bytes32) -> Address;
    // fn _evm_static_call(gas: u64, address: Address, value: Uint256, input_offset: i32, input_length: u32, return_offset: i32, return_length: u32) -> bool;
    // fn _evm_revert(error_offset: i32, error_length: u32);
    // fn _evm_self_destruct(beneficiary: Address);
}

#[inline(always)]
pub fn evm_stop() {
    unsafe {
        _evm_stop()
    }
}

// pub fn evm_keccak256(offset: *const u8, size: u32) -> Bytes32 {
//     let ptr = unsafe {
//         _evm_keccak256(offset, size)
//     };
//     ptr_to_slice(ptr)
// }

#[inline(always)]
pub fn evm_address() -> Address {
    let mut res: Address = [0; 20];
    unsafe {
        _evm_address(res.as_mut_ptr())
    };
    res
}

// pub fn evm_balance(address: Address) -> Uint256 {
//     let ptr = unsafe {
//         _evm_balance(address.as_ptr())
//     };
//     ptr_to_slice(ptr)
// }
//
// pub fn evm_origin() -> Address {
//     let ptr = unsafe {
//         _evm_origin()
//     };
//     ptr_to_slice(ptr)
// }
//
// pub fn evm_caller() -> Address {
//     let ptr = unsafe {
//         _evm_caller()
//     };
//     ptr_to_slice(ptr)
// }

// pub fn evm_call_value() -> Uint256 {
//     unsafe {
//         _evm_call_value()
//     }
// }
//
// pub fn evm_call_data_load(offset: i32) -> Bytes32 {
//     unsafe {
//         _evm_call_data_load(offset)
//     }
// }
//
// pub fn evm_call_data_size() -> u32 {
//     unsafe {
//         _evm_call_data_size()
//     }
// }
//
// pub fn evm_call_data_copy(mem_offset: i32, data_offset: i32, length: u32) {
//     unsafe {
//         _evm_call_data_copy(mem_offset, data_offset, length)
//     }
// }
//
// pub fn evm_code_size() -> u32 {
//     unsafe {
//         _evm_code_size()
//     }
// }
//
// pub fn evm_code_copy(mem_offset: i32, code_offset: i32, length: u32) {
//     unsafe {
//         _evm_code_copy(mem_offset, code_offset, length)
//     }
// }
//
// pub fn evm_gas_price() -> Uint256 {
//     unsafe {
//         _evm_gas_price()
//     }
// }
//
// pub fn evm_ext_code_size(address: Address) -> u32 {
//     unsafe {
//         _evm_ext_code_size(address)
//     }
// }
//
// pub fn evm_ext_code_copy(address: Address, mem_offset: i32, code_offset: i32, length: u32) {
//     unsafe {
//         _evm_ext_code_copy(address, mem_offset, code_offset, length)
//     }
// }
//
// pub fn evm_ext_code_hash(address: Address) -> Bytes32 {
//     unsafe {
//         _evm_ext_code_hash(address)
//     }
// }

#[inline(always)]
pub fn evm_return_data_size() -> u32 {
    unsafe {
        _evm_return_data_size()
    }
}

#[inline(always)]
pub fn evm_return_data_copy(mem_offset: *const u8, data_offset: i32, length: u32) {
    unsafe {
        _evm_return_data_copy(mem_offset as i32, data_offset, length)
    }
}

// pub fn evm_block_hash(num: u64) -> BlockHash {
//     unsafe {
//         _evm_block_hash(num)
//     }
// }
//
// pub fn evm_coinbase() -> Address {
//     unsafe {
//         _evm_coinbase()
//     }
// }
//
// pub fn evm_timestamp() -> u64 {
//     unsafe {
//         _evm_timestamp()
//     }
// }
//
// pub fn evm_number() -> u64 {
//     unsafe {
//         _evm_number()
//     }
// }
//
// pub fn evm_difficulty() -> Uint256 {
//     unsafe {
//         _evm_difficulty()
//     }
// }
//
// pub fn evm_random() -> Bytes32 {
//     unsafe {
//         _evm_random()
//     }
// }
//
// pub fn evm_gas_limit() -> u64 {
//     unsafe {
//         _evm_gas_limit()
//     }
// }
//
// pub fn evm_chain_id() -> Uint256 {
//     unsafe {
//         _evm_chain_id()
//     }
// }
//
// pub fn evm_self_balance() -> Uint256 {
//     unsafe {
//         _evm_self_balance()
//     }
// }
//
// pub fn evm_base_fee() -> u64 {
//     unsafe {
//         _evm_base_fee()
//     }
// }
//
// pub fn evm_storage_load(slot: Bytes32) -> Bytes32 {
//     unsafe {
//         _evm_storage_load(slot)
//     }
// }
//
// pub fn evm_storage_store(slot: Bytes32, value: Bytes32) {
//     unsafe {
//         _evm_storage_store(slot, value)
//     }
// }
//
// pub fn evm_log0(data_offset: i32, data_length: u32) {
//     unsafe {
//         _evm_log0(data_offset, data_length)
//     }
// }
//
// pub fn evm_log1(data_offset: i32, data_length: u32, topics: [Bytes32; 1]) {
//     unsafe {
//         _evm_log1(data_offset, data_length, topics)
//     }
// }
//
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
//
// pub fn evm_create2(value: Uint256, bytecode_offset: i32, bytecode_length: u32, salt: Bytes32) -> Address {
//     unsafe {
//         _evm_create2(value, bytecode_offset, bytecode_length, salt)
//     }
// }
//
// pub fn evm_static_call(gas: u64, address: Address, value: Uint256, input_offset: i32, input_length: u32, return_offset: i32, return_length: u32) -> bool {
//     unsafe {
//         _evm_static_call(gas, address, value, input_offset, input_length, return_offset, return_length)
//     }
// }
//
// pub fn evm_revert(error_offset: i32, error_length: u32) {
//     unsafe {
//         _evm_revert(error_offset, error_length)
//     }
// }
//
// pub fn evm_self_destruct(beneficiary: Address) {
//     unsafe {
//         _evm_self_destruct(beneficiary)
//     }
// }