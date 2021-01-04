#include <vector>
#include <iostream>
using std::vector;
int matrixElementsSum(vector<vector<int>> matrix) {
    int sum = 0;

    for(int i = 0; i < matrix[0].size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            if (matrix[j][i] == 0) {
                break;
            }
            sum += matrix[j][i];
        }
    }
    return sum;

}

int main() {
   vector<vector<int>> testMatrix ={{0,1,1,2}, 
                                    {0,5,0,0}, 
                                    {2,0,3,3}};
    std::cout<<"matrixElementsSum: "<< matrixElementsSum(testMatrix);
}