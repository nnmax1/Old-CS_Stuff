
//
// Program to demonstrate that an array variable is a kind of pointer variable.
// DISPLAY 9.4 Arrays and Pointer Variables (from Savitch)
//
#include <iostream>
using namespace std;

// Example of a typedef
typedef int* IntPtr;

int main()
{
    IntPtr p;
    int a[10];
    int index;

    // Set values of array a from 0 to 9
    for (index = 0; index < 10; index++)
        a[index] = index;

    p = a;  // p now points to first elemen of a

    // We can access the array a via p
    for (index = 0; index < 10; index++)
        cout << p[index] << " ";
    cout << endl;

    // We can also change a via p
    for (index = 0; index < 10; index++)
        p[index] = p[index] + 1;

    for (index = 0; index < 10; index++)
        cout << a[index] << " ";
    cout << endl;

    // p points to the first element of a
    cout << "*p  = " << *p << endl;   // should be 1
    cout << "a[0]= " << a[0] << endl;  // should be 1
    // p and a should point to the same location
    cout << "p = " << p << endl;
    cout << "a = " << a << endl;
    // BUT--we can't assign p to a
//  a = p;
    // We can treat p like an array variable
    cout << "p[0] = " << p[0] << endl;
    cout << "p[1] = " << p[1] << endl;
    cout << "p[9] = " << p[9] << endl;

    return 0;
}

