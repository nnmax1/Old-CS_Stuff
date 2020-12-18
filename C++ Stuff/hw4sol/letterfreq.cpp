
#include <iostream>
#include <fstream>
#include <cctype>   // for character functions

using std::string;
using std::ifstream;
using std::ofstream;

// Global constants
constexpr unsigned int A_OFFSET = 97;  // ASCII code for 'a'
constexpr unsigned int NUMLTRS = 26;   // English alphabet

// 2D array for the letter frequencies
unsigned int ltrct[NUMLTRS][2];




void init_array(unsigned int arr2d[][2], unsigned int dim1);

void get_letter_freq(ifstream &infile, unsigned int arr2d[][2]);


void rev_sort_2d_array(unsigned int arr2d[][2], unsigned int dim1);

void print_frequencies(const unsigned int arr2d[][2], unsigned int dim1);

// Print a 2D array.  
void print_2d_array(const unsigned int arr2d[][2], unsigned int dim1);

int main()
{
    string fname;
    ifstream infile;

    init_array(ltrct, NUMLTRS);
    openfile(infile, fname);
    get_letter_freq(infile, ltrct);

    // We can close the file -- don't need it anymore
    infile.close();

//Debug: print_2d_array(ltrct, NUMLTRS);       
    rev_sort_2d_array(ltrct, NUMLTRS);
    print_frequencies(ltrct, NUMLTRS);

    return 0;
}


void init_array(unsigned int arr2d[][2], unsigned int dim1)
{
    unsigned int i;

    // fill first column of the array with ASCII code for lowercase letters
    for (i = 0; i < NUMLTRS; ++i)
        ltrct[i][0] = i + A_OFFSET;

    return;
}


void get_letter_freq(ifstream &infile, unsigned int arr2d[][2])
{
    char ch;
    infile.get(ch);
    while (!infile.eof())
    {
        if (isalpha(ch))
            arr2d[static_cast<unsigned int>(tolower(ch)) - A_OFFSET][1]++;
        infile.get(ch);
    }
    return;
}


void print_frequencies(const unsigned int arr2d[][2], unsigned int dim1)
{
    for(unsigned int i = 0; i < dim1; ++i)
        if (arr2d[i][1])
        {
            std::cout << static_cast<char>(arr2d[i][0]) << " " 
                << arr2d[i][1] << std::endl; 
        }
    return;
}


void openfile(std::ifstream &infile, std::string &filename)
{
    using namespace std;
    cout << "Name of data file: ";
    cin >> filename;

    infile.open(filename);
    if (infile.fail( ))
    {
        cout << filename <<  ": file open failed.\n";
        exit(1);
    }
    return;
}


void rev_sort_2d_array(unsigned int arr2d[][2], unsigned int dim1)
{
    unsigned int temp;
    for (int i = dim1 - 1; i > 0; i--)
    {
        for (int j = 0; j < i; ++j)
        {
            if (arr2d[j][1] < arr2d[j + 1][1])
            {   // swap letters
                temp = arr2d[j + 1][0];
                arr2d[j + 1][0] = arr2d[j][0];
                arr2d[j][0] = temp;
                // swap numbers
                temp = arr2d[j + 1][1];
                arr2d[j + 1][1] = arr2d[j][1];
                arr2d[j][1] = temp;
            }
        }
    }
    return;
}


void print_2d_array(const unsigned int arr2d[][2], unsigned int dim1)
{
    for(unsigned int i = 0; i < dim1; ++i)
        std::cout << static_cast<char>(arr2d[i][0]) << " " 
                  << arr2d[i][1] << std::endl; 
    return;
}

