//DISPLAY 15.9 Interface for the Base Class Sale
//This is the header file sale.h.
//This is the interface for the class Sale.
//Sale is a class for simple sales.
#ifndef SALE_H
#define SALE_H

#include <iostream>
using namespace std;


class Sale
{
    public:
        Sale();
        Sale(double the_price);
        virtual double bill() const;

        //Returns the savings if you buy other instead of the calling object.
        double savings(const Sale& other) const;

    protected:
        double price;
};

//Compares two sales to see which is larger.
bool operator < (const Sale& first, const Sale& second);


#endif // SALE_H
