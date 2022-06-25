.PHONY: build
.PHONY: test

build: build@Debug
	@if [ ! -f compile_commands.json ]; then \
  	ln -s build/Debug/compile_commands.json compile_commands.json; \
	fi;

build@%: configure@%
	@cmake --build build/$*

run@%: build@Debug
	@build/Debug/examples/$*_example

configure@%:
	@cmake -S . -B build/$* -DCMAKE_BUILD_TYPE=$*

test: test@Debug
	@#

test@%: build@%
	@echo ""
	@cd build/$* && ctest

bm@%: build@Release
	@sudo cpupower frequency-set --governor performance > /dev/null
	@build/Release/benchmarks/$*_bm
	@sudo cpupower frequency-set --governor powersave > /dev/null

clean:
	@rm -rf build
	@rm -f compile_commands.json

clean@%:
	@rm -rf build/$*
