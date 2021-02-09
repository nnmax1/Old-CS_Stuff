#include <iostream>


//generic Quick Sort implementation to sort elements in an array from L -> G


//Time Compexity:
//best case: O(nlogn)
//worst case: O(n^2)
//Avg: O(nlogn)



//Break Down of Quick Sort
/*
-- Goal: is to repeatedly partition the input into low and high parts (each part unsorted), 
   and then recursively sort each of those parts.
--To partition, we  chooses a pivot to divide the data into low and high parts. 
   --the pivot is commonly the middle element.
*/

template<typename T>
void swap(T& v1, T&v2)
{
    T temp = v1;
    v1 = v2;
    v2 = temp;
}
template<typename T>
int partition(T arr[], int i, int k) 
{
      int l, h, mid,temp;
      T pivot;
      bool done=false;

      ///assign middle element to the pivot
      mid = i + (k - i) / 2;
      pivot = arr[mid];

      l = i;
      h = k;

      while (!done) {
         //Increment l while arr[l] < pivot
         while (arr[l] < pivot) {
            ++l;
         }

         //decrement h while pivot < arr[h]
         while (pivot < arr[h]) {
            --h;
         }

         //if there are zero or one item left,
         //all values have been partitioned. Return h
         if (l >= h) {
            done = true;
         } 
         //if not all partitioned, swap arr[1] w/ arr[h]
         else {
            swap(arr[l++], arr[h--]);
         }
      }

      return h;
   }
template<typename T>
void quickSort(T arr[], int i, int k) {
      int j;

      //if there are 1 or 0 entries to sort,
      // partition is already sorted. Thus, nothing needed to do.
      if (i >= k) {
         return;
      }

      //partition elements in the arr. Value j returned
      // from partitioning is location of last item in low partition. 
      j = partition(arr, i, k);

      //recursively sort low (i to j) and
      // high (j + 1 to k) partitions 
      quickSort(arr, i, j);
      quickSort(arr, j + 1, k);
   }


//Test Quick Sort Implementation:
int main(void) {
      const int MAXSIZE = 5;
      std::string bandArr[MAXSIZE] = {"Metallica", "Pink Floyd", "The Beatles","Van Halen","Black Sabbath"};
      int i;

    //unsorted arr
    std::cout<<"unsorted arr: ";
    for(auto element : bandArr) {
         std::cout<<element<<"-->";
      }
      std::cout<<"\n\n";

   quickSort(bandArr, 0, MAXSIZE-1);

    //sorted arr
    std::cout<<"sorted arr: ";
    for(auto element : bandArr) {
         std::cout<<element<<"-->";
      }
      std::cout<<"\n";

    return 0;
}