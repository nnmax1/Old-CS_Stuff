#ifndef _BANKACCOUNT_H_
#define _BANKACCOUNT_H_

#include <iostream>

class BankAccount
{
  public:
     // Default constructor.
     // Initializes the account balance to $0.00.
     BankAccount();

     // Initializes the account balance to $dollars.00.
     BankAccount(int dollars);

     // Initializes the account balance to $dollars.cents.
     BankAccount(int dollars, int cents);

     // Postcondition: The account balance has been set to $dollars.cents.
     void set(int dollars, int cents);

     // Postcondition: The account balance has been set to $dollars.00.
     void set(int dollars);

     // Returns the current account balance.
     double getBalance() const;

     // Precondition: If outs is a file output stream, then
     // outs has already been connected to a file.
     // Postcondition: Account balance and interest rate
     // have been written to the stream outs.
     void output(std::ostream& outs);

  private:
     double balance;
};

#endif
