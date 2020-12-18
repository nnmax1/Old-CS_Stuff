#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

template<typename T, int size>
class Queue {
public:
    Queue(){
        queue = new T[size];
        cap = size;
        front = 0;
        rear = -1;
        count =0;
    }
    ~Queue() {
        delete [] queue;
    }
    int getSize() {
        return count;
    }
    bool isFull(){
        return getSize() == cap;
    }
     bool isEmpty(){
         return getSize() == 0;
    }
    void enqueue(T item){
        if(isFull()){
            std::cout<<"Cannot enqueue. Queue is full\n";
        } 
        rear = (rear + 1) % cap;
	    queue[rear] = item;
	    count++;
    }
    void dequeue(){
        if(isEmpty()){
            std::cout<<"Cannot dequeue. Queue is empty\n";
        }
	    front = (front + 1) % cap;
	    count--;
    }
    T peek() {
        if(isEmpty()){
           std::cout<<"Cannot get peek. Queue is empty\n";
        } 
        return queue[front];
    }
private:
    T* queue;
    int front, rear;
    int count;
    int cap;
};

#endif