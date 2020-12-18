
// Lab midterm.
// Decode a secret message.

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

// Reverse the characters in a string.
// Parameter:  line  : the string to reverse 
void reverse(string &line)
{
    unsigned int start = 0U;
    unsigned int end = line.length() - 1;
    unsigned int temp;
    while (start < end)
    {
        temp = line[end];
        line[end] = line[start];
        line[start] = temp;
        ++start;
        --end;
    }
    return;
}

// Decode a line of text.
void decode(string &line)
{
    const unsigned int THRESHOLD = 83;
    const unsigned int OFFSET_HI = 4;
    const unsigned int OFFSET_LO = 2;

    // Reverse the line
    reverse(line);
    
    // Decode each character
    unsigned int i, offset, charval;

    for (i = 0; i < line.length(); ++i)
    {
        charval = static_cast<unsigned int>(line[i]); 
        if (charval > THRESHOLD)
            offset = OFFSET_HI;
        else
            offset = OFFSET_LO;
        line[i] = static_cast<char>(charval - offset);
    }
    return;
}

int main()
{
    ifstream infile("secret.txt");
    if (infile.fail())
        exit(1);

    string line;
    while (getline(infile, line))
    {
        decode(line);
        cout << line << endl;
    }

    infile.close();
    return 0;
}
