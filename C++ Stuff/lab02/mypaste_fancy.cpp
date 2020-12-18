
// Lab 2.
// Write a program to emulate the paste command.
// This version produces a formatted table.

#include <iostream>
#include <fstream>
#include <cstdlib>   // for exit
#include <iomanip>   // for setw, setprecision

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

    outfile.open("fancypasted.txt");
    if (outfile.fail())
    {
        cout << "File open for writing failed." << endl;
        exit(1);
    }

    string city;
    unsigned int maxlength = 0U;  // for the longest word in cities.txt
    // Read the entire cities.txt file to find the length
    // of the longest city name
    while (infile1 >> city)
    {
        if (city.length() > maxlength)
            maxlength = city.length();
    }
    // In order to read cities.txt a second time, we need to close
    // it first, then open it again
    infile1.close();
    infile1.open("cities.dat");
    if (infile1.fail())
    {
        cout << "File open for reading failed." << endl;
        exit(1);
    }

    double temp;
    outfile.setf(ios::fixed);
    outfile.setf(ios::showpoint);

    // Use manipulators left, right, setw, and setprecision
    while (infile1 >> city && infile2 >> temp)
    {
        outfile << left << setw(maxlength) << city << " " 
                << right << setw(7) << setprecision(2) << temp << endl;
    }
  
    // Close all streams
    infile1.close();
    infile2.close();
    outfile.close();

    return 0;
}
