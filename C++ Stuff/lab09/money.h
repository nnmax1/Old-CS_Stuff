
// Lab 9. Separate Compilation.
//
// money.h: the interface file for the Money class.

#ifndef _MONEY_H_
#define _MONEY_H_

#include <iostream>

using std::ostream;
using std::istream;


// A class for amounts of money in U.S. currency.
class Money
{
    public:
        friend Money operator +(const Money& amount1, const Money& amount2);
        friend Money operator -(const Money& amount1, const Money& amount2);
        friend Money operator -(const Money& amount);
        friend Money operator *(const Money& amount1, const Money& amount2);

        friend bool operator ==(const Money& amount1, const Money& amount2);
        friend bool operator !=(const Money& amount1, const Money& amount2);
        friend bool operator <(const Money& amount1, const Money& amount2);
        friend bool operator >(const Money& amount1, const Money& amount2);
        friend bool operator <=(const Money& amount1, const Money& amount2);
        friend bool operator >=(const Money& amount1, const Money& amount2);

        Money(long dollars, int cents);
        Money(long dollars);
        Money();

        double getValue() const;

        //Overloads the >> operator so it can be used to input values of
        //type Money. Notation for inputting negative amounts is as 
        //in -$100.00.
        //Precondition: If ins is a file input stream, then ins has
        //already been connected to a file.
        friend istream& operator >>(istream& ins, Money& amount);

        //Overloads the << operator so it can be used to output values of
        //type Money. Precedes each output value of type Money with a
        //dollar sign.
        //Precondition: If outs is a file output stream,
        //then outs has already been connected to a file.
        friend ostream& operator <<(ostream& outs, const Money& amount);

    private:
        long allCents;
};


//Used in the definition of the overloaded input operator >>.
//Precondition: c is one of the digits '0' through '9'.
//Returns the integer for the digit; for example, digitToInt('3') returns 3.
int digitToInt(char c);


#endif // _MONEY_H_
