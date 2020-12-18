
#include <iostream>
//generic bubble sort implementation to sort values in array from least -> greatest

//Time Compexity:
//best case: O(n)
//worst case: O(n^2)
//Avg: O(n^2)


//Breakdown of Bubble Sort: 
//-Iterate Thru the array
//-compare adjacent elements 
//-swap the values if the elements are not arranged in order

template<typename T>
void swap(T& v1, T&v2)
{
    T temp = v1;
    v1 = v2;
    v2 = temp;
}
template<typename T>
void bubbleSort(T arr[], int n)
{
    for (int i = 0; i < n-1; i++)      
    {
        for (int j = 0; j < n-i-1; j++) 
        {
            if (arr[j] > arr[j+1])
            {
                //swap
               swap(arr[j],arr[j+1]);
            }
        }          
    }
}
//test bubble sort implementation:
int main(void) {
    double arr[6]= {4.2, 9.1, 2.4, 1.11, 10.87, 3.43};

    //before sort
    std::cout<<"unsorted arr: ";
    for(auto e : arr)
    {
        std::cout<<e<<" ";
    }
    std::cout<<"\n";
    bubbleSort(arr, 6);
    //after sort 
    std::cout<<"sorted arr: ";
    for(auto e : arr)
    {
        std::cout<<e<<" ";
    }
    std::cout<<"\n";
    return 0;
}