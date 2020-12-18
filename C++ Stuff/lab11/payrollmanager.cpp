// Implementation file for PayrollManager class.
#include <iostream>
#include <iomanip>
#include <locale>
#include "payrollmanager.h"

void PayrollManager::add(Employee *new_emp)
{
    staff.push_back(new_emp);
}

void PayrollManager::generate_payroll_report()
{
    using std::cout;
    using std::endl;
    for (auto emp: staff)
    {
        cout << *emp << " Total pay: $" << std::setw(10) << std::right 
             << emp->get_total_pay() << endl;
    }

}

PayrollManager::~PayrollManager()
{
    for (auto emp: staff)
        delete emp;
}
