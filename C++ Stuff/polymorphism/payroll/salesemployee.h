// CISC 2000   Fordham University  Spring 2020
// Instructor: Vincent Mierlak
// 
// Header file salesemployee.h.
// 
// This is the interface for the class SalesEmployee.
// SalesEmployees receive a monthly salary PLUS a commission based on
// their total monthly sales.

#ifndef SALES_EMPLOYEE_H
#define SALES_EMPLOYEE_H

#include <string>
#include "corpemployee.h"
using std::string;

class SalesEmployee: public CorporateEmployee
{
    public:
        SalesEmployee() : CorporateEmployee() { }
        SalesEmployee(string e_name, string e_ssn, double e_sal,
                      double e_comm_rate);
        
        virtual double get_total_pay() const;

        double get_commission_rate() const;
        void set_commission_rate(double new_commish_rate);
        void set_monthly_sales(double mo_sales);

    private:
        double commission_rate = 0.0;
        double monthly_sales;
};

#endif //_SALES_EMPLOYEE_H_
