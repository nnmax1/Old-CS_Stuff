#include <iostream>
#include <ctime>

// A generic LinkedList data type 

template<typename T>
class LinkedList {
    public:
    //default constructor
    LinkedList() {
        value = NULL;
        next = nullptr;
    }
    //overloaded constructor
    LinkedList(T val, LinkedList* nextPtr) {
        value = val;
        next = nextPtr;
    }
    //destructor
    ~LinkedList() {
        delete next;
    }
    //get current element
    int getElement() {
        return value;
    }
    //return pointer to next element
    LinkedList * getNext() {
        return next;
    }
    //set next element node
    void setNext(LinkedList * n ){
        next =n;
    }

    private:
    LinkedList* next;
    T value;
};
