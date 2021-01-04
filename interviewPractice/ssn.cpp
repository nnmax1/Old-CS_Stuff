

#include <regex>
#include<iostream>
#include <string>


//a valid ssn is  XXX-XX-XXXX where X is a digit 0-9


bool isSSNValid(std::string ssn) {

    std::string validSSN = R"(\d{3}-\d{2}-\d{4})";
    //create a regex object 
    std::regex regssn(validSSN);

    //the string valiidSSN is now represented
    //as a regular expression thru the variable regssn
    
    //regex_match a regular expression to see if it matches
    if(regex_match(ssn, regssn)){
       return true;
    }
    return false;
}

int main() {

    std::string ssn;

    std::cout<<"Enter a social security number: ";
    getline(std::cin, ssn);

    if(isSSNValid(ssn)) {
        std::cout<<"SSN is in correct format: \n";
    }else {
        std::cout<<"SSN is not in the correct format: \n";
    }
    return 0;
}