
.PHONY: examples math

examples:
	rm -rf ./deploy/target ./greeting/target ./hello/target
	rm -rf ./bin
	mkdir -p ./bin
	sleep 1
	# hello
	#	cargo build --manifest-path=./hello/Cargo.toml --release --target=wasm32-unknown-unknown
	#	cp ./hello/target/wasm32-unknown-unknown/release/hello.wasm ./bin/hello.wasm
	#	wasm2wat ./bin/hello.wasm > ./bin/hello.wat
	#	wat2wasm ./bin/hello.wat
	#	mv hello.wasm ./bin/hello.wasm
	#	xxd -p ./bin/hello.wasm | tr -d '\n' > ./bin/hello.hex
	# greeting
	cargo build --manifest-path=./greeting/Cargo.toml --release --target=wasm32-unknown-unknown
	cp ./greeting/target/wasm32-unknown-unknown/release/greeting.wasm ./bin/greeting.wasm
	wasm2wat ./bin/greeting.wasm > ./bin/greeting.wat
	wat2wasm ./bin/greeting.wat
	mv greeting.wasm ./bin/greeting.wasm
	xxd -p ./bin/greeting.wasm | tr -d '\n' > ./bin/greeting.hex
	# deploy
	cargo build --manifest-path=./deploy/Cargo.toml --release --target=wasm32-unknown-unknown
	cp ./deploy/target/wasm32-unknown-unknown/release/deploy.wasm ./bin/deploy.wasm
	wasm2wat ./bin/deploy.wasm > ./bin/deploy.wat
	wat2wasm ./bin/deploy.wat
	mv deploy.wasm ./bin/deploy.wasm
	xxd -p ./bin/deploy.wasm | tr -d '\n' > ./bin/deploy.hex

math:
	cargo build --manifest-path=./math/Cargo.toml --release --target=wasm32-unknown-unknown
	cp ./math/target/wasm32-unknown-unknown/release/math.wasm ./bin/math.wasm
	wasm2wat ./bin/math.wasm > ./bin/math.wat
	wat2wasm ./bin/math.wat
	mv math.wasm ./bin/math.wasm
	xxd -p ./bin/math.wasm | tr -d '\n' > ./bin/math.hex