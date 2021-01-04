//The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

//Given two 32 bit integers x and y, calculate the Hamming distance.


#include <iostream>

class Solution {
public:
    int hammingDistance(int x, int y) {
        //vars
        int counter=0;
        std::string xStr,yStr;
        //convert to binary
        xStr=toBinary(x);
        yStr=toBinary(y);
        
        for(int i=0;i<xStr.length();i++)
        {
            //count the points where the strings are different
            if(xStr.at(i)!= yStr.at(i))
            {
                counter++;
            }
        }
        return counter;
        
    }
private:
    std::string toBinary(int a)
    {
        std::string binary = "";
        int mask = 1;
        //for a 32 bit decimal
        for(int i = 0; i < 31; i++)
        {   
            if((mask&a) >= 1)
                binary = "1"+binary;
            else
                binary = "0"+binary;
            mask<<=1;
        }
        return binary;
    }
};

int main(void) 
{
    Solution test;
    int hammingdist;
    hammingdist = test.hammingDistance(1,4);
    std::cout<<hammingdist<<"\n";

    return 0;
}