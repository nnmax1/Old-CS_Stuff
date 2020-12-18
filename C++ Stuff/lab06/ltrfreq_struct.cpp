
// Lab 6B.  Use a structure to count letter frequencies.

#include <iostream>
#include <fstream>
#include <cctype>   // for character functions

// Using declarations
using std::ifstream;
using std::cout;
using std::cin;
using std::endl;
using std::string;

// Global constants
constexpr unsigned int LOWER_A = 97;    // ASCII code for 'a'
constexpr unsigned int NUMLTRS = 26;    // English alphabet

// A structure for letter frequency
struct LetterCount {
    char letter;
    unsigned int count;
};

typedef struct LetterCount LtrCt;
typedef unsigned int UnsInt;

// Function declarations
void openfile(ifstream &infile, string &filename);
void init_array(LtrCt ltrs[], UnsInt dim1);
void get_letter_freq(ifstream &infile, LtrCt ltrs[]);
void rev_sort_array(LtrCt ltrs[], UnsInt dim1);
void print_frequencies(LtrCt ltrs[], UnsInt dim1);


int main()
{
    // An array of structures for the letter counts
    struct LetterCount letters[NUMLTRS];
    init_array(letters, NUMLTRS);

    // Open the file and count the letter frequencies
    string fname;
    ifstream infile;
    openfile(infile, fname);
    get_letter_freq(infile, letters);
    infile.close();

    // Reverse sort the final array and display the result
    rev_sort_array(letters, NUMLTRS);
    print_frequencies(letters, NUMLTRS);

    return 0;
}


// Initialize letter frequency array.
void init_array(LtrCt ltrs[], UnsInt dim1)
{
    for (UnsInt i = 0; i < dim1; ++i)
    {
        ltrs[i].letter = static_cast<char>(i + LOWER_A);
        ltrs[i].count = 0;
    }

    return;
}

// Get the frequencies of each letter in a text file.
void get_letter_freq(ifstream &infile, LtrCt ltrs[])
{
    UnsInt index;
    char ch;
    infile.get(ch);
    while (!infile.eof())
    {

        if (isalpha(ch))
        {
            index = static_cast<UnsInt>(tolower(ch)) - LOWER_A;
            ltrs[index].count++;
        }

        infile.get(ch);
    }
    return;
}


// Print the letter frequencies.
void print_frequencies(LtrCt ltrs[], UnsInt dim1)
{
    for(UnsInt i = 0; i < dim1; ++i)
        if (ltrs[i].count)
        {
            cout << ltrs[i].letter << " " << ltrs[i].count << std::endl; 
        }
    return;
}


// Open a file for reading.
void openfile(ifstream &infile, string &filename)
{
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


// Reverse sort the array of letter frequencies.
void rev_sort_array(LtrCt ltrs[], UnsInt dim1)
{
    LtrCt temp;
    for (int i = dim1 - 1; i > 0; i--)
    {
        for (int j = 0; j < i; ++j)
        {
            if (ltrs[j].count < ltrs[j+1].count)
            {
                temp = ltrs[j+1];
                ltrs[j+1] = ltrs[j];
                ltrs[j] = temp;

            }
        }
    }
    return;
}

