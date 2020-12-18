
// Lab 5.  Pointers & Dynamic Variables.

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

// Display the numbers in an array.
void display(const double arr[], unsigned int sz);

// Find the median of a list of numbers.
double median(const double arr[], unsigned int sz);

// Swap two variables.
void swap(double *d1, double *d2);

// Sort a list of numbers.
void bubblesort(double arr[], unsigned int sz);


int main()
{
    ifstream inputfile;
    string filename;
    cout << "Enter the name of a data file: ";
    cin >> filename;
    inputfile.open(filename);
    if (inputfile.fail())
        exit(1);

    unsigned int size;
    inputfile >> size;

    double *numbers = new double[size];
    unsigned int i;
    for (i = 0; i < size; ++i)
        inputfile >> numbers[i];

    // For debugging: print the array
    display(numbers, size);
    bubblesort(numbers, size);
    display(numbers, size);
    cout << "median: " << median(numbers, size) << endl;

    delete [] numbers;
    inputfile.close();

    return 0;
}


void display(const double arr[], unsigned int sz)
{
    unsigned int i;
    for (i = 0; i < sz; ++i)
        cout << arr[i] << " ";
    cout << endl;
    return;
}

double median(const double arr[], unsigned int sz)
{
    double med;
    if (sz % 2 == 0)
        med = ( arr[sz/2] + arr[sz/2-1] ) / 2;
    else
        med = arr[ sz/2 ];
        
    return med;
}

void swap(double *d1, double *d2)
{
    double temp;
    temp = *d1;
    *d1 = *d2;
    *d2 = temp;
}

void bubblesort(double arr[], unsigned int sz)
{
    unsigned int i, j;
    for (i = sz-1; i > 0; i--)
        for (j = 0U; j < i; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}


