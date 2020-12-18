//This is the implementation for the class Employee.
//The interface for the class Employee is in the header file employee.h.

#include <string>
#include <cstdlib>
#include <iostream>
#include "employee.h"

using std::string;
using std::ostream;

Employee::Employee() : name("Default Name"), ssn("Default SSN")
{
    //deliberately empty
}

Employee::Employee(string the_name, string the_number)
    : name(the_name), ssn(the_number)
{
    //deliberately empty
}

string Employee::get_name() const
{
    return name;
}

string Employee::get_ssn() const
{
    return ssn;
}

void Employee::set_name(string new_name)
{
    name = new_name;
}

void Employee::set_ssn(string new_ssn)
{
    ssn = new_ssn;
}

double Employee::get_total_pay() const
{
    std::cout << "\nERROR: called total_pay for generic employee.\n"
              << "Aborting program." << std::endl;
    exit(1);
}


string Employee::to_string()
{
    return  "[" +  ssn + "] " + name;
}

