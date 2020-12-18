#include <iostream>

//generic Merge sort implementation to sort elements in an array from least->greatest


//Time Compexity:
//best case: O(nlogn)
//worst case: O(nlogn)
//Avg: O(nlogn)


/*Merge Sort Pseudocode:

--Split the input array into halves 
--Recursively Sort each half
--Recursively partition until there is 1 element 
  left b/c that means that the list has been sorted.
--Merge the sorted halves together into a single array by repeatedly selecting 
  the smallest element from either the left or right partition and adding that 
  element to a temporary merged array.
--Once everything is merged, the elements in the temporary merged array are 
  copied back to the original array.
*/

//Similar to quick sort, integer vars will be used to keep track 
//of indices within the array: 1 for the front, back, and one to divide the array in half

//merge function
template<typename T>
void merge(T arr[], int i, int j, int k) {
      //size of merged partition
      int mergedSize = k - i + 1;       
      //dynamic array mergedValues will be used to hold merged values
      T* mergedValues = new T[mergedSize];    
      //position where merged value is inserted, pos of elems. in left part. , pos of elems in right part.
      int mergePos, leftPos, rightPos;                   
      
      //init left, right, and merge positions
      mergePos = 0;
      leftPos = i;                      
      rightPos = j + 1;                 

      //add smallest element from left or right partition to merged values
      while (leftPos <= j && rightPos <= k) {
         if (arr[leftPos] < arr[rightPos]) {
            mergedValues[mergePos] = arr[leftPos++];
         } 
         else {
            mergedValues[mergePos] = arr[rightPos++];
         }
         ++mergePos;
      }

      //while left partition is not empty, add remaining elements to merged values
      while (leftPos <= j) {
         mergedValues[mergePos++] = arr[leftPos++];
      }

      //while right partition is not empty, add remaining elements to merged values
      while (rightPos <= k) {
         mergedValues[mergePos++] = arr[rightPos++];
      }

      //copy merge values back to the original array
      for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
         arr[i + mergePos] = mergedValues[mergePos];
      }
      //deallocate mergedValues dynamic array 
      delete [] mergedValues;
}
//mergeSort function
template<typename T>
void mergeSort(T arr[], int i, int j ) {
     int mid;
     //search for the middle of partition
      if (i < j) {
         mid = (i + j) / 2;  

         //recursively sort left 
         mergeSort(arr, i, mid);
         //recursively sort right parition
         mergeSort(arr, mid + 1, j);

         //merge the sorted left and right partitions 
         merge(arr, i, mid, j);
      }
}


//Test Merge Sort Implementation:
int main(void) {
      const int MAXSIZE = 5;
      std::string colorArr[MAXSIZE] = {"sarcoline", "midnight blue", "indigo", "aquamarine", "turqoise"};
      int i;

    //unsorted arr
    std::cout<<"unsorted arr: ";
    for(auto element : colorArr) {
         std::cout<<element<<"-->";
      }
      std::cout<<"\n\n";

   mergeSort(colorArr, 0, MAXSIZE-1);

    //sorted arr
    std::cout<<"sorted arr: ";
    for(auto element : colorArr) {
         std::cout<<element<<"-->";
      }
      std::cout<<"\n";

    return 0;
}