.PHONY: test

build: src/solutions/*
	mkdir -p build && cd build && cmake .. && make

test: build
	cd build && ctest