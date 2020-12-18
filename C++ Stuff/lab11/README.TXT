Lab 11: Polymorphism
In this lab, we will take advantage of polymorphism to implement a payroll manager program.

TODO:

To get started, use the following command to copy the lab11 directory into your cs2 working directory:
cp -r /u/erdos/mierlak/Public/cs2/lab11 .
Create a PayrollManager class, whose job it is to manage the payroll for a division of a company.
The PayrollManager class has 1 private member named staff, which is a vector of pointers to the type Employee:
vector<Employee*> staff;
The PayrollManager class has the following member functions:
a default constructor (which does not need to do anything)
a destructor that will call delete for each Employee in the vector staff
void generate_payroll_report(): this function generates the payroll report for the entire staff. For each Employee in the vector staff, call the member function get_total_pay()
void add(Employee *new_emp) which takes a pointer to an Employee object and pushes new_emp back to the vector staff
Put the class definition for PayrollManager in the header file payrollmanager.h and the implementation in the file payrollmanager.cpp. 
Compile the program by entering the command make.  To get rid of unwanted files, type make clean.
The executable file is called payroll.out.  The output is saved in the file output_lab11.txt.
Use valgrind to check for memory leaks:
valgrind --leak-check=full ./payroll.out
Note: valgrind may report that you still have reachable blocks; this is OK as long as the ERROR SUMMARY reports 0 errors from 0 contexts.
WHAT TO SUBMIT:

Submit payrollmanager.h and payrollmanager.cpp by Thursday 4/23 by 11:59 PM EDT:

/u/erdos/mierlak/bin/submitlab.sh payrollmanager.h payrollmanager.cpp

Polymorphism in the PayrollManager Class.

The PayrollManager class uses a vector of pointers to generic Employee types.  This allows us to add employees using derived types of the Employee class.  In the program payrolltest.cpp, we create a PayrollManager object and add HourlyEmployees and a Manager.  When we add these objects, we call new to dynamically create the appropriate type of employee object.   

Polymorphism comes into play when we generate the entire payroll report with the call to the member function generate_payroll_report.  In this function, we can iterate over the entire vector staff and call get_total_pay() for each employee.  By virtue of polymorphism, the correct version of get_total_pay() will be called based on the type of the calling object.

Because you are calling new for each employee, the destructor for PayrollManager must call delete in an appropriate manner. 

Using Pointers With Objects.

When you have a pointer to an object of class type, you cannot use the dot operator to access members; instead, you must use the -> (arrow) operator.  For example, if you use new to create an HourlyEmployee, 

HourlyEmployee hrlyemp = new HourlyEmployee();

then you would access member functions like this:

hrlyemp->get_total_pay().