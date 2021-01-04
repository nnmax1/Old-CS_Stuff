

#include "hangman.h"


Hangman::Hangman(){
    int len = word.length();
    player_word = new char[len];
    for(int i=0;i<len;i++) { 
        player_word[i]= '?';
    }
}
Hangman::~Hangman() 
{
        delete [] player_word;
}

//function definitions
void Hangman::show_word()
{
    int len = word.length();
    std::cout<<"CURRENT WORD: \n";
    for(int i=0;i<len;i++) {
        if(player_word[i]==word.at(i)){
            std::cout<<word.at(i)<<" ";
        }
        else {
            std::cout<<"__ ";
        }
    }
    std::cout<<"\n";
    std::cout<<"--------------------------------------\n";
}
void Hangman::show_hangman()
{
    std::cout<<"--------------------------------------\n";
    std::cout<<"CURRENT HANGMAN:\n";
    if(score ==0){
        std::cout<<"Nothing hung yet...\n";
    }
    if(score ==1){
        std::cout<<"HEAD\n";
    }
    if(score ==2){
        std::cout<<"HEAD\n";
        std::cout<<"TORSO\n";
    }
    if(score ==3){
        std::cout<<"HEAD\n";
        std::cout<<"TORSO\n";
        std::cout<<"ARM\n";
    }
    if(score ==4){
        std::cout<<"HEAD\n";
        std::cout<<"TORSO\n";
        std::cout<<"2 ARMS\n";
    }
    if(score ==5){
        std::cout<<"HEAD\n";
        std::cout<<"TORSO\n";
        std::cout<<"2 ARMS\n";
        std::cout<<"1 LEG\n";
    }
    std::cout<<"--------------------------------------\n";
}

bool Hangman::letter_search(char letter)
{
    int len = word.length();
    for(int i=0;i<len;i++){
        if(letter == word.at(i)) {
            return true;
        }
    }
    return false;
}
void Hangman::update_player_word(char letter)
{
    int len = word.length();
    for(int i=0;i<len;i++){
        if(letter == word.at(i)) {
            player_word[i] = letter;
        }
    }
}

void Hangman::guessLetter()
{
    char letter, temp;
    std::cout<<"Enter a letter(A-Z): ";
    std::cin>>temp;
    letter = tolower(temp);
    if(letter_search(letter)) {
        update_player_word(letter);
        std::cout<<"The word contains the letter: "<<letter<<"\n";
    }
    if(!letter_search(letter)) {
        std::cout<<"The word does not contain the letter: "<<letter<<"\n";
        score +=1;
    }
}
void Hangman::guessWord()
{
    std::string tempword;
    std::cout<<"Enter the word in all lowercase: ";
    std::cin>>tempword;
    if(tempword == word) {
        std::cout<<"You got the word! You won!\n";
        //end loop
        score =10;
        games_won+=1;
    }
    else {
        std::cout<<"You did not get the word.\n";
        score+=1;
    }
}
bool Hangman::checkWin(char *theword){
    int counter=0;
    int len = word.length();
    for(int i=0;i<len;i++) {
        if(word.at(i)==theword[i]){
            counter++;
        }
    }
    if(counter == len){
        return true;
    }
    return false;
}
void Hangman::reset() {
    score =0;
    int len = word.length();
    for(int i=0;i<len;i++){ 
        player_word[i]= '?';
    }
}

void Hangman::playGame()
{
    char choice;
    Word wordObj;
    word = wordObj.get_word();   
    if(word == "NO_WORD!"){
        std::cout<<"Error! Exiting program...\n";
        exit(1);
    }
    std::cout<<"GAME OF HANGMAN V.S THE COMPUTER.\n";
    std::cout<<"The word is "<<word.length()<<" letters long.\n";
    while(score < 6) { 
        show_hangman();
        show_word();
        std::cout<<"Do you want to guess the word (1) or choose a letter(2)?: ";
        std::cin >> choice;
        switch(choice){
            //guess word option
            case '1':
            guessWord();
            break;
            //choose letter option
            case '2':
            guessLetter();
            if(checkWin(player_word)) {
                std::cout<<"You got the word! You Won!\n";
                std::cout<<"The word is: "<<word<<".\n";
                games_won+=1;
                //end loop
                score=10;
            }
            break;
            //default option is choose a letter
            default:
            guessLetter();
            if(checkWin(player_word)) {
                std::cout<<"You got the word! You Won!\n";
                std::cout<<"The word is: "<<word<<".\n";
                games_won+=1;
                //end loop
                score=10;
            }
            break;
        }
    }
    if(score ==6){
        std::cout<<"Your person was hanged! You lost!\n";
        std::cout<<"The word is: "<<word<<".\n";
    }
    std::cout<<"Games won: "<<games_won<<"\n";
    reset();
}
