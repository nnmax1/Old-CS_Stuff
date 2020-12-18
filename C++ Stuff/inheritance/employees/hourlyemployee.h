//DISPLAY 15.5 Interface for the Derived Class HourlyEmployee
//This is the header file hourlyemployee.h.
//This is the interface for the class HourlyEmployee.
#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H

#include <string>
#include "employee.h"


class HourlyEmployee : public Employee
{
    public:
        HourlyEmployee( );
        HourlyEmployee(string theName, string theSSN,
                double theWageRate, double theHours);
        void setRate(double newWageRate);
        double getRate( ) const;
        void setHours(double hoursWorked);
        double getHours( ) const;
        void printCheck( ) ;
    private:
        double wageRate;
        double hours;
};


#endif //HOURLYMPLOYEE_H
