
#include <iostream>

// Precondition: length <= declared size of the array arr.
// The array elements arr[0] through a[length - 1] have values.
// Postcondition: The values of arr[0] through arr[length - 1] have
// been rearranged so that arr[0] <= a[1] <= ... <= arr[length - 1].
void bubblesort(int arr[], int length);

//Interchanges the values of v1 and v2.
void swap(int &v1, int &v2);

int main()
{
        using namespace std;
        int a[] = {3, 10, 9, 2, 5, 1};

        bubblesort(a, 6);
        for (int i=0; i<6; i++)
                cout << a[i] << " ";
        cout << endl;

        return 0;
}

void bubblesort(int arr[], int length)
{
    // Bubble largest number toward the right
    for (int i = length-1; i > 0; i--)
        for (int j = 0; j < i; j++)
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
}

void swap(int &v1, int &v2)
{
    int temp = v1;
    v1 = v2;
    v2 = temp;
}
