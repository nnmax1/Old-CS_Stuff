
// Lab 4.
// Write a program that reads a text file and outputs in lexicographic order
// each unique word that appears in the file .

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>  // for sort()

using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;

// Open a file for reading.
void openfile(ifstream &infile);

// Open a file for writing.
void openfile(ofstream &outfile);

// Determine if a word is in a list of words.
bool hasword(const vector<string> &vec, const string &tgt);

// Find all the unique words in a text file.
void find_unique_words(ifstream &infile, vector<string> &vec);

int main()
{
    using namespace std;

    ifstream infile;
    ofstream outfile;

    openfile(infile);
    openfile(outfile);

    vector<string> words;

    find_unique_words(infile, words);
    sort(words.begin(), words.end());

    // Print out the final sorted list
    for (string w : words)
        outfile << w << endl;

    infile.close();
    outfile.close();

    return 0;
}


void openfile(std::ifstream &infile)
{
    using namespace std;
    string filename;
    cout << "Name of data file: ";
    cin >> filename;

    infile.open(filename);
    if (infile.fail())
    {
        cout << filename << ": file open failed for input file.\n";
        exit(1);
    }
}

void openfile(std::ofstream &outfile)
{
    using namespace std;
    string filename;
    cout << "Name of output file: ";
    cin >> filename;

    outfile.open(filename);
    if (outfile.fail())
    {
        cout << filename << ": file open failed for output file.\n";
        exit(1);
    }
}

bool hasword(const vector<string> &vec, const string &tgt)
{
    using namespace std;
    for (string s : vec)
        if (s == tgt)
            return true;
    return false;
}

void find_unique_words(ifstream &infile, vector<string> &vec)
{
    string word;

    // Read each word from infile: if it's not in the
    // vector, add it to the vector using push_back()
    while (infile >> word)
        if (!hasword(vec, word))
            vec.push_back(word);
}

