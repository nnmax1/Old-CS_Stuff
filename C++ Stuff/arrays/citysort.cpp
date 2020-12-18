

#include <iostream>
#include <fstream>
#include <cstdlib>

void open_file(std::ifstream &inf, const std::string &fname);
void print_array(const std::string strarr[], unsigned int size);

// Function declarations for the implementation of selection sort.
int get_min_index(const std::string strarr[], int start_idx, int size);
void swapValues(std::string &s1, std::string &s2);
void sort(std::string strarr[], int size);

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
    sort(citynames, counter);
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

int get_min_index(const std::string strarr[], int start_idx, int size)
{
    std::string min = strarr[start_idx];
    int min_index = start_idx;
    for (int index = start_idx + 1; index < size; index++)
        if (strarr[index] < min)
        {
            min = strarr[index];
            min_index = index;
        }
    return min_index;
}

void swapValues(std::string &s1, std::string &s2)
{
    std::string temp = s1;
    s1 = s2;
    s2 = temp;
    return;
}

void sort(std::string strarr[], int size)
{
    int index_of_min;

    for (int i = 0; i < size - 1; ++i)
    {  //Place the correct value in a[index]:
        index_of_min = get_min_index(strarr, i, size);
        swapValues(strarr[i], strarr[index_of_min]);
    }
}

