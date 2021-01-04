
//Fun Fact: I actually Ran into this problem during my technical assesment for Robinhood (SWE Intern, IOS Position)
 

#include <vector>
#include <iostream>
using std::vector;

vector<bool> checkOperations(vector<int> a,vector<char>signs, vector<int>b, vector<int>c) {
    vector<bool>results;
    for(int i=0;i<a.size();i++) {
        if(signs[i] == '+') {
            if(a[i] + b[i] == c[i]) {
                results.push_back(true);
            }
            else {
                results.push_back(false);
            }
        }
        if(signs[i] == '-') {
            if(a[i] - b[i] == c[i]) {
                results.push_back(true);
            }
            else {
                results.push_back(false);
            }
        }
    }
    return results;
}
int main() {
    vector<int> a = {3, 9, 9, 11}, b = {8, 9, 2, 9},c=  {11, 0, 13, 2};
    vector<char> signs = {'+', '-','+', '-' };
    vector<bool> result;

    result = checkOperations(a, signs, b, c);

    for(bool r : result)
        if(r)
            std::cout<<"true"<<" ";
        else 
            std::cout<<"false"<<" ";
    std::cout<<"\n";

    return 0;
}