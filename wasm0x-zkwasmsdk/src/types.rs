use fixed_bigint::{FixedUInt};

pub type Bytes8 = [u8; 8];
pub type Bytes32 = [u8; 32];
pub type Bytes20 = [u8; 20];

pub type Uint128 = FixedUInt<u8, 16>;
pub type Int128 = FixedUInt<u8, 16>; // TODO: "add int128 support"
pub type Uint256 = FixedUInt<u8, 32>;
pub type Int256 = FixedUInt<u8, 32>; // TODO: "add int256 support"

pub type BlockHash = Bytes32;
pub type Address = Bytes20;
pub type Balance = Bytes32;
