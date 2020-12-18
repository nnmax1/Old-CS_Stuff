
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>

void open_file(std::ifstream &inf, const std::string &fname);
void print_citytemps(const std::string ctemps[][2], unsigned int dim1);
void convert_citytemps(const std::string ctemps[][2], unsigned int dim1);

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
  
    // print_citytemps(citytemps, counter);
    convert_citytemps(citytemps, counter);

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

void convert_citytemps(const std::string ctemps[][2], unsigned int dim1)
{
    using std::cout;
    using std::endl;
    using std::setw;
    using std::left;
    using std::right;
    using std::setprecision;

    cout.setf(std::ios::fixed);
    cout.setf(std::ios::showpoint);

    unsigned int i;
    cout << left << setw(12) << "City" << right << setw(9) << "Temp F" 
         << right << setw(9) << "Temp C" << endl;
    for (i = 0U; i < dim1; ++i)
        cout << left << setw(12) << ctemps[i][0] 
             << right << setw(9) << setprecision(2) << stod(ctemps[i][1])
             << setw(9) << (stod(ctemps[i][1]) - 32.0) * (5.0 / 9.0) << endl;
    return;
}
