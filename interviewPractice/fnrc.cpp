
//first non repeating character  problem

#include <iostream>

char firstNotRepeatingCharacter(std::string str) {
    
  for (int i = 0; i < str.length(); i++) {
    char ch = str.at(i);
    if (str.find(ch) == i && str.find(ch, i + 1) == -1) {
      return ch;
    }
  }
  return '_';
}

int main() {
    std::string tests[2] = {"abacabad", "bcccccccccccccyb"};
    std::cout<<"First non repeating char: "<< firstNotRepeatingCharacter(tests[0])<<"\n";
    std::cout<<"First non repeating char: "<< firstNotRepeatingCharacter(tests[1])<<"\n";
   
    return 0;
}