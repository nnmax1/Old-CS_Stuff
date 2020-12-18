# Program for compiling C++ programs
CXX = g++

# Extra flags to give to the compiler
CXXFLAGS = -g -Wall

# make compiles with an implicit rule:
# $(CXX) -c $(CXXFLAGS) <the .cpp file> 

.PHONY: default
default: acct.out

acct.out: main.o bankaccount.o savingsaccount.o
	$(CXX) $(CXXFLAGS) main.o bankaccount.o savingsaccount.o -o acct.out

main.o: main.cpp bankaccount.h savingsaccount.h

bankaccount.o: bankaccount.cpp bankaccount.h

savingsaccount.o: savingsaccount.cpp bankaccount.h savingsaccount.h

.PHONY: clean
clean:
	rm -f *.o core

.PHONY: clobber
clobber: clean
	rm -f *.out

.PHONY: all
all: clobber acct.out

