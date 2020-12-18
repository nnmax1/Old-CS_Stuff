# Program for compiling C++ programs
CXX = g++

# Extra flags to give to the compiler
CXXFLAGS = -g -Wall

# make compiles with an implicit rule:
# $(CXX) -c $(CXXFLAGS) <the .cpp file> 

employee.out: main.o employee.o hourlyemployee.o salariedemployee.o
	$(CXX) $(CXXFLAGS) main.o employee.o hourlyemployee.o salariedemployee.o -o employee.out

main.o: main.cpp hourlyemployee.h salariedemployee.h

employee.o: employee.cpp employee.h

hourlyemployee.o: hourlyemployee.cpp hourlyemployee.h employee.h

salariedemployee.o: salariedemployee.cpp salariedemployee.h employee.h

.PHONY: clean
clean:
	rm -f *.o core

.PHONY: clobber
clobber: clean
	rm -f *.out

.PHONY: all
all: clobber employee.out

