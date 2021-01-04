
#ifndef _CONSOLEFUNCTIONS_H_
#define _CONSOLEFUNCTIONS_H_
//namespace of functions that allow programmer to display and read stuff to/from the console

#include <iostream>

namespace console_functions {

//display something to console
template <typename T>
void print(T arg)
{
    std::cout<<arg;
}

//read in input from console
template <typename T2>
void scanner(T2 &arg)
{
    std::cin>>arg;
}
//overloaded scanner to take in two arguments of same type
template <typename T2>
void scanner(T2 &arg, T2 &arg2)
{
    std::cin>>arg>>arg2;
}

}
#endif