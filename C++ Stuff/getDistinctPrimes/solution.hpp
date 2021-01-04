#ifndef _SOLUTION_HPP_
#define _SOLUTION_HPP_
#include <string>
#include <vector>

class Solution {
    public:
    //empty default constructor
    //this will cause the program to exit(1) b/c file "no file" can't be opened
    Solution() {filename = "no file";}
    //declare a Solution object with the name of the file
    Solution(std::string f) {
        filename = f;
    }
    //returns a list of all distinct primes in the file
    std::vector<int> getDistinctPrimes();
    void setFilename(std::string);
    private:
    //file name variable
    std::string filename;
    //replace dash w/ a space
    void replaceDash(std::string&);
    //check if integer is a prime number
    bool isPrime(int n);
    //return a list of only distinct values based on an input list.
    std::vector<int> onlyDistinct(std::vector<int> p);
};

#endif