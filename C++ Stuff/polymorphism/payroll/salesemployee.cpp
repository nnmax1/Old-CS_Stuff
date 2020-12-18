// CISC 2000   Fordham University  Fall 2019
// Instructor: Vincent Mierlak
// 
// This is the implementation for the class SalesEmployee.

#include <string>
#include <iostream>
#include "salesemployee.h"
using std::string;

SalesEmployee::SalesEmployee(string e_name, string e_ssn, 
        double e_sal, 
        double e_comm_rate) : CorporateEmployee(e_name, e_ssn, e_sal)
{ 
    commission_rate = e_comm_rate;
}

double SalesEmployee::get_commission_rate() const
{
    return commission_rate;
}

void SalesEmployee::set_commission_rate(double new_commish_rate)
{
    commission_rate = new_commish_rate;
}

void SalesEmployee::set_monthly_sales(double mo_sales)
{
    monthly_sales = mo_sales;
}

double SalesEmployee::get_total_pay() const
{
    return salary + monthly_sales * commission_rate;
}
