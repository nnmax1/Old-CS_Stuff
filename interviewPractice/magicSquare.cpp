

#include <vector>
#include <iostream>


using std::vector;


class Solution {

    public: 
    //empty default constructor
    Solution() {}
    //overloaded constructor to init 
    //the solution w/ a matrix and a magic sum
    Solution(vector<vector<int>>matrix, int magicsum) {
        m = matrix;
        sum = magicsum;
    }
    //method true is magic square is a magic square, false otherwise
    bool checkMagicSquare() {
        if(checkRows() && checkCols() && diagonalChecker()) {
            return true;
        }
        return false;
    }
    //method that does the same as the overloaded constructor
    void setMagicSquare(vector<vector<int>>matrix, int magicsum) {
        m = matrix;
        sum = magicsum;
    }
    //method to print a matrix to console
    void showMatrix() {
        for(int i=0;i<m[0].size();i++) {
            for(int j=0;j<m.size();j++) {
                std::cout<<m[i][j]<<" ";
            }
        std::cout<<"\n";
        }
    }
    private:
    //matrix vars
    vector<vector<int>>m;
    //magic sum var
    int sum;
    //method to check rows of magic square
    bool checkRows() {
        for(auto row : m ) {
            int rowSum =0;
            for(int i=0;i<row.size();i++) {
                rowSum += row[i];
            }
            if(rowSum != sum) {return false;}
        }
        return true;
    }
    //method to check columns of magic square
    bool checkCols() {
        int n = m.size();
        for(int r=0;r<n;r++) {
            int colSum =0;
            for(int c=0;c<n;c++) {
                colSum += m[c][r];
            }
            if(colSum != sum) {return false;}
        }
        return true;
    }
    //method to check diags of magic square
    bool diagonalChecker() {
         //check diagonals
        int n = m.size();
        int diagSum1=0, diagSum2=0;
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j < n; j++) { 
                //principle diagonal
                if(i ==j) diagSum1 += m[i][j] ;  
            } 
        } 
        for(int i=0;i<n;i++ ){
            for(int j=0;j<n;j++) {
                //secondary diagonal
                if ((i + j) == (n - 1)) diagSum2 += m[i][j];
            }
        }
        if(diagSum1 != sum ||diagSum2 != sum) return false;
        return true;
    }
};

//function to test Solution on various matrices and their magic sums
void runTests(vector<vector<vector<int>>> matrices, vector<int> magicSums) {
    Solution *tests;
    tests = new Solution[matrices.size()];

    for(int i=0;i<matrices.size();i++) {
        tests[i].setMagicSquare(matrices[i], magicSums[i]);
        tests[i].showMatrix();
        if(tests[i].checkMagicSquare()) {
            std::cout<<"is a Magic Square\n";
        }else {
            std::cout<<"is not a Magic Square\n";
        }
        std::cout<<"-------------------------\n";
    }
    delete [] tests;
}




//test Solution:
int main() {

//sample inputs:
vector<vector<int>>matrix1 = {{8, 1, 6}, 
                              {3, 5, 7},
                              {4, 9, 2}};
vector<vector<int>>matrix2 = {{1, 2, 3},
                              {4, 5, 6},
                              {7, 8, 9}};
vector<vector<int>>matrix3 = {{17, 24, 1, 8, 15}, 
                              {23, 5, 7, 14, 16}, 
                              {4, 6, 13, 20, 22}, 
                              {10, 12, 19, 21, 3}, 
                              {11, 18, 25, 2 ,9}};
vector<vector<int>>matrix4 = { { 1, 0 },
                                {0 , 1 }};
vector<int> magicSums = {15, 6, 65, 1};

vector<vector<vector<int>>> matrices = {matrix1, matrix2, matrix3, matrix4};

//test Solution on inputs above
runTests(matrices, magicSums);


    return 0;

}