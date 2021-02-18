#include <iostream>

//generic insertion sort implementation to sort values in an array from least to greatest


//Time Compexity:
//best case: O(n)
//worst case: O(n^2)
//Avg: O(n^2)

//Goal of Insertion Sort: To insert values into the array
//until the values in the array are sorted from l->g or g->l


template<typename T>
void swap(T& v1, T&v2)
{
    T temp = v1;
    v1 = v2;
    v2 = temp;
}
template<typename T>
void insertionSort(T arr[], int n){
    int j;
    for(int i=1;i<n;++i)
    {
        j=i;
        while(j > 0 && arr[j]  < arr[j-1])
        {
            swap(arr[j], arr[j-1]);
            --j;
        }
    }
}
//test insertion sort implementation:
int main(void) {
    long int arr[6]= {488388, 99339, 28473, 18382, 78336, 38383};
    std::cout<<"unsorted arr: ";
    for(auto e : arr)
    {
        std::cout<<e<<" ";
    }
    std::cout<<"\n";
    insertionSort(arr, 6);
    std::cout<<"sorted arr: ";
    for(auto e : arr)
    {
        std::cout<<e<<" ";
    }
    std::cout<<"\n";
    return 0;
}