// CISC 2000   Fordham University  Spring 2020
// Instructor: Vincent Mierlak
// 
// Header file corpemployee.h.
//
// This is the interface for the class CorporateEmployee.
// Corporate Employees receive a monthly salary.

#ifndef CORPEMPLOYEE_H
#define CORPEMPLOYEE_H

#include <string>
#include "employee.h"
using std::string;

class CorporateEmployee : public Employee
{
    public:
        CorporateEmployee() : Employee() { }
        CorporateEmployee(string e_name, string e_ssn) : Employee(e_name, e_ssn) { }
        CorporateEmployee(string e_name, string e_ssn, double e_sal);
        
        virtual double get_total_pay() const;

        double get_salary() const;
        void set_salary(double new_sal);

    protected:
        double salary;
};

#endif //_CORPEMPLOYEE_H_
