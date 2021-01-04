
#include <iostream>
#include <vector>

std::vector<std::vector<int>> rotateImage(std::vector<std::vector<int>> a) {
    
    int N = a.size();
    //iterate over the 2D vector
    for (int i = 0; i < N / 2; i++) { 
        for (int j = i; j < N - i - 1; j++) { 
  
            // Swap elements of each cycle 
            // in clockwise direction 
            int temp = a[i][j]; 
            a[i][j] = a[N - 1 - j][i]; 
            a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j]; 
            a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i]; 
            a[j][N - 1 - i] = temp; 
        } 
    } 
    return a;
}

//test in main()
int main() {
 std::vector<std::vector<int>> test = {{10,9,6,3,7}, 
 {6,10,2,9,7}, 
 {7,6,3,8,2}, 
 {8,9,7,9,9}, 
 {6,8,6,8,2}};

std::vector<std::vector<int>> result = rotateImage(test);

    for(auto r : result) {
        for(int e : r) {
            std::cout<<e<<" ";
        }
        std::cout<<"\n";
    }
    return 0;
}