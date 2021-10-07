.PHONY: all init cpp go python rust

all: cpp go python rust

init:
	git submodule init
	git submodule update

cpp:
	mkdir -p build && cmake -S cpp -B build && cd build && make && ctest

go:
	cd go && make

python:
	cd python && make

rust:
	cd rust && cargo test
