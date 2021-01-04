
//bottom -up solution to the knap sack problem 


#include <vector>
#include <iostream>

//return max of two integers 
int max(int a, int b) { 
    return (a > b) ? a : b; 
} 
  
//returns max value that can be carried in the knap sack
int knapSack(int cap, std::vector<int>weights, std::vector<int> values) {     
    int sz = values.size();
    int s[sz + 1][cap + 1]; 
    for (int i = 0; i <= sz; i++) { 
        for (int j = 0; j <= cap; j++) { 
            if (i == 0 || j == 0) s[i][j] = 0; 
            else if (weights[i - 1] <= j)  {
                s[i][j] = max(values[i - 1] + s[i - 1][j - weights[i - 1]], s[i - 1][j]); 
            }
            else s[i][j] = s[i - 1][j]; 
        } 
    } 
  
    return s[sz][cap]; 
} 
  
int main() {
    std::vector<int> values = { 10, 80, 70, 60, 100 }; 
    std::vector<int> weights ={ 5, 35, 20, 25, 15 }; 
    int capacity = 50; 
    std::cout<<"knapSack result: "<<knapSack(capacity, weights, values)<<"\n"; //180
    
    return 0; 
}