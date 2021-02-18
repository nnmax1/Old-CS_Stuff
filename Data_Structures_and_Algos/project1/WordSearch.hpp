
// Project 1: WordSearcher.hpp
// interface of the WordSearch Class
#ifndef _WORDSEARCH_HPP_
#define _WORDSEARCH_HPP_

#include <vector>
#include <string>

using std::vector;


// Node struct 
struct Node{
    char ch;
    bool sol;
};


class WordSearch{
    public: 
    // constructor
    WordSearch(int, int, vector<vector<Node>>) ;
    // print matrix with words found
    void solve(int , char **);
    private:
    //vars 
    vector< vector<Node> > matrix; // 2x2 word matrix
    int x, y; // x, y coordinates
    //methods
    void findWord(char*);
    void drawWord(char*, int, int, int, int);
    bool checkWord(char*, int, int, int, int);
    void printMatrix();

};

#endif