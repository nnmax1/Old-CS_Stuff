
// Project 1: WordSearcher.hpp
// implementation of the WordSearch Class
#include "WordSearch.hpp"
#include<iostream>
#include <cstring>

WordSearch::WordSearch(int xMax, int yMax,  vector< vector<Node>> m) {
        x = xMax;
        y = yMax;
        matrix = m;
}
void WordSearch::findWord(char* word) {
    // iterate over 2d vector and check all directions
    for(int i = 0; i < matrix.size(); ++i){
        for(int j = 0; j < matrix[0].size(); ++j){
            if(checkWord(word, i, 0, j, 1)){
                drawWord(word, i, 0, j, 1);
            }
            if(checkWord(word, i, 0, j, -1)){
                drawWord(word, i, 0, j, -1);
            }
            if(checkWord(word, i, 1, j, 0)){
                drawWord(word, i, 1, j, 0);
            }
            if(checkWord(word, i, -1, j, 0)){
                drawWord(word, i, -1, j, 0);
            }
            if(checkWord(word, i, 1, j, 1)){
                drawWord(word, i, 1, j, 1);
            }
            if(checkWord(word, i, 1, j, -1)){
                drawWord(word, i, 1, j, -1);
            }
            if(checkWord(word, i, -1, j, -1)){
                drawWord(word, i, -1, j, -1);
            }
            if(checkWord(word, i, -1, j, 1)){
                drawWord(word, i, -1, j, 1);
            }
        }
    }
}

void WordSearch::drawWord(char* word, int x, int delX, int y, int delY){
    int count = 0;
    while(count < strlen(word)){
        matrix[x][y].sol = true;
        count++;
        x += delX;
        y += delY;
    }
}

bool WordSearch::checkWord(char* word, int x, int delX, int y, int delY){
    int count = 0;
    while(count < strlen(word)){
        if(x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size()){ return false; }
        if(matrix[x][y].ch != *(word + count)){ return false; }
        count++;
        x += delX;
        y += delY;
    }
    
    return true;
}

void WordSearch::printMatrix(){
    // print words in grid and * where word is not fount. 
    for(int i = 0; i < matrix.size(); ++i){
        for(int j = 0; j < matrix[0].size(); ++j){
            if(matrix[i][j].sol){
                std::cout << matrix[i][j].ch << " ";
            }else{
                std::cout << "* ";
            }
        }
        std::cout << "\n";
    }
}


void WordSearch::solve(int len, char ** words){
    //loop over the input arguments excluding the name of the program
    for(int i = 1; i <len ; ++i){
        findWord(*(words + i));
    }
    printMatrix();
}