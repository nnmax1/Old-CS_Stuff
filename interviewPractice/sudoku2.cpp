
#include <vector>
#include <iostream>


bool sudoku2(std::vector<std::vector<char>> grid) {
        int val = 0;
        int n = 9, x, y, r, c;
        
        //check each row
        for(r = 0; r < n; r++){
            val = 0;
            for(c = 0; c < n; c++){
                if(grid[r][c] != '.'){
                    if(val&(1 << (grid[r][c] - '0'))) 
                        return false;
                    val |= (1 << (grid[r][c] - '0'));
                }
            }
        }
        
        //check each column
        for(r = 0; r < n; r++){
            val = 0;
            for(c = 0; c < n; c++){
                if(grid[c][r] != '.'){
                    if(val&(1 << (grid[c][r] - '0'))) return false;
                    val |= (1 << (grid[c][r] - '0'));
                }
            }
        }
        
        //check each vector inside the vector
        for(x = 0; x < 3; x++){
            for(y = 0; y < 3; y++){
                val = 0;
                for(r = 3*x; r < 3*(x + 1); r++){
                    for(c = 3*y; c < 3*(y + 1); c++){
                        if(grid[r][c] != '.'){
                            if(val&(1 << (grid[r][c] - '0')))
                                return false;
                            val |= (1 << (grid[r][c] - '0'));
                        }
                    }
                }
            }
        }
        
        return true;
}

//test sudoku2()
int main() {
    std::vector<std::vector<char>> test =   
    { {'.','.','.','1','4','.','.','2','.'}, 
    {'.','.','6','.','.','.','.','.','.'}, 
    {'.','.','.','.','.','.','.','.','.'}, 
    {'.','.','1','.','.','.','.','.','.'}, 
    {'.','6','7','.','.','.','.','.','9'}, 
    {'.','.','.','.','.','.','8','1','.'}, 
    {'.','3','.','.','.','.','.','.','6'}, 
    {'.','.','.','.','.','7','.','.','.'},  
    {'.','.','.','5','.','.','.','7','.'}};


    if(sudoku2(test)) {
        std::cout<<"valid sudoku\n";
    }
}
