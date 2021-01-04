#ifndef _HANGMAN_H_
#define _HANGMAN_H_


#include "word.h"
#include <cstring>
#include <cctype>

class Hangman {
    public:
    //constructor
    Hangman();
    //member function to play a game of hangman
    void playGame();
    //destructor
    ~Hangman();
    private:
    std::string word;
    char* player_word;
    int score =0, games_won=0;
    //display functions
    void show_word();
    void show_hangman();
    //get letter/word
    void guessLetter();
    void guessWord();
    //update player's word based on letter's guessed so far
    void update_player_word(char);
    //searches for letter. returns true if letter is found.
    bool letter_search(char);
    //checks if game is won
    bool checkWin(char*);
    //resets score and word
    void reset() ;
};

#endif
