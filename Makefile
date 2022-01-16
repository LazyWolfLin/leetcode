.PHONY: all cpp go python rust

all: cpp go python rust

cpp:
	cd cpp && make test

go:
	cd go && make test

python:
	cd python && make test

rust:
	cd rust && cargo test
