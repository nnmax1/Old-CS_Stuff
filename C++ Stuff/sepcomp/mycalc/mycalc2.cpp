#include <iostream>
#include "mycalc.h"


void myadd(double x, double y)
{
    std::cout << x << " + " << y << " = " << x + y << std::endl;
    return;
}


void mysub(double x, double y)
{
    std::cout << x << " - " << y << " = " << x - y << std::endl;
    return;
}


void mymult(double x, double y)
{
    std::cout << x << " * " << y << " = " << x * y << std::endl;
    return;
}

void mydiv(double x, double y)
{
    std::cout << x << " / " << y << " = " << x / y << std::endl;
    return;
}
