
// This is the implementation for the class NonexemptEmployee.

#include "nonexemptemployee.h"

double NonexemptEmployee::get_total_pay() const
{
    double pay = 0.0;
    if (hours > 40)
        pay = hourly_rate * 40 + 1.5 * hourly_rate * (hours - 40);
    else
        pay = hourly_rate * hours;
    return pay;
}

