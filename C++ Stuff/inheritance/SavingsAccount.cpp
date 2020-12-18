
#include <iostream>
using namespace std;

//-------------------------------------------------------------------
//       BankAccount CLASS DEFINITION AND MEMBER FUNCTIONS  
//------------------------------------------------------------------
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
     void output(ostream& outs);

  private:
     double balance;
};

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
void BankAccount::output(ostream& outs)
{
    outs.setf(ios::fixed);
    outs.setf(ios::showpoint);
    outs.precision(2);
    outs << "Account balance $" << balance << endl;
}
// --------------- END BankAccount Definitions -------------------------

// Definition of the derived class SavingsAccount
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

    double interestRate = 0.0;

     // Converts a percentage to a fraction. For example, fraction(50.3)
     // returns 0.503.
     double fraction(double percent);
};


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

// BAD VERSION -- won't work because balance is private in BankAccount
/*
void SavingsAccount::update()
{
    balance = balance + fraction(interestRate)*balance;
}
*/

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
