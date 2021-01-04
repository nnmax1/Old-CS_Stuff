
#ifndef _TTT_H_
#define _TTT_H_


//Tic Tac Toe interface file

class TicTacToe
{
public:
//constructor
TicTacToe();
//function to play a game of ttt
void playGame();
private:
//vars
char board[3][3];
int turn,moves;
//random number generator that determines which player goes first
int getTurn();
//initialize board with numbers 1-9 in each square
void initBoard();
//display board
void showBoard();
//check if spot on the board is taken
bool spotTaken(int, int);
//insert an X or O onto the board
void insertXO(int, int,char);
//places an X or O on the board based on which square the user selects
int placeXO(int, char);
//player X's turn
void playerX();
//player O's turn
void playerO();
//checks if a player has won the game
bool checkWin(char ch);
};


#endif