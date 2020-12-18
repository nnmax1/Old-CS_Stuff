
#include <iostream>
#include <fstream>
#include <cstdlib>

void open_file(std::ifstream &inf, const std::string &fname);
void print_citytemps(const std::string ctemps[][2], unsigned int dim1);

int main()
{
    using namespace std;
    constexpr unsigned int MAXNUM = 100;

    string citytemps[MAXNUM][2];

    ifstream infile;
    open_file(infile, "pasted.out");

    string city, temp;
    unsigned int counter = 0U;
    while (infile >> city && infile >> temp)
    {
        citytemps[counter][0] = city;
        citytemps[counter][1] = temp;
        counter++;
    }
    infile.close();
  
    print_citytemps(citytemps, counter);

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

void print_citytemps(const std::string ctemps[][2], unsigned int dim1)
{
    unsigned int i;
    for (i = 0U; i < dim1; ++i)
        std::cout << ctemps[i][0] << " " << ctemps[i][1] << std::endl;
    return;
}
