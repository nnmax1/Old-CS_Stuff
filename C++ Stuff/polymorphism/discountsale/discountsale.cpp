//This is the implementation for the class DiscountSale.
#include "discountsale.h"

DiscountSale::DiscountSale() : Sale(), discount(0)
{
  // empty
}

DiscountSale::DiscountSale(double the_price, double the_discount)
    : Sale(the_price), discount(the_discount)
{
  // empty
}

double DiscountSale::bill() const
{
    double fraction = discount/100;
    return (1 - fraction)*price;
}
