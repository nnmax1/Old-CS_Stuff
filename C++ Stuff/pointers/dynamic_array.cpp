
// Demo: A Dynamic Array.
// Sorts a list of numbers entered at the keyboard.
// Adapted from display 9.6 in Savitch.

#include <iostream>
#include <cstdlib>
#include <cstddef>

typedef int* IntArray;

// Precondition: size is the size of the array a.
// Postcondition: a[0] through a[size-1] have been
// filled with values read from the keyboard.
void fill_array(int a[], int size)
{
    using namespace std;
    cout << "Enter " << size << " integers.\n";
    for (int index = 0; index < size; index++)
        cin >> a[index];
}

void bubblesort(int arr[], int length)
{
    for (int i = length-1; i > 0; i--)
        for (int j = 0; j < i; j++)
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
}

int main( )
{
    using namespace std;
    cout << "This program sorts numbers from lowest to highest.\n";

    int array_size;
    cout << "How many numbers will be sorted? ";
    cin >> array_size;

    IntArray mynums;
    mynums = new int[array_size];

    fill_array(mynums, array_size);
    bubblesort(mynums, array_size);

    cout << "In sorted order the numbers are:\n";
    for (int index = 0; index < array_size; index++)
        cout << mynums[index] << " ";
    cout << endl;

    delete [] mynums;  // Don't forget to delete; otherwise, memory leak!

    return 0;
}
