// CISC 2000   Fordham University   Spring 2020
// Instructor: Vincent Mierlak
//
// File name: payrolltest.cpp.
// A program to test our employee classes.

#include <iostream>
#include <iomanip>
#include <locale>
#include <vector>
#include "salesemployee.h"
#include "hourlyemployee.h"
#include "manager.h"

using std::cout;
using std::endl;
using std::vector;

int main()
{
    HourlyEmployee hrly1("Adam Driven", "444559999", 21.50, 160);
    HourlyEmployee hrly2("Minnie Castile", "555993322", 23.25, 150);

    SalesEmployee sales1("Sidney Lumint", "000441199", 2500.00, 0.1);
    sales1.set_monthly_sales(100000);
    SalesEmployee sales2("Edna Millanon", "111221199", 2500.00, 0.1);
    sales2.set_monthly_sales(150000);
    SalesEmployee sales3("Henri Frinch", "777334444", 3000.00, 0.075);
    sales3.set_monthly_sales(75000);
    SalesEmployee sales4("Maisie Krill", "888990033", 2750.00, 0.075);
    sales4.set_monthly_sales(200000);

    Manager mgr("Estelle Parsnip", "434558833", 7600, 525000 * .015);

    // Some formatting code
    cout.setf(std::ios::fixed);
    cout.setf(std::ios::showpoint);
    cout.precision(2);
    cout.imbue(std::locale(""));
    cout << "NYC Division -- Payroll Test:" << endl;

//--------------------------------------------------------------------------
    // Generate the payroll report.
    // Version 1: the non-polymorphic way.
    // Create a vector for each derived class
/*
    vector<HourlyEmployee> hrly_staff;
    hrly_staff.push_back(hrly1);
    hrly_staff.push_back(hrly2);

    vector<SalesEmployee> sales_staff;
    sales_staff.push_back(sales1);
    sales_staff.push_back(sales2);
    sales_staff.push_back(sales3);
    sales_staff.push_back(sales4);

    for (auto hrlyemp : hrly_staff)
        cout << std::setw(30) << std::left << hrlyemp.to_string() 
             << " Total pay: $" << std::setw(10) << std::right 
             << hrlyemp.get_total_pay() << endl;

    for (auto salesemp : sales_staff)
        cout << std::setw(30) << std::left << salesemp.to_string()
             << " Total pay: $" << std::setw(10) << std::right
             << salesemp.get_total_pay() << endl;

    cout << std::setw(30) << std::left << mgr.to_string() 
         << " Total pay: $" << std::setw(10) << std::right 
         << mgr.get_total_pay() << endl;
*/

//----------------------------------------------------------------------------
    // Generate the payroll report.
    // Version 2: create a vector of Employee objects, and see what happens
    // when we call get_total_pay().

/*
    vector<Employee> staff;
    staff.push_back(hrly1);
    staff.push_back(hrly2);
    staff.push_back(sales1);
    staff.push_back(sales2);
    staff.push_back(sales3);
    staff.push_back(sales4);
    staff.push_back(mgr);

    for (auto emp : staff)
        cout << std::setw(30) << std::left << emp.to_string() 
             << " Total pay: $" << std::setw(10) << std::right 
             << emp.get_total_pay() << endl;
*/

//---------------------------------------------------------------------------
    // Generate the payroll report
    // Version 3: use polymorphism.
    // Create a vector of pointers to Employee objects instead:
    // when we call get_total_pay(), pointers make late binding possible, and
    // we call the respective get_total_pay() functions for each derived class


    vector<Employee*> staff;
    staff.push_back(&hrly1);
    staff.push_back(&hrly2);
    staff.push_back(&sales1);
    staff.push_back(&sales2);
    staff.push_back(&sales3);
    staff.push_back(&sales4);
    staff.push_back(&mgr);

    // Our single for-loop works correctly for ALL employees because
    // of polymorphism.
    for (auto emp : staff)
        cout << std::setw(30) << std::left << emp->to_string() 
             << " Total pay: $" << std::setw(10) << std::right 
             << emp->get_total_pay() << endl;



    return 0;
}
