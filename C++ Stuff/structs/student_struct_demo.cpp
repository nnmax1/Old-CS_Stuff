
// Demonstration of how to use a structure.
// We encapsulate the attributes for a student in a structure.

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

typedef unsigned int UnsInt;

void openfile(ifstream &infile)
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

// A structure to represent a student.
struct Student {
    string last;
    string first;
    UnsInt id;
    vector<double> grades;
};

string student_tostring(Student &st)
{
    return to_string(st.id) + " " + st.first + " " + st.last;
}

// Get one student from a data file
// Pre-condition: there is at least 1 student in the roster file
// Returns a Student structure with a student's info.
Student get_student_from_file(ifstream &dfile)
{
    string in_last, in_first;
    UnsInt in_id;

    dfile >> in_last >> in_first;
    dfile >> in_id;

    Student temp = {in_last, in_first, in_id};
    return temp;
}

int main()
{
    ifstream datafile;
    openfile(datafile);

    Student temp_student;
    UnsInt count;
    datafile >> count;
    for (UnsInt i = 0; i < count; ++i)
    {
        temp_student = get_student_from_file(datafile);
        cout << student_tostring(temp_student) << endl;
    }

    datafile.close();
    return 0;
}
