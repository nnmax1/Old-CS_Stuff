//implementation file for Solution class

#include <fstream> //std::ifstream
#include <sstream> //std::istringstream
#include <iostream>
#include <algorithm> //std::sort
#include <cstdlib>

#include "solution.hpp"

    //getDistinctPrimes()
    std::vector<int> Solution::getDistinctPrimes() {
        std::vector<int> res;
        std::ifstream reader;
        reader.open(filename);
        if(reader.fail()) {
            std::cout<<filename<<" failed to open. exit w/ code 1\n";
            exit(1);
        }    
        std::string temp, str;
        std::vector<int>primes;
        while(!reader.eof()) {
            reader>>temp;
            replaceDash(temp);
            std::istringstream s(temp);
            while(s >> str) {
                int num = std::stoi(str);
                if(isPrime(num)) {
                    primes.push_back(num);
                }
            }
        }
        reader.close();
        res = onlyDistinct(primes);
        return res;
    }
    //replace dash w/ a space
    void Solution::replaceDash(std::string &str) {
        for(int i=0;i<str.length();i++) {
            if(str.at(i) == '-') {
                str.at(i) = ' ';
            }
        }
    }
    //check if integer is a prime number
    bool Solution::isPrime(int n){
        bool prime = true;
    
        for (int i = 2; i <= n / 2; ++i) {
            //check if n is composite
            if (n % i == 0) {
                prime = false;
                break;
            }
        }
        //1 is not prime nor composite
        if (n == 1) return false; 
        //if n is prime, return true
        if (prime) return true;

        return false;
    }
    //return a list of only distinct values based on an input list.
    std::vector<int> Solution::onlyDistinct(std::vector<int> p) {
        std::vector<int> result;
        std::sort(p.begin(), p.end());
        int n = p.size();
        for(int i=0; i<n;i++) {
            if(p[i] != p[i-1] && i !=0) {
                result.push_back(p[i]);
            }
        }
        return result;
    }
    
    void setFilename(std::string s) {
        filename = s;
    }

