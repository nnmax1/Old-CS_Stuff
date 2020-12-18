
// Program to demonstrate a function template.
// Adapted from DISPLAY 17.1 A Function Template in Savitch.
#include <iostream>
using namespace std;

//Interchanges the values of variable1 and variable2.
template<typename T>
void swapValues(T &var1, T &var2)
{
      T temp;

      temp = var1;
      var1 = var2;
      var2 = temp;
}

int main( )
{
    int integer1 = 1, integer2 = 2;
    cout << "Original integer values are "
         << integer1 << " " << integer2 << endl;
    swapValues(integer1, integer2);
    cout << "Swapped integer values are "
         << integer1 << " " << integer2 << endl;

    char symbol1 = 'A', symbol2 = 'B';
    cout << "Original character values are "
         << symbol1 << " " << symbol2 << endl;
    swapValues(symbol1, symbol2);
    cout << "Swapped character values are "
         << symbol1 << " " << symbol2 << endl;

    return 0;
}

