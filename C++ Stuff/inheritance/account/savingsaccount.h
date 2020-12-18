#ifndef _SAVINGSACCOUNT_H_
#define _SAVINGSACCOUNT_H_

#include <iostream>
#include "bankaccount.h"

class SavingsAccount : public BankAccount
{
  public:
    SavingsAccount() : BankAccount() { }
    SavingsAccount(int dollars, int cents, double rate);

    // Adds $dollars.cents to the account balance
    void deposit(int dollars, int cents);

    // Subtracts $dollars.cents from the account balance
    void withdraw(int dollars, int cents);

    void set_rate(double new_rate);
    double get_rate() const;

    // Adds 1 year worth of interest to balance.
    void update();

  private:
    // As a derived class, we inherit the member variable
    // balance from BankAccount

    double interestRate;

     // Converts a percentage to a fraction. For example, fraction(50.3)
     // returns 0.503.
     double fraction(double percent);
};

#endif
