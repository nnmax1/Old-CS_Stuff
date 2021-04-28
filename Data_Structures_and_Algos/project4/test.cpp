#include <iostream>
#include <string>
#include "hashTable.h"

using namespace std;

int main(){
  Node<string>* temp = new Node<string>;
  SLL<string>* tempSLL = new SLL<string>;
  HashTable<string>* tempT = new HashTable<string>(10007);
  // test insert()
  tempT->insert("843", "student1");
  tempT->insert("69", "student2");
  tempT->insert("932", "student3");
  tempT->insert("983", "student4");
  cout << "Size: " << tempT->getSize() << endl;
  // test find()
  if(tempT->find("843")){
    cout << "found" << endl;
  }else{
    cout << "not found" << endl;
  }
  // test erase()
  cout << "Deleting element 69" << endl;
  tempT->erase("69");
  cout << "Size: " << tempT->getSize() << endl;

}
