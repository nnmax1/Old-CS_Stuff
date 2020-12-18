#include <iostream>
#include "savingsaccount.h"
using namespace std;

int main()
{
    SavingsAccount account; // calls default BankAccount() constructor
    account.output(cout);  // output defined in BankAccount class
    cout << endl;

    account.set_rate(5);  // set the rate to 5.0% interest per year

    cout << "Depositing $100.00." << endl;
    account.deposit(100,0);
    account.output(cout);
    cout << endl;

    // Update the interest
    account.update();
    cout << "After 1 year of interest:\n";
    account.output(cout);
    cout << endl;

    cout << "Withdrawing $25.10." << endl;
    account.withdraw(25,10);
    account.output(cout);
    cout << endl;

    return 0;
}

