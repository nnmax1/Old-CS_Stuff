
// This program fixes the memory leaks from dynvars_leaky.cpp,
// which is taken from the textbook.
// 
// For every call to new, we need to call delete to free up
// the memory that was allocated.

#include <iostream>
using namespace std;

int main()
{
    int *p1, *p2;

    p1 = new int(42);  //syntax for initialization with new
    // p1 points to a DYNAMIC VARIABLE
    
    p2 = p1;
    // p2 points to the same dynamic variable as p1

    cout << "*p1 == " << *p1 << endl;
    cout << "*p2 == " << *p2 << endl;

    *p2 = 53;
    cout << "*p1 == " << *p1 << endl;
    cout << "*p2 == " << *p2 << endl;

    p1 = new int;
    // p1 now points to a new, second, DYNAMIC VARIABLE

    *p1 = 88;
    cout << "*p1 == " << *p1 << endl;
    cout << "*p2 == " << *p2 << endl;
    cout << "Hope you got the point of this example!\n";

    // FIX THE MEMORY LEAK!
    // Call delete for every call to new: p1 and p2 point
    // to two different dynamic variables that were created with new
    delete p1;
    delete p2;

    return 0;
}
