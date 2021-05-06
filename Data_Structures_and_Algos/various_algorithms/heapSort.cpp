#include <iostream>
#include "../data_structures/priorityQueue.hpp"
// #include <queue> 
// you can alternatively used std::priority_queue


//Generic Heap sort implementation to sort an array 

//Time complexity: 0(nlogn)


//Generic Heap Sort methods


// uses the PriorityQueue class defined in data_structures folder
template<typename T>
void HeapSort(T A[], int n) {
	//build heap using PriorityQueue class
	PriorityQueue<T> pq(A, n);

	//pop repeatedly from heap till it's empty
	while (n > 0) {
		A[n - 1] = pq.pop(A, n);
		n--;
	}
}


//test heapSort: 
int main()
{
	int A[] = { 6, 4, 7, 1, 9, -2 };
	std::string beatles[] = {"Ringo","John", "George", "Paul"};

	//call heap sort on the arrays
	HeapSort(A, 6);
	HeapSort(beatles, 4);
	//print the sorted array to console
	std::cout<<"Integer Arr: ";
	for (int num : A) {
		std::cout << num << " ";
	}
	std::cout<<"\n";
	std::cout<<"String Arr: ";
	for (std::string beatle : beatles) {
		std::cout << beatle << " ";
	}
	std::cout<<"\n";
	return 0;
}