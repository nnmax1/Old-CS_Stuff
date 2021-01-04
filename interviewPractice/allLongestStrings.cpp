#include <vector>
#include <iostream>
std::vector<std::string> allLongestStrings(std::vector<std::string> inputArray) {
    
    int longestLen;
    std::vector<std::string>results ;
        
    //get length of longest String
    for(int i=0;i< inputArray.size();i++) {
        if(inputArray[i].length() > longestLen ) {
            longestLen = inputArray[i].length();
        }
    }
    //store elements in the results that have a length of longestLen
    for(int i=0;i<inputArray.size();i++) {
        if(inputArray[i].length() == longestLen) {
            results.push_back(inputArray[i]);
        }
    }
    
    return results;
    
}
