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

OBJECTS = payrolltest.o hourlyemployee.o salesemployee.o manager.o corpemployee.o employee.o

payroll.out: $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o payroll.out $(LDLIBS)

payrolltest.o: payrolltest.cpp hourlyemployee.h salesemployee.h manager.h

hourlyemployee.o: hourlyemployee.cpp hourlyemployee.h employee.h

salesemployee.o: salesemployee.cpp salesemployee.h corpemployee.h employee.h

manager.o: manager.cpp manager.h corpemployee.h employee.h

corpemployee.o: corpemployee.cpp corpemployee.h employee.h

employee.o: employee.cpp employee.h

.PHONY: clean
clean:
	rm -f *.o core *.out

.PHONY: all
all: clean payroll.out

