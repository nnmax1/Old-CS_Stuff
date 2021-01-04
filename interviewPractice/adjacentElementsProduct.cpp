#include <vector>
#include <iostream>

int adjacentElementsProduct(std::vector<int> inputArray) {
    int largestProduct=inputArray[0]*inputArray[1],temp;
    
    if(inputArray.size()== 1){return 0;}
    for(int i=0;i<inputArray.size()-1;i++)
    {

        temp = inputArray[i] * inputArray[i+1];
        if(temp > largestProduct)
        {
          largestProduct = temp;
        }
    }
    return largestProduct;
}
int main() {
    std::vector<int> test = {3, 6, -2, -5, 7, 3};

    int product = adjacentElementsProduct(test);
    std::cout<<"Product: "<<product<<"\n";
}
