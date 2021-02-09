#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

//Generic Priority Queue Class
template<typename T>
class PriorityQueue {
    public:
	//Constructor 
	PriorityQueue(T A[], int n){
		//call heapify starting from 
		//last internal node all the
		//way up to root node to build the heap
		int i = (n - 2) / 2;
		while (i >= 0) {
			Heapify(A, i--, n);
		}
	}
	//function to remove element with highest priority 
	T pop(T A[], int size){
		//if heap has no elements
		T top;
		if (size <= 0) {
			top = -1;
			return top;
		}else {
			top = A[0];
		}
		//replace the root of the heap with the last element of the arr
		A[0] = A[size-1];
		//call heapify-down on root node
		Heapify(A, 0, size - 1);

		return top;
	}
    private:
	//return left child of Priority Queue
	int leftPQ(int i) {
		return (2 * i + 1);
	}
	//return right child of Priority Queue
	int rightPQ(int i) {
		return (2 * i + 2);
	}
	//swap 
	void swap(T& v1, T&v2) {
    	T temp = v1;
    	v1 = v2;
    	v2 = temp;
	}
	// Recursive Heapify-down algo
	void Heapify(T A[], int i, int size){
		//get left and right child of node at index i
		int left = leftPQ(i);
		int right = rightPQ(i);

		int largest = i;

		//compare A[i] with its left and right child to find largest value
		if (left < size && A[left] > A[i]) {
			largest = left;
		}

		if (right < size && A[right] > A[largest]) {
			largest = right;
		}
		//swap with child having greater value and
		//call heapify-down on the child
		if (largest != i) {
			swap(A[i], A[largest]);
			Heapify(A, largest, size);
		}
	}
};

#endif