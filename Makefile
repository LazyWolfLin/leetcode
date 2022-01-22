.PHONY: all cpp go python rust

all: cpp go python rust

cpp:
	bazel run cpp:solutions_test

go:
	cd go && make test

python:
	cd python && make test

rust:
	bazel run rust:solutions_test
