
//
// Demonstrate dynamically allocated 2-d array.
// Adapted from DISPLAY 9.7 A Two-Dimensional Dynamic Array (in Savitch)

#include <iostream>
using namespace std;

int main( )
{
    int d1, d2;
    cout << "Enter the row and column dimensions of the array:\n";
    cin >> d1 >> d2;

    // Allocate an array of int * pointers
    // m is a pointer to a pointer (common when allocating arrays)
    int **m = new int*[d1];

    // For each row of m, allocate an array of ints
    int i, j;
    for (i = 0; i < d1; i++)
        m[i] = new int[d2];
    //m is now a d1 by d2 array.

    cout << "Enter " << d1 << " rows of "
         << d2 << " integers each:\n";
    for (i = 0; i < d1; i++)
        for (j = 0; j < d2; j++)
            cin >> m[i][j];

    cout << "Echoing the two-dimensional array:\n";
    for (i = 0; i < d1; i++)
    {
        for (j = 0; j < d2; j++)
            cout << m[i][j] << " ";
        cout << endl;
    }

    // When deleting the 2D array, first delete the arrays in each row,
    // then delete the original array of pointers to ints
    for (i = 0; i < d1; i++)
        delete[] m[i];
    delete[] m;

    return 0;
}
