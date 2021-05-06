#include<iostream>
#include <fstream>

// doubly linkedlist example

using namespace std;

struct Person{  
    string SSN;  
    string name;
};
template <class T>
struct Node{  
    T data;  
    Node<T>* prev;  
    Node<T>* next;
};

// generic linkedlist insert
template <class T>
void insert(Node<T>*& head, T*data) {    
    if(head == NULL){
        head = data;
    }else{
        Node<T>* n = data;
        while(n->next != NULL){
            if(n->SSN < add->SSN){
                n = n->next;
            }else if(n == head){
                // swap head and add Nodes
                Node<T>* temp = head;                
                head = data;
                head->next = temp;
                temp->prev= head;
                return;
            }else{
                //insert add Node before n
                Node<T>* temp = n->prev;
                data = n;
                n->prev =data;
                temp->next = data;
                data = temp;
                return;
            }
        }
        n->next = data;
        data->prev= n;
    }

}

template <class T, class U>
int search(Node<T>* head, U data) {
    if(head != NULL){
        int pos = 0; 
        Node<T>* n = head;
        while(n != NULL){
            if(data == n->data.SSN ){ 
                return pos;
            }
            pos++;
            n = n->next;
        }
       return -1;
    }
}
template <class T>
void print(Node<T>* head) {
    std::cout << "Elements:\n" ;
    Node<T>* n = head;
    // traverse the linkedlist and print each value
    while(n != NULL){
        std::cout << n->data.SSN << "\n";
        n = n->next;
    }
}

// use sample_data.txt as the input file
int main(int argc, char**argv){  
    Node<Person>* head = NULL;  
    // Implement the functionality of the lab using insert, serach and print method.  
    char ch;
    std::string ssn, fname, lname;
    Node<Person>* headNode = NULL; 
    // get filename from arguments
    // and open file
    std::fstream input(*(argv + 1));
    // read data from file
    while(!input.eof()){
        Person* p = new Person; 
        // store data from file in temp vars
        input >> ch >> ssn >> fname >> lname;
        // store data in temporary Node var
        p->SSN = ssn;
        p->name = fname + " " + lname;
        //insert node into linkedlist
        insert(headNode, p);
    }
    input.close(); 

    // user input
    std::string inputSSN;
    std::cout << "Input a SSN:\n" ;
    std::cin >> inputSSN;
    search(headNode, inputSSN);
    print(headNode);


    return 0;
}