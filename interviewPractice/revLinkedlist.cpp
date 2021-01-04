


#include <forward_list>//STL implementation of a singly-linked list
#include <iostream>

void  reverseLinkedList(std::forward_list<int> &s_list) {
   s_list.reverse();
}
void printElements(std::forward_list<int> s_list) {
   for (int&element : s_list){
        std::cout << element << " "; 
    } 
    std::cout<<"\n";
}
int main() {
    std::forward_list<int> s_list;
    s_list.assign({1,2,3,4,5,6,7,8});

    std::cout<<"Linked List: ";
    printElements(s_list);
    reverseLinkedList(s_list);
    std::cout<<"Linked List Reversed: ";
    printElements(s_list);

}