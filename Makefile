.PHONY: all cpp go python rust

all: cpp go python rust

cpp:
	bazel run cpp:solutions_test

go:
	bazel run go:solutions_test

python:
	bazel run python:solutions_test

rust:
	bazel run rust:solutions_test
