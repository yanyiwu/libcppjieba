CXX ?= g++
CXXSTD ?= -std=c++11
CXXFLAGS ?= -O3 -DLOGGER_LEVEL=LL_WARN -Wall -g

.PHONY: all test clean

all: demo

demo: demo.cpp
	$(CXX) $(CXXSTD) $(CXXFLAGS) -o $@ $<

tests/baseline_test: tests/baseline_test.cpp
	$(CXX) $(CXXSTD) $(CXXFLAGS) -I. -o $@ $<

test: tests/baseline_test
	./tests/baseline_test

clean:
	rm -f *.o *.a demo tests/baseline_test
