#!/bin/bash
set -e
[[ ! "$1" ]] && echo "specify valid contract C++ file as first argument" && exit
[[ ! "$2" ]] && echo "specify WASM output file as second argument" && exit
if [[ "$(command -v python3)" == ""  ]]; then
    echo "no python3", exit
fi
if [[ "$(command -v pip3)" == ""  ]]; then
    echo "no pip", exit
fi

TMP_FILE=/tmp/_$(date +%s%N)_$1
if [[ -e ${TMP_FILE} ]]; then
  echo "you can't compile two C++ files in one nanosecond", exit
fi

if [[ ! -d ./venv ]]; then
  echo "creating venv (subsequent builds might be faster)..."
  python3 -m venv ./venv
  source ./venv/bin/activate
  pip3 uninstall sha3 || true
  pip3 install pysha3
  echo "venv created"
else
  source ./venv/bin/activate
fi
python3 abi_gen.py $1 ${TMP_FILE}
deactivate

clang++ -mllvm -inline-threshold=1000000000 \
    --sysroot=./wasi-sdk-19.0/share/wasi-sysroot \
    -I.. \
    -L./wasi-sdk-19.0/lib/ckang/15.0.7/lib/wasi \
    -O3 \
    -nostartfiles \
    --target=wasm32-wasi \
    -Wl,--allow-undefined-file=export.syms,--demangle,--no-entry,--export=start \
    -fno-exceptions \
    -fno-rtti \
    -std=c++17 \
    -fvisibility=hidden \
    -fno-threadsafe-statics \
    ${TMP_FILE} -o $2

#cat ${TMP_FILE}
rm -f ${TMP_FILE}

wasm2wat $2 > token.wat
wasm2c $2 > token.c

xxd -p $2 | tr -d '\n'
echo ''
