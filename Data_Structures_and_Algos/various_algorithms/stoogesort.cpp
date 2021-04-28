#include <iostream>

template <typename T>
void stoogesort(T arr[],int l, int h) {
    if (l >= h)
      return;
    if (arr[l] > arr[h])
       std::swap(arr[l], arr[h]);
    // If arr has > 2 elements
    if(h-l+1>2) {
        int t = (h-l+1)/3;
        // recursively sort first 2/3 elements
        stoogesort(arr, l, h-t);
        // recursively sort last 2/3 elements
        stoogesort(arr, l+t, h);
        // recursively sort first 2/3 elements
        stoogesort(arr, l, h-t);
    }
}
 
// Driver Code
int main() {
    std::string sortingAlgos[] = {"stooge", "radix", "quick","bubble", "selection", "merge","insertion"};
    int n = sizeof(sortingAlgos)/sizeof(sortingAlgos[0]);
 
    // Calling Stooge Sort function to sort
    // the array
    stoogesort(sortingAlgos, 0, n-1);
 
    // Display the sorted array
    for (int i=0; i<n; i++) std::cout << sortingAlgos[i] << " ";
    std::cout<<"\n";
    return 0;
}