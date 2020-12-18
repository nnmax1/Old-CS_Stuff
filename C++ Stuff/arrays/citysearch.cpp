

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>

void open_file(std::ifstream &inf, const std::string &fname);
void print_array(const std::string strarr[], unsigned int size);
int search(const std::string strarr[], int size, std::string target);

int main()
{
    using namespace std;
    constexpr unsigned int MAXNUM = 100;

    string citynames[MAXNUM];

    ifstream infile;
    open_file(infile, "cities.dat");

    string city;
    unsigned int counter = 0U;
    while (infile >> city)
        citynames[counter++] = city;
    infile.close();
  
    // For debugging
    // print_array(citynames, counter);

    char repeat;
    string tgtstr;
    int res;
    do
    {
        cout << "Enter a city: ";
        cin >> tgtstr;
        res = search(citynames, counter, tgtstr);
        if (res < 0)
            cout << tgtstr << " is NOT in the list." << endl;
        else
            cout << citynames[res] << " is in the list." << endl;
            
        cout << "Repeat? y/n ";
        cin >> repeat;
    } while(tolower(repeat) != 'n');

    return 0;
}

void open_file(std::ifstream &inf, const std::string &fname)
{
    inf.open(fname);
    if (inf.fail())
    {
        std::cout << fname << ": File open for reading failed." << std::endl;
        exit(1);
    }
    return;
}

void print_array(const std::string strarr[], unsigned int size)
{
    unsigned int i;
    for (i = 0U; i < size; ++i)
        std::cout << strarr[i] << std::endl;
    return;
}

int search(const std::string strarr[], int size, std::string target)
{
    int index = 0;
    bool found = false;
    while (!found && index < size)
        if (target == strarr[index])
            found = true;
        else
            index++;

    if (found)
        return index;

    return -1;
}
