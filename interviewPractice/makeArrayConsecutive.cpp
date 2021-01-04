#include <vector>
#include <iostream>
int makeArrayConsecutive(std::vector<int> af) {
    std::sort(af.begin(), af.end());
    int curr=0, figsNeeded=0;
    for(int i=af[0];i<af[af.size()-1];i++)
    {
        if(af[curr]!=i){
            statuesNeeded++;
        }else {
            curr++;
        }
    }
    return figsNeeded;

}

int main() {
    std::vector<int> actionFigs = {6, 2, 3, 8};

    std::cout<<"Need: "<<makeArrayConsecutive(actionFigs)<<" figures\n";
    return 0;
}