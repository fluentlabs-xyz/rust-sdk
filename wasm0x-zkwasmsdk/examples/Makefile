
.PHONY: examples
examples:
	mkdir -p ./bin/
	cargo build --manifest-path=./deploy/Cargo.toml --release --target=wasm32-unknown-unknown
	cp ./deploy/target/wasm32-unknown-unknown/release/deploy.wasm ./bin/deploy.wasm
	wasm2wat ./bin/deploy.wasm > ./bin/deploy.wat
	wat2wasm ./bin/deploy.wat
	mv deploy.wasm ./bin/deploy.wasm
	cargo build --manifest-path=./hello/Cargo.toml --release --target=wasm32-unknown-unknown
	cp ./hello/target/wasm32-unknown-unknown/release/hello.wasm ./bin/hello.wasm
	wasm2wat ./bin/hello.wasm > ./bin/hello.wat
	wat2wasm ./bin/hello.wat
	mv hello.wasm ./bin/hello.wasm