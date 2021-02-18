
// Project 1: driver.cpp

#include <iostream>
#include "WordSearch.hpp"

int main(int argc, char **argv) {
    // get row and column
    int row, col;
    std::cin >> row >> col;
    //initialize the 2x2 word matrix
    vector< vector<Node> > matrix;
    matrix.resize(row);
    //read the matrix from the input file
    for(int i = 0; i < row; ++i){
        matrix[i].resize(col);
        for(int j = 0; j < col; ++j){
            //insert nodes in the matrix
            Node n;
            std::cin >> n.ch;
            n.sol = false;
            matrix[i][j] = n;
        }
    }
    // create a word search object 
    // init with row, col, & matrix
    WordSearch wordsearch(row,col, matrix);
    // pass in command line arguments
    wordsearch.solve(argc, argv);

    return 0;
}

