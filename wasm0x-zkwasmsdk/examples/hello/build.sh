#!/bin/bash

# required:
#  rust wasm32 target installed, command: rustup target add wasm32-unknown-unknown
#  WebAssembly Binary Toolkit ('wasm2wat' command), resource: https://github.com/WebAssembly/wabt

BUILD_TARGET=wasm32-unknown-unknown
TARGET_FOLDER=target/$BUILD_TARGET/release
cargo build --target=$BUILD_TARGET --release
(cd $TARGET_FOLDER && wasm2wat hello.wasm > hello.wat)

echo "result 'hello.wasm' and 'hello.wat' files are here: $TARGET_FOLDER"