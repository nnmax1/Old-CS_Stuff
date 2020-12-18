
// Lab 10. Inheritance.
// 
// This program tests the NonexemptEmployee class, which is derived from
// the HourlyEmployee class.  A non-exempt employee is an hourly employee
// that gets paid 1.5 times their hourly rate for every hour worked over
// 40 hours per week.

#include <iostream>
#include <iomanip>
#include <locale>
#include <vector>
#include "hourlyemployee.h"
#include "nonexemptemployee.h"

using std::cout;
using std::endl;
using std::vector;

int main()
{
    HourlyEmployee hrly1("Adam Driven", "444559999", 21.50, 45);
    HourlyEmployee hrly2("Minnie Castile", "555993322", 33.25, 42);
    HourlyEmployee hrly3("Brat Pittman", "666555991", 15.00, 55);

    vector<HourlyEmployee> hrly_staff;
    hrly_staff.push_back(hrly1);
    hrly_staff.push_back(hrly2);
    hrly_staff.push_back(hrly3);

    NonexemptEmployee nonxmpt1("Danny Kreeg", "000123211", 21.50, 45);
    NonexemptEmployee nonxmpt2("Sasha Cone", "000456654", 33.25, 42);
    NonexemptEmployee nonxmpt3("Andie Newmin", "000789987", 15.00, 55);

    vector<NonexemptEmployee> nonxmpt_staff;
    nonxmpt_staff.push_back(nonxmpt1);
    nonxmpt_staff.push_back(nonxmpt2);
    nonxmpt_staff.push_back(nonxmpt3);

    cout.setf(std::ios::fixed);
    cout.setf(std::ios::showpoint);
    cout.precision(2);
    cout.imbue(std::locale(""));
    cout << "NYC Division -- Payroll Test:" << endl;

    for (auto hrlyemp : hrly_staff)
        cout <<  hrlyemp << " Total pay: $" 
             << std::setw(10) << std::right 
             << hrlyemp.get_total_pay() << endl;

    for (auto nonexmptemp : nonxmpt_staff)
        cout << nonexmptemp << " Total pay: $" 
             << std::setw(10) << std::right
             << nonexmptemp.get_total_pay() << endl;

    return 0;
}
