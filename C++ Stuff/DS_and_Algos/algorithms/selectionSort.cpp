
#include <iostream>

//generic selection sort implementation to sort values from least -> greatest


//Goal of selection sort: 
//to repeatedly find the smallest element from the unsorted part of the array
//and put it at the beginning. (sort values into ascending order)

//Time Complexity: 
//Best : O(n^2)
//Worst : O(n^2)
//Avg: O(n^2)


template<typename T>
void swap(T& v1, T&v2)
{
    T temp = v1;
    v1 = v2;
    v2 = temp;
}

template<typename T>
void selectionSort(T arr[], int n)
{
    int minIndex;
    for(int i=0;i<n;i++)
    {
        minIndex = i;
        //search for index of smallest remaining value in 
        //the arr
        for(int j=i+1; j<n; ++j)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        //swap values at current index w/ the value at the min index.
        swap(arr[i], arr[minIndex]);
    }
}

//Test Selection Sort implementation:
int main() {
    int arr[6]= {4, 9, 2, 1, 10, 3};
    std::cout<<"unsorted arr: ";
    for(auto e : arr)
    {
        std::cout<<e<<" ";
    }
    std::cout<<"\n";
    selectionSort(arr, 6);
    std::cout<<"sorted arr: ";
    for(auto e : arr)
    {
        std::cout<<e<<" ";
    }
    std::cout<<"\n";
    return 0;
}