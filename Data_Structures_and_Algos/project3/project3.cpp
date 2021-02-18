#include "DLL.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>


int main(int argc, char** argv) {
    if(argc < 2){ return 0; }

    //local vars
    int inserted = 0;
    int deleted = 0;
    int retrieved = 0;

    clock_t start, end;
    double duration;

    char chr;
    std::string ssn, fname, lname;

    start = clock();

    DLL theList;

    std::fstream input(*(argv + 1));
    while(!input.eof()){
        input >> chr >> ssn >> fname >> lname;
        switch(chr){
            case 'i':
                theList.insert(ssn, fname + " " + lname, inserted);
                break;
            case 'r':
                if(theList.search(ssn)){
                    retrieved++;
                }else{
                    retrieved--;
                }
                break;
            case 'd':
                theList.remove(ssn, deleted);
                break;
        }
    }
    input.close();

    end = clock();
    duration = ( end - start ) / (double) CLOCKS_PER_SEC;

    int itemsC = inserted - deleted;
    cout.precision(5);
    std::cout << "The Number of Valid Insertation: " << inserted << std::endl;
    std::cout << "The Number of Valid Deletion: " << deleted << std::endl;
    std::cout << "The Number of Valid Retrieval: " << retrieved << std::endl;
    std::cout << "Item numbers in the list: " << itemsC << std::endl;
    std::cout << "Time elapsed: " << fixed << duration << std::endl;
    
    return 0;
}