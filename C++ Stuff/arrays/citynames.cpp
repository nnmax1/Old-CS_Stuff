

#include <iostream>
#include <fstream>
#include <cstdlib>

void open_file(std::ifstream &inf, const std::string &fname);
void print_array(const std::string strarr[], unsigned int size);

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
  
    print_array(citynames, counter);

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
