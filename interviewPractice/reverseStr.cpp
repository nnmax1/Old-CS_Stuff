

//string reversal functions

#include <cstring>
#include <iostream>
//access data structures
#include <stack>
#include <queue>
#include <vector>

class ReverseStr {
    public: 
    //recursive algo to reverse string
    void recursiveAlgo(char str[], int&begin, int&end)
    {
        char temp,temp2;
        if(begin > end) { return;}
        else { 
            temp=str[begin];
            temp2=str[end];
            str[end--]=temp;
            str[begin++]=temp2;
            recursiveAlgo(str,begin,end);
        }
    }
    //iterative algo to reverse cstring
    void iterativeAlgo(char str[])
    {
        int begin=0;
        int end = strlen(str)-1;
        char temp,temp2;
        while(begin <end)
        {
            temp=str[begin];
            temp2=str[end];
            str[begin++]=temp2;
            str[end--]=temp;
        }
    }
    //reverse cstring using a stack
    void stackAlgo(char str[])
    {
        std::stack <char> s;
        int i=0;
        while(str[i] !='\0')
        {
            s.push(str[i++]);
        }
        //reset i to 0
        i=0;
        while(!s.empty())
        {
            str[i]=s.top();
            s.pop();
            i++;
        }   
    }
    //reverse cstring using queue
    void queueAlgo(char str[])
    {
        std::queue <char> q;
        int i=0;
        int len = strlen(str)-1;
        while(str[i]!='\0')
        {
            q.push(str[i++]);
        }
        while(!q.empty())
        {
            str[len]=q.front();
            q.pop();
            len--;
        }
    }
    //reverse cstring using vector
    void vectorAlgo(char str[])
    {
        std::vector <char> v;
        int i=0;
        while(str[i]!='\0')
        {
            v.push_back(str[i++]);
        }
        i=0;
        while(!v.empty())
        {
            str[i]=v.back();
            v.pop_back();
            i++;
        }
    }
};

int main(void) 
{
    //std::cout<<"Recursive Method: \n";
    //std::cout<<"Iterative Method: \n";
    //std::cout<<"Reversal using a stack \n";
    std::cout<<"Reversal using a queue \n";

    ReverseStr reversestr;
    char str1[200];
    std::cout<<"Enter a cstring : ";
    std::cin.getline(str1,200,'\n');
    std::cout<<"----------------------------\n";
    //for recursive algo
    int b=0;
    int e= strlen(str1) -1;
 
    std::cout<<"----------------------------\n";
    std::cout<<"Before reversal: "<<str1<<"\n";
    //reversestr.recursiveAlgo(str1, b, e);
    //reversestr.iterativeAlgo(str1);
    //reversestr.stackAlgo(str1);
    reversestr.queueAlgo(str1);
    //reversestr.vectorAlgo(str1);
    std::cout<<"After reversal: "<<str1<<"\n";
    std::cout<<"----------------------------\n";

    return 0;
}