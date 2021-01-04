//my solution to the detectCapital leetcode problem


#include <iostream>
#include <cctype> //access toupper()

bool checkCapital(std::string word) {

    //count capital letters
    int numCapitals =0;
    //check if first letter is capital
    bool firstLet = false;
    
    //if first letter is capitalized, set firstLet to true
    if(word.at(0) == toupper(word.at(0))) firstLet = true;

    //iterate over word and count capital letters
    for(int i=0;i<word.length();i++) {
        if(word.at(i) == toupper(word.at(i)) ) {
            numCapitals += 1;
        }
    }

    //if all letters are capitalized return true
    if(numCapitals == word.length()) {
        return true;
    }   
    //if 1st letter is the only capitalized letter
    if(numCapitals ==1 && firstLet && firstLet == true ) {
        return true;
    }

    return false;
}

//test checkCapital()
int main() {

    if(checkCapital("HELLO")) {
        std::cout<<"Capital usage is correct in: HELLO\n";
    }
   if(checkCapital("Hello")) {
        std::cout<<"Capital usage is correct in: Hello\n";
    }
   if(!checkCapital("hello")) {
        std::cout<<"Capital usage is incorrect in hello\n";
    }
    if(!checkCapital("HeLLo")) {
        std::cout<<"Capital usage is incorrect in hElLo\n";
    }
}