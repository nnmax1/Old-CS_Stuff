
///solution to smart pointer linked list problem
//Question # 24

#include <memory>//access smart pointer template class
#include <iostream>
#include <ctime>

//class that  allows you to make linked list of integers

class MyIntList {
    public:
    //default constructor
    MyIntList() {
        value = 0;
        next = nullptr;
    }
    //overloaded constructor
    MyIntList(int val, std::shared_ptr<MyIntList> nextPtr) {
        value = val;
        next = nextPtr;
    }
    //destructor
    ~MyIntList() {
        //we don't need to deallocate anything b/c, thanks to abstraction,
        // smart pointers handle that for us!
    }
    //get current element
    int getElement() {
        return value;
    }
    //return smart pointer to next element
    std::shared_ptr<MyIntList> getNext() {
        return next;
    }
    //set next element node
    void setNext(std::shared_ptr<MyIntList> n ){
        next =n;
    }

    private:
    std::shared_ptr<MyIntList> next;
    int value;
};


//test linked list class solution:
int main() {
    srand(time(NULL));
    
    //root of linked list
    std::shared_ptr<MyIntList> root(new MyIntList(2, nullptr)), next[5];


    //get 5 random integers and store them in next arr which is an 
    //array of MyIntList nodes.
    for(int i=0;i<5;i++){
        int randomN = (rand() % 100)+1;
        next[i].reset(new MyIntList(randomN, nullptr));
    }

    //add next array elements to root
    root->setNext(next[0]);
    for(int i=0;i<4;i++){
        next[i]->setNext(next[i+1]);
    }

    //display contents of list
    std::shared_ptr<MyIntList>temp;
    temp = root;
    std::cout<<"Integers in linked list: ";
    while(temp != nullptr){
        std::cout<<temp->getElement()<<" ";
        temp = temp->getNext();
    }
    std::cout<<"\n";
    
    
    return 0;
}