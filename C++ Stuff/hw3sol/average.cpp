
#include <fstream>  
#include <sstream>   
#include <iostream>
#include <string>
#include <cstdlib>   

// Global constants
const int MINGRADE = 0;   
const int MAXGRADE = 100; 


void openfile(std::ifstream &infile);

void openfile(std::ofstream &outfile);

bool is_valid(int grade, int min, int max);


void process_student_record(const std::string &line, std::ofstream &outstr);


int main()
{
    using namespace std;
    ifstream in_stream;
    ofstream out_stream;
    
    // Open files for reading and writing
    openfile(in_stream);
    openfile(out_stream);

    // Read each student record from the data file and process
    string line;
    while (getline(in_stream, line))
        process_student_record(line, out_stream);

    in_stream.close();
    out_stream.close();

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

bool is_valid(int grade, int min, int max)
{
    return (grade >= min && grade <= max);
}

void process_student_record(const std::string &line, std::ofstream &outstr)
{
    using namespace std;
    istringstream linestr(line);
    int grade;
    int sum = 0, numgrades = 0;
    int min_grade = MAXGRADE + 1;  // for the lowest grade to drop
    string last, first;

    // Set formatting for the output file stream
    outstr.setf(ios::fixed);
    outstr.setf(ios::showpoint);
    outstr.precision(4);

    // Read the student's name
    linestr >> last >> first;
    outstr << first << " " << last << " ";
    // Process the grades
    while (linestr >> grade)
    {
        if (is_valid(grade, MINGRADE, MAXGRADE))
        {
            outstr << grade << " ";
            sum += grade;
            numgrades++;
            if (grade < min_grade)
                min_grade = grade;
        }
    }

    if (numgrades > 0)
    {
        // The average of valid grades excluding the lowest grade seen
        outstr << (static_cast<double>(sum) - min_grade) / (numgrades - 1)
               << '\n'; 
    }
    else
        outstr << "N/A\n";
}
