

#include "ttt.h"
#include "consolefunctions.h"

int main(void) 
{
    char again;
    do {
    //TicTacToe object
    TicTacToe ttt;
    ttt.playGame();
    console_functions::print("Play again?[Y/n]: ");
    console_functions::scanner(again);
    }while(again=='Y'||again=='y');

    return 0;
}