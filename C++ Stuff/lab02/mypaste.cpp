
// Lab 2.
// Write a program to emulate the paste command.

#include <iostream>
#include <fstream>
#include <cstdlib>   // for exit

int main()
{
    using namespace std;
    ifstream infile1, infile2;
    ofstream outfile;

    infile1.open("cities.dat");
    if (infile1.fail())
    {
        cout << "File open for reading failed." << endl;
        exit(1);
    }

    infile2.open("temps.dat");
    if (infile2.fail())
    {
        cout << "File open for reading failed." << endl;
        exit(1);
    }

    outfile.open("pasted.txt");
    if (outfile.fail())
    {
        cout << "File open for writing failed." << endl;
        exit(1);
    }

    string city;
    double temp;

    while (infile1 >> city && infile2 >> temp)
    {
        outfile <<  city << " " << temp << endl;
    }
  
    // Close all streams
    infile1.close();
    infile2.close();
    outfile.close();

    return 0;
}
