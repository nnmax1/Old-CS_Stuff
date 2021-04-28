#include <iostream>
#include <fstream>
#include "hashTable.h"
#include <string>
#include <time.h>
#include <ctime>

using namespace std;

int main(int argc, char* argv[]){

  // implement this missing part
  // make the array size inside the hash table is 10007
  
  // need filename
  if(argc < 2){ return 0; } 
  // hashtable var
  HashTable<string>* theTable = new HashTable<string>(10007);   

    //intialize variables
    int inserted = 0;
    int deleted = 0;
    int retrieved = 0;
    clock_t start, end;
    double duration;
    char chr;
    string ssn, fname, lname;
    start = clock();
    //open file 
    fstream input(argv[1]);
    // read data from file
    while(!input.eof()){
      // input line
      input >> chr >> ssn >> fname >> lname;
      switch(chr){
        // insert operation
        case 'i' :
          if(theTable->insert(ssn, fname + " " + lname)){
            inserted++;
          }else{
            inserted--;
          }
          break;
        // retrieve operation
        case 'r' :
          if(theTable->find(ssn)){
            retrieved++;
          }else{
            retrieved--;
          }
          break;
        // delete operation
        case 'd' :
          if(theTable->erase(ssn)){
            deleted++;
          }else{
            deleted--;
          }
          break;
      }
    }
    input.close(); 
    end = clock();
    duration = ( end - start ) / (double) CLOCKS_PER_SEC;
    // adjust itemsC
    int itemsC = inserted - deleted;
    cout.precision(5);
    // print results
    cout << "The Number of Valid Insertation: " << inserted << endl;
    cout << "The Number of Valid Deletion: " << deleted << endl;
    cout << "The Number of Valid Retrieval: " << retrieved << endl;
    cout << "Item numbers in the list: " << itemsC << endl;
    cout << "Time elapsed: " << fixed << duration << endl;
    
}
