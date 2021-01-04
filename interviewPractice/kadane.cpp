//kadane's algorithm 

#include <vector>
#include <iostream>

int kadane(std::vector<int> weights) {
    int max_curr =0;
    int max_end =0;
    for(auto w : weights) {
        //update max sum of sub array
        max_end = max_end + w;
        //if max sum is <0, set it to 0
        max_end = std::max(max_end,0);  
        //update if curr. sub-array is larger
        max_curr = std::max(max_curr, max_end);
    }
    return max_curr;
}
int main() {
    std::vector<int>weights = {28 ,54, 20, 18, 34, 15, 19, 49, 59, 61};
    int res = kadane(weights);

    std::cout<<"Max: "<<res<<"\n";
    return 0;

}