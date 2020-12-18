# Program for compiling C++ programs
CXX = g++

# Extra flags to give to the compiler
CXXFLAGS = -g -Wall

# make compiles with an implicit rule:
# $(CXX) -c $(CXXFLAGS) <the .cpp file> 

polydemo.out: main.o germanshepherd.o chihuahua.o dog.o
	$(CXX) $(CXXFLAGS) main.o germanshepherd.o chihuahua.o dog.o -o polydemo.out

main.o: main.cpp germanshepherd.h chihuahua.h dog.h

germanshepherd.o: germanshepherd.cpp germanshepherd.h dog.h

chihuahua.o: chihuahua.cpp chihuahua.h dog.h

dog.o:	dog.cpp dog.h

.PHONY: clean
clean:
	rm -f *.o core

.PHONY: clobber
clobber: clean
	rm -f *.out

.PHONY: all
all: clobber polydemo.out

