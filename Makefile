.PHONY: all init cpp go python rust

all: cpp go python rust

init:
	git submodule init
	git submodule update

cpp:
	cd cpp && make test

go:
	cd go && make test

python:
	cd python && make test

rust:
	cd rust && cargo test
