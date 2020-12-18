# Program for compiling C++ programs
CXX = g++

# Extra flags to give to the compiler
CXXFLAGS = -Wall

# Extra flags to give to compilers when they are supposed to invoke the linker,
# ld, such as -L.
# instead
LDFLAGS =

# Library flags or names given to compilers when they are supposed to invoke
# the linker, ld.  Non-library linker flags, such as -L, should go in the
# LDFLAGS variable
LDLIBS =

# make compiles with an implicit rule:
# $(CXX) -c $(CXXFLAGS) <the .cpp file> 

OBJECTS = main.o nonexemptemployee.o hourlyemployee.o employee.o

main.out: $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o main.out $(LDLIBS)

main.o:	main.cpp hourlyemployee.h nonexemptemployee.h employee.h

nonexemptemployee.o: nonexemptemployee.cpp nonexemptemployee.h hourlyemployee.h employee.h

hourlyemployee.o: hourlyemployee.cpp hourlyemployee.h employee.h

employee.o: employee.cpp employee.h

.PHONY: clean
clean:
	rm -f *.o core *.out

.PHONY: all
all: clean main.out

