
// Demonstrates dynamically allocating a ragged 2-d array.
// Modifies DISPLAY 9.7 A Two-Dimensional Dynamic Array (in Savitch)

#include <iostream>
using namespace std;


typedef int * IntArray;
typedef int ** Int2DArray;

void print_2d_ragged(Int2DArray arr, int d1, IntArray rowsz)
{
    for (int i = 0; i < d1; ++i)
    {
        for (int j = 0; j < rowsz[i]; ++j)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    return;
}

int main( )
{
    int d1, d2;
    cout << "Enter the number of rows: ";
    cin >> d1;

    // Allocate an array to keep track of the size of each row
    IntArray rowsize = new int[d1];

    // Allocate an array of int * pointers
    // m is a pointer to a pointer (common when allocating arrays)
    Int2DArray m = new IntArray[d1];

    // For each row of m, allocate an array of ints
    int i, j;
    for (i = 0; i < d1; i++)
    {
        cout << "How many integers in row " << i+1 << "? ";
        cin >> d2;
        rowsize[i] = d2;
        m[i] = new int[d2];
        cout << "Enter " << d2 << " integers:\n";
        for (j = 0; j < d2; j++)
            cin >> m[i][j];
    }

    cout << "Echoing the two-dimensional array:\n";
    print_2d_ragged(m, d1, rowsize);

    // When deleting the 2D array, first delete the arrays in each row,
    // then delete the original array of pointers to ints
    for (i = 0; i < d1; i++)
        delete[] m[i];
    delete[] m;

    delete[] rowsize;

    return 0;
}
