#include <iostream>

//iterative binary Search implementation

//Binary Search Break down: 
/*
--Divide the search interval in half.
--Check if element at middle index == target, then return middle index.
--If the target value is greater than the middle value, 
  narrow the search to the right half of the array
--Otherwise, narrow the search to the left half of the array.
--Keep doing this until the index of the target value is found.
--If target index not found, return -1 b/c an index of -1 in an
  array does not exist.
*/


template<typename T>
int binarySearch(T arr[], int n, T target)
{
    int front = 0, back=n-1;
    while(front < back)
    {
        int middle = front + (back -1) / 2;
        if(arr[middle] == target) 
        {
            return middle;
        }
        //if middle of arr < target. ignore left sub array
        if(arr[middle] < target )
        {
            front = middle +1;
        }
        //ignore the right sub array
        else 
        {
            back = middle -1;
        }
    }
    //return -1 if all else fails
    return -1;
}
//test binary search implementation
int main(void) 
{ 
    int arr[] = { 1, 4, 5, 13, 79 }; 
    int targetNumber = 193; 
    int foundIndex = binarySearch(arr, 5, targetNumber); 
    if(foundIndex != -1) std::cout<<"Target found at index: "<<foundIndex<<"\n";
    else std::cout<<"Target not found\n";
    
    return 0; 
} 
