.PHONY: test

build: src/solutions/*
	mkdir -p build && cd build && cmake .. && make -j 4

test: build
	cd build && ctest