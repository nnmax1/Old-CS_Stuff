

#include <vector>
#include <iostream>
std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>>&A) {

    for(int i=0;i<A.size();i++) {
        int j=0;
        int k = A[i].size() -1;
        while(j < k) {
            //reverse
            int temp = A[i][j];
            A[i][j++] = A[i][k];
            A[i][k--] = temp;
        }
        //invert
        for(int j=0;j<A.size();j++) {
            A[i][j] = A[i][j] == 1 ?  0 : 1;
        }
    }
    return A;
}
int main() {
     std::vector<std::vector<int>> test = {{1,1,0,0}, 
        {1,0,0,1}, 
        {0,1,1,1}, 
        {1,0,1,0}};
    
      std::vector<std::vector<int>> res = flipAndInvertImage(test);

      for(auto r: res) {
          for(auto e: r ) {
              std::cout<<e <<" ";
          }
          std::cout<<"\n";
      }
}