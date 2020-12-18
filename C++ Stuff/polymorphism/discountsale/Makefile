# Program for compiling C++ programs
CXX = g++

# Extra flags to give to the compiler
CXXFLAGS = -g -Wall

# make compiles with an implicit rule:
# $(CXX) -c $(CXXFLAGS) <the .cpp file> 

.PHONY: default
default: test.out

test.out: main.o sale.o discountsale.o
	$(CXX) $(CXXFLAGS) main.o sale.o discountsale.o -o test.out

main.o: main.cpp sale.h discountsale.h

sale.o: sale.cpp sale.h

discountsale.o: discountsale.cpp discountsale.h sale.h

.PHONY: clean
clean:
	rm -f *.o core

.PHONY: clobber
clobber: clean
	rm -f *.out

.PHONY: all
all: clobber test.out

