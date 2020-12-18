# Program for compiling C++ programs
CXX = g++

# Extra flags to give to the compiler
CXXFLAGS = -g -Wall

# make compiles with an implicit rule:
# $(CXX) -c $(CXXFLAGS) <the .cpp file> 

money.out: money_main.o money.o
	$(CXX) $(CXXFLAGS) money_main.o money.o -o money.out

money_main.o: money_main.cpp money.h

money.o: money.cpp money.h

.PHONY: clean
clean:
	rm -f *.o core

.PHONY: clobber
clobber: clean
	rm -f *.out

.PHONY: all
all: clobber money.out

