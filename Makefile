.PHONY: test

test:
	mkdir -p build && cmake -S cpp -B build && cd build && ctest
	cd go && make
	cd python && make
	cd rust && cargo test