
//test the solution

#include <vector>
#include <iostream>
#include "solution.hpp"


//print elements (formatted) of vector to console
void printList(std::vector<int> v) {
    int counter =0;
    for(int p : v){
        std::cout<<p;
        if(counter % 5 == 0 && counter !=0) {
            std::cout<<"\n";
        }else {
            std::cout<<", ";
        }
        counter++;
    }
}

int main(void) {
    Solution test("numbers.txt");
    std::vector<int> primes; 
    primes = test.getDistinctPrimes();
    //print list of distinct primes to console
    printList(primes);
    return 0;
}