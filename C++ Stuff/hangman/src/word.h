#ifndef _WORD_H_
#define _WORD_H_

//interface file for word class

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

//class definition
class Word {

    public:
    //default constructor
    Word();
    //Returns a random word from the file words.txt
    std::string get_word();
    
    private:
    //vars
    std::string current_word;
    std::string allwords[2000];
    //member functions
    void set_currentWord();
    void set_allwords();
};



#endif
