

//


#include <iostream>
class TowerHanoi
{
private:
    int moves, discs;
    void algorithm(int m, char a,char b, char c);
public:
    TowerHanoi(int d);
    int getMoves() {
        algorithm(discs, 'A', 'B', 'C');        
        return moves;
    }
};

TowerHanoi::TowerHanoi(int d)
{
    moves = 0;
    discs = d;
}

void TowerHanoi::algorithm(int m, char a, char b, char c){
  moves++;
  if(m == 1){
    std::cout << "Move disc " << m << " from " << a << " to " << c << "\n";
  }else{  
    algorithm(m-1, a,c,b);
    std::cout << "Move disc " << m << " from " << a << " to " << c << "\n";
    algorithm(m-1,b,a,c);
  }
}

int main(){
    int discs;
    std::cout << "Enter the number of discs: ";
    std::cin >> discs;
    TowerHanoi solution(discs);

    std::cout << "It took " << solution.getMoves() << " moves. \n";
    return 0;
}