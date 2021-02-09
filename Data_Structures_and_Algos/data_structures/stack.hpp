#ifndef STACK_H
#define STACK_H

#include <iostream>
template <typename T, int size>
class Stack {
    public:
        //constructor
        Stack() {
            stack = new T[size];
            top = -1;
        }
        //destructor
        ~Stack() {
            delete [] stack; 
        }
        //check if empty
        bool isEmpty() {
            return top == -1;
        }    
        //insert item
        void push(T item) {
            if (top == size - 1) {
                //throw an ArrayIndexOutOfBounds Exception
                throw std::out_of_range("Cannot push element onto the stack.");
            }
            //insert element 
            stack[++top] = item;
        }
        //remove item
        T pop() {
           if(isEmpty()) {
                throw std::out_of_range("Cannot pop. No elements on the stack");
           }
           T removed = stack[top--];
           return removed;
        }
        T at(int index) {
            return stack[index];
        }
        //use an overloaded ostream to print elements of stack
        friend std::ostream& operator<<(std::ostream& os, Stack& s) {
            if (s.isEmpty()){
                os<<"Nothing in the stack.\n";
            }else{ 
                for (int i = s.topIndex(); i >= 0; i--){
                    os<<s.at(i)<<" ";
                }
                os <<"\n";
            }
            return os;
        }   
        //return top element    
        T getTop() {
            if(isEmpty()) {
                throw std::out_of_range("Cannot get top. Stack is empty");
            }
            return stack[top];
        }
        int topIndex() {
            if(isEmpty()) {
                throw std::out_of_range("Cannot get top inddx. Stack is empty");
            }
            return top;
        }
        //erase everything from the stack
        void clear() {
            delete[] stack;
            top = -1;
            stack = new T[size];
        }  
    private:
        //variable to create dynamic array
        T* stack; 
        //top index
        int top;   
};
#endif