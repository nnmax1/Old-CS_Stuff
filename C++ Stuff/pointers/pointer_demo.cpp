
// Demonstrate basic pointer usage.

#include <iostream>
using namespace std;

int main()
{

    double x = 12.7;
    double y = -9.5;

    double *ptr1 = &x;  // assign address of x to ptr1
    double *ptr2 = &y;  // assign address of y to ptr2

    // What is the output?
    cout << "x == " << x << " *ptr1 == " << *ptr1 << endl;
    cout << "y == " << y << " *ptr2 == " << *ptr2 << endl;

    // Pointer assignment
    ptr2 = ptr1;
    cout << "\nAfter assigning ptr1 to ptr2:" << endl;
    cout << "x == " << x << " *ptr1 == " << *ptr1 << endl;
    cout << "y == " << y << " *ptr2 == " << *ptr2 << endl;

    // Now that ptr2 points to the same variable as ptr1, we
    // can change x using ptr2
    cout << "\nNow this assignment statement: *ptr1 = 49.1;" << endl;
    *ptr1 = 49.1;
    cout << "x == " << x << " *ptr1 == " << *ptr1 << endl;
    cout << "y == " << y << " *ptr2 == " << *ptr2 << endl;

    // What are the pointer variables themselves?

    cout << "\nWhat do pointer variables contain?" << endl;
    cout << "ptr1 == " << ptr1 << endl;
    cout << "ptr2 == " << ptr2 << endl;

    return 0;
}
