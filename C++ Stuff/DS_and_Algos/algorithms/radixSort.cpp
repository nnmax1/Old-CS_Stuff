#include <iostream> 
using namespace std; 
  

class RadixSort {
    public: 
    RadixSort() {}
void sort(int arr[], int n)  { 
    // get max value 
    int m = getMax(arr, n); 
    //counting sort for each dig.
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countSort(arr, n, exp); 
    }
} 
    private: 
// A utility function to get maximum value in arr[] 
int getMax(int arr[], int n)  { 
    int mx = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > mx) 
            mx = arr[i]; 
    return mx; 
} 
void countSort(int arr[], int n, int exp)  { 
    int res[n];
    int i, count[10] = { 0 }; 
    for (i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    } 
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1]; 
    }
    for (i = n - 1; i >= 0; i--) { 
        res[count[(arr[i] / exp) % 10] - 1] = arr[i]; 
        count[(arr[i] / exp) % 10]--; 
    }
    //copy elements to res arr
    for (i = 0; i < n; i++) {
        arr[i] = res[i]; 
    }
} 
  
};


// Driver Code 
int main() 
{ 
    int arr[] = { 83, 938, 38, 28, 2828, 28, 1 }; 
    int sz = sizeof(arr) / sizeof(arr[0]); 
    RadixSort radix;
    radix.sort(arr, sz); 

    std::cout<<"Sorted elements: ";
    for(int e : arr) {
        std::cout<<e<<" ";
    }
    std::cout<<"\n";

    return 0; 
}