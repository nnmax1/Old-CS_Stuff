// CISC 2000   Fordham University  Spring 2020
// Instructor: Vincent Mierlak
// 
// Header file payrollmanager.h.
// 
// This is the interface for the class PayrollManager.

#ifndef _PAYROLLMANAGER_H_
#define _PAYROLLMANAGER_H_

#include <iostream>
#include <vector>
#include "employee.h"
#include "hourlyemployee.h"
#include "manager.h"

class PayrollManager {
    public:
        PayrollManager() { };
        ~PayrollManager();

        void generate_payroll_report();
        void add(Employee *new_emp);
        
    private:
        std::vector<Employee*> staff;
};

#endif // _PAYROLLMANAGER_H_
