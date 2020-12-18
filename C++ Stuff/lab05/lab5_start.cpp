#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;


// Make this work, but using pointers (not reference parameters).
/*
void swap(double d1, double d2)
{
    double temp;
    temp = d1;
    d1 = d2;
    d2 = temp;
}
*/

// This will not work -- yet.
// We need to change the call to swap.
/*
void bubblesort(double arr[], unsigned int sz)
{
    unsigned int i, j;
    for (i = sz-1; i > 0; i--)
        for (j = 0U; j < i; j++)
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
}
*/

int main()
{


    return 0;
}
