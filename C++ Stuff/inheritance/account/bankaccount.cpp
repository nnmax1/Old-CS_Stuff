#include <iostream>
#include "bankaccount.h"

using std::cout;
using std::endl;
using std::ios;

BankAccount::BankAccount(int dollars, int cents)
{
    if ((dollars < 0) || (cents < 0))
    {
        cout << "Illegal values for money.\n";
        return;
    }
	balance = dollars + 0.01*cents;
}


BankAccount::BankAccount(int dollars)
{
    if (dollars < 0)
    {
        cout << "Illegal value for money.\n";
        return;
    }
    balance = dollars;
}

BankAccount::BankAccount() : balance(0)
{
   //Body intentionally empty
}


void BankAccount::set(int dollars, int cents)
{
    if ((dollars < 0) || (cents < 0))
    {
        cout << "Illegal values for money.\n";
        return;
    }

    balance = dollars + 0.01*cents;
}

void BankAccount::set(int dollars)
{
    if (dollars < 0)
    {
        cout << "Illegal value for money.\n";
        return;
    }
    balance = dollars;
}

double BankAccount::getBalance() const
{
    return balance;
}

//Uses iostream:
void BankAccount::output(std::ostream& outs)
{
    outs.setf(ios::fixed);
    outs.setf(ios::showpoint);
    outs.precision(2);
    outs << "Account balance $" << balance << endl;
}


