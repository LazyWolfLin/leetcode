.PHONY: all clean test cpp go python rust

all: clean test

clean:
	bazel clean

test:
	bazel test ...

cpp: clean
	bazel test cpp:solutions_test

go: clean
	bazel test go:solutions_test

python: clean
	bazel test python:solutions_test

rust: clean
	bazel test rust:solutions_test
