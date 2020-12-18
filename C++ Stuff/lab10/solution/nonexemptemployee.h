
// Header file nonexemptemployee.h.
// This is the interface for the class NonexemptEmployee.
// NonexemptEmployees are HourlyEmployees who are eligible for overtime pay.

#ifndef _NONEXEMPTYEMPLOYEE_H_
#define _NONEXEMPTEMPLOYEE_H_

#include <string>
#include "hourlyemployee.h"

class NonexemptEmployee: public HourlyEmployee
{
    public:
        NonexemptEmployee() : HourlyEmployee() { }
        NonexemptEmployee(string e_name, string e_ssn, 
                double e_hourly_rate, double e_hours) : HourlyEmployee(e_name, 
                   e_ssn, e_hourly_rate, e_hours) { }
        
        double get_total_pay() const;
};

#endif //_NONEXEMPTEMPLOYEE_H_
