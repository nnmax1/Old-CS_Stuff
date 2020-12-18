// CISC 2000   Fordham University  Spring 2020
// Instructor: Vincent Mierlak
// 
// Header file employee.h.
// 
// This is the interface for the class Employee.
// This is primarily intended to be used as a base class from which we
// can derive classes for different kinds of employees.

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using std::string;

class Employee
{
    public:
        Employee();
        Employee(string the_name, string the_ssn);
        string get_name() const;
        string get_ssn() const;
        
        // This virtual function will be overridden in derived classes
        virtual double get_total_pay() const;

        void set_name(string new_name);
        void set_ssn(string new_ssn);
        string to_string();

    private:
        string name;
        string ssn;
};

#endif //EMPLOYEE_H
