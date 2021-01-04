#include "ttt.h"

//Tic Tac Toe implementation file

#include <ctime>
#include <cstdlib>
#include "consolefunctions.h"
using namespace console_functions;
    //default constructor
    TicTacToe::TicTacToe() 
    {
        turn =1;
        moves=0;
    }
    //function to play a game of TTT
    void TicTacToe::playGame()
    {
        srand(time(0));
        initBoard();
        turn = getTurn();
        do {
            if(turn==1)
            {
                showBoard();
                playerX();
                turn++;
                moves++;
                //exit loop if won
                if(checkWin('X')){turn=3;}
            }
            if(turn==2)
            {
                showBoard();
                playerO();
                turn--;
                moves++;
                //exit loop if won
                if(checkWin('O')){turn=3;}
            }
        }while(moves<9&&turn <3);
        showBoard();
        if(checkWin('X')) {print("Player X Won!\n");}
        else if(checkWin('O')) {print("Player O Won!\n");}
        else{print("Tie Game!\n");}
        //reset moves back to 0
        moves=0;
    }
    //generate a random number to determine which player goes first
    int TicTacToe::getTurn()
    {
        srand(time(NULL));
        return rand()%2 +1;
    }
    //initialize board with numbers 1-9 in each square
    void TicTacToe::initBoard()
    {
        char ch = '1';
        for(int r=0; r<3;r++)
        { 
            for(int c=0; c<3; c++)
            {
                board[r][c] = ch;
                ch++;
            }
        }
    }
    //show board
    void TicTacToe::showBoard()
    {
        for(int r=0;r<3;r++)
        {
            for(int c=0;c<3;c++)
            {
                print(board[r][c]);
                print(" ");
                if(c <2 ){print(" | ");}
                if(c==2){print("\n");}
            }
            if(r < 2){print("------------\n");}
        }
    }
    //checks if spot is taken
    bool TicTacToe::spotTaken(int r, int c)
    {
        if(board[r][c]=='X' || board[r][c]=='O'){return true;}
        return false;
    }
    //insert XO on the board
    void TicTacToe::insertXO(int r, int c, char ch)
    {
        board[r][c]=ch;
    }
    //places an X or O on the board based on which square the user selects
    int TicTacToe::placeXO(int pos, char ch)
    {
        switch(pos)
        {
            case 1:
                if(spotTaken(0,0)) {print("Spot is already taken\n"); return -1;}
                else {insertXO(0,0,ch);return 0; }
            break;
            case 2:
                if(spotTaken(0,1)) {print("Spot is already taken\n"); return -1;}
                else {insertXO(0,1,ch);return 0; }
            break;
            case 3:
                if(spotTaken(0,2)) {print("Spot is already taken\n"); return -1;}
                else {insertXO(0,2,ch);return 0; }
            break;
            case 4:
                if(spotTaken(1,0)) {print("Spot is already taken\n"); return -1;}
                else {insertXO(1,0,ch);return 0; }
            break;
            case 5:
                if(spotTaken(1,1)) {print("Spot is already taken\n"); return -1;}
                else {insertXO(1,1,ch);return 0; }
            break;
            case 6:
                if(spotTaken(1,2)) {print("Spot is already taken\n"); return -1;}
                else {insertXO(1,2,ch);return 0; }
            break;
            case 7:
                if(spotTaken(2,0)) {print("Spot is already taken\n"); return -1;}
                else {insertXO(2,0,ch);return 0; }
            break;
            case 8:
                if(spotTaken(2,1)) {print("Spot is already taken\n"); return -1;}
                else {insertXO(2,1,ch);return 0; }
            break;
            case 9:
                if(spotTaken(2,2)) {print("Spot is already taken\n"); return -1;}
                else {insertXO(2,2,ch);return 0; }
            break;
            default: 
            std::cout<<"Invalid Board location\n";
            return -1;
            break;
        }
    }
    //turn for player X
    void TicTacToe::playerX()
    {
        int spot,res;
        print("Player X's turn\n");
        print("Choose a spot (1-9) to place your X: ");
            scanner(spot);
        res= placeXO(spot, 'X');
        while(res ==-1)
        {
            print("Choose another spot: ");
                scanner(spot);
            res= placeXO(spot, 'X');
        }
        if(res==0){print("Player X's turn is over.\n");}
    }
    //turn for player O
    void TicTacToe::playerO()
    {
        int spot,res;
        print("Player O's turn\n");
        print("Choose a spot (1-9) to place your O: ");
            scanner(spot);
        res= placeXO(spot, 'O');
        while(res ==-1)
        {
            print("Choose another spot: ");
                scanner(spot);
            res= placeXO(spot, 'O');
        }
        if(res==0){print("Player O's turn is over.\n");}
    }
    //checks if one of the players has won the game
    bool TicTacToe::checkWin(char ch)
    {
        int r;//row index
        int c;//column index
        
        //horizontal win cases
        for(r=0;r<3;r++)
        {
            if(board[r][0]==ch&&board[r][1]==ch&&board[r][2]==ch){return true;}
        }
        //vertical win cases
        for(c=0;c<3;c++)
        {
            if(board[0][c]==ch&&board[1][c]==ch&&board[2][c]==ch){return true;}
        }
        //diagonal win cases
        if(board[0][0]==ch&&board[1][1]==ch&&board[2][2]==ch){return true;}
        if(board[2][0]==ch&&board[1][1]==ch&&board[0][2]==ch){return true;}

        return false;
    }