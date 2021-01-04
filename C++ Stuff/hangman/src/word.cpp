

//implementation file for word class

#include "word.h"


Word::Word() 
{
    current_word= "NO_WORD!";
}
void Word::set_allwords() {
    std::ifstream read;
    read.open("words.txt");
    if(read.fail()){
        std::cout<<"ERROR! file open for reading failed.\n";
    }
    for(int i=0;i<2000;i++){
        read >> allwords[i];
    }
    read.close();
}
void Word::set_currentWord()
{
    int word_index,i=0;
    srand(time(NULL));
    while(i<100){ 
        word_index = rand()%2000 +1;
        i++;
    }
    current_word = allwords[word_index-1];
}
std::string Word::get_word()
{
    set_allwords();
    set_currentWord();
    return current_word;
}