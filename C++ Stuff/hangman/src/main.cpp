

#include "hangman.h"

int main() {
    char again;
    Hangman hangman;
    do {
        hangman.playGame();
        std::cout<<"Do you want to play again?[Y/n]: ";
            std::cin >> again;
        std::cout<<"\n";
        std::cout<<"--------------------------------------\n";
    }while(again == 'Y' || again =='y');

    return 0;
}