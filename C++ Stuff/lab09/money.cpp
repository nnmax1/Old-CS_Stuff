
//
// Lab 9. Separate compilation.
//
// money.cpp: this is the implementation file for the Money class.

#include <iostream>
#include <cstdlib>
#include <cctype>
#include "money.h"

using std::istream;
using std::ostream;
using std::cout;

//Uses iostream, cctype, cstdlib:
istream& operator >>(istream& ins, Money& amount)
{
    char oneChar, decimalPoint,
         digit1, digit2; //digits for the amount of cents
    long dollars;
    int cents;
    bool negative;//set to true if input is negative.

    ins >> oneChar;
    if (oneChar == '-')
    {
        negative = true;
        ins >> oneChar; //read '$'
    }
    else
        negative = false;
    //if input is legal, then oneChar == '$'

    ins >> dollars >> decimalPoint >> digit1 >> digit2;

    if ( oneChar != '$' || decimalPoint != '.'
            || !isdigit(digit1) || !isdigit(digit2) )
    {
        cout << "Error illegal form for money input\n";
        exit(1);
    }

    cents = digitToInt(digit1)*10 + digitToInt(digit2);

    amount.allCents = dollars*100 + cents;
    if (negative)
        amount.allCents = -amount.allCents;

    return ins;
}

int digitToInt(char c)
{
    return ( static_cast<int>(c) - static_cast<int>('0') );
}


ostream& operator <<(ostream& outs, const Money& amount)
{
    long positiveCents, dollars, cents;
    positiveCents = labs(amount.allCents);
    dollars = positiveCents/100;
    cents = positiveCents%100;

    if (amount.allCents < 0)
        outs << "-$" << dollars << '.';
    else
        outs << "$" << dollars << '.';

    if (cents < 10)
        outs << '0';
    outs << cents;

    return outs;
}

Money operator +(const Money& amount1, const Money& amount2)
{
    Money temp;
    temp.allCents = amount1.allCents + amount2.allCents;
    return temp;
}

Money operator *(const Money& amount1, const Money& amount2)
{
    Money temp;
    temp.allCents = (amount1.allCents * amount2.allCents) / 100;
    return temp;
}


bool operator ==(const Money& amount1, const Money& amount2)
{
    return (amount1.allCents == amount2.allCents);
}


bool operator !=(const Money& amount1, const Money& amount2)
{
    return !(amount1 == amount2);
}

Money operator -(const Money& amount1, const Money& amount2)
{
    Money temp;
    temp.allCents = amount1.allCents - amount2.allCents;
    return temp;
}

Money operator -(const Money& amount)
{
    Money temp;
    temp.allCents = -amount.allCents;
    return temp;
}

bool operator <(const Money& amount1, const Money& amount2)
{
    return amount1.allCents < amount2.allCents;
}


bool operator >(const Money& amount1, const Money& amount2)
{
    return amount1.allCents > amount2.allCents;
}


bool operator <=(const Money& amount1, const Money& amount2)
{
    return ( (amount1.allCents < amount2.allCents) ||
                  (amount1.allCents == amount2.allCents) ) ;
}


bool operator >=(const Money& amount1, const Money& amount2)
{

    return ( (amount1.allCents > amount2.allCents) ||
                  (amount1.allCents == amount2.allCents) ) ;
}

Money::Money(long dollars, int cents)
{
    if(dollars*cents < 0) //If one is negative and one is positive
    {
        cout << "Illegal values for dollars and cents.\n";
        exit(1);
    }
    allCents = dollars*100 + cents;
}

Money::Money(long dollars) : allCents(dollars*100)
{
    //Body intentionally blank.
}

Money::Money() : allCents(0)
{
    //Body intentionally blank.
}

double Money::getValue() const
{
    return (allCents * 0.01);
}

