
#include <iostream>
using namespace std;


//Class definition for a bank account:
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

int main( )
{
    BankAccount account1(100), account2;

    cout << "account1 initialized as follows:\n";
    account1.output(cout);
    cout << "account2 initialized as follows:\n";
    account2.output(cout);

    account1 = BankAccount(999, 99);
    cout << "account1 reset to the following:\n";
    account1.output(cout);

    account2.set(100);
    cout << "account2 set to $100.00:\n";
    account2.output(cout);
  
    return 0;
}

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


