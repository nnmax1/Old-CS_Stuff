
// Lab 9. Separate Compilation.
//
// money_main.cpp: this program tests the Money class.

#include <iostream>
#include <cassert>
#include "money.h"

using std::cout;
using std::endl;

int main( )
{
    Money amt1(1,90), amt2(2,10);
    cout << "amt1 = " << amt1 << endl;
    cout << "amt2 = " << amt2 << endl;
    cout << "amt1 + amt2 = " << amt1 + amt2 << endl;
    cout << "amt1 - amt2 = " << amt1 - amt2 << endl;

    assert(amt1 == amt1);
    assert(amt1 != amt2);
    assert(amt1 < amt2);
    assert(amt2 > amt1);
    assert(amt1 <= amt1);
    assert(amt2 >= amt2);
    assert(amt1 <= amt2);
    assert(amt2 >= amt1);

    Money amt3(3,99);
    cout << "amt1 * amt2 = " << amt1 * amt2 << endl;
    assert((amt1 * amt2) == amt3);

    return 0;
}

