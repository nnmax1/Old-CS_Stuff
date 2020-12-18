#include <iostream>
#include "savingsaccount.h"

// SavingsAccount constructor uses constructor delegation:
// we call the constructor for BankAccount
SavingsAccount::SavingsAccount(int dollars, int cents, double rate):
	BankAccount(dollars, cents), interestRate(rate)
{
	// deliberately empty
}

// NB: although SavingsAccount inherits all of BankAccount's
// members, we still cannot directly access private members of
// BankAccount; therefore, we use getBalance().

void SavingsAccount::deposit(int dollars, int cents)
{
	double balance = getBalance();
	balance += dollars;
	balance += (static_cast<double>(cents) / 100);
	int newDollars = static_cast<int>(balance);
	int newCents = static_cast<int>((balance - newDollars)*100);
	set(newDollars, newCents);
}

void SavingsAccount::withdraw(int dollars, int cents)
{
	double balance = getBalance();
	balance -= dollars;
	balance -= (static_cast<double>(cents) / 100);
	int newDollars = static_cast<int>(balance);
	int newCents = static_cast<int>((balance - newDollars)*100);
	set(newDollars, newCents);
}

void SavingsAccount::update()
{
    double temp_balance = getBalance();
    temp_balance = temp_balance + fraction(interestRate)*temp_balance;
	int newDollars = static_cast<int>(temp_balance);
	int newCents = static_cast<int>((temp_balance - newDollars)*100);
	set(newDollars, newCents);
}

double SavingsAccount::fraction(double percent_value)
{
    return (percent_value/100.0);
}

double SavingsAccount::get_rate() const
{
    return interestRate;
}

void SavingsAccount::set_rate(double new_rate)
{
    interestRate = new_rate;
}
