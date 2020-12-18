// Lab 1. 
// Problem 1: write a program that outputs the sum of the digits
// for a 2-digit integer.
#include <iostream>
using namespace std;


//TODO: write a function that prompts the user for a 2-digit integer
//      and SETS an int variable with the user's value.
void get_number(int &in_val)
{
    do
    {
        cout << "Enter a 2-digit number: ";
        cin  >> in_val;
    } while (in_val < 10 || in_val > 99);
}


//TODO: write a function that takes a 2-digit int and returns the sum of
//      the digits.
int sum_digits(int num)
{
    return num / 10 + num % 10;
}


int main()
{
    int my_number = 0;
    get_number(my_number);
    cout << "You entered " << my_number << endl;
    cout << "The sum of the digits is " << sum_digits(my_number) << endl;
    return 0;
}
