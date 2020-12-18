
// Create a course roster.
// Demonstrates structures and dynamic arrays.

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

// Print a student's info.
void print_student(const Student &st)
{
    cout << "[" << st.id <<  "] "
         << setw(10) << st.first << " "
         << setw(10) << st.last
         << endl;
    return;
}

string student_tostring(Student &st)
{
    return to_string(st.id) + " " + st.first + " " + st.last;
}

// Get one student from a data file
// Pre-condition: there is at least 1 student in the roster file
// Returns a Student structure with a student's info.
Student
get_student_from_file(ifstream &dfile)
{
    string in_last, in_first;
    UnsInt in_id;

    dfile >> in_last >> in_first;
    dfile >> in_id;

    Student temp = {in_last, in_first, in_id};
    return temp;
}

void print_class_roster(const Student myclass[], UnsInt size)
{
    for (UnsInt i = 0U; i < size; ++i)
        print_student(myclass[i]);

}

int main()
{
    ifstream datafile;
    openfile(datafile);

    UnsInt count;
    datafile >> count;

    Student *roster = new Student[count];

    for (UnsInt i = 0; i < count; ++i)
        roster[i] = get_student_from_file(datafile);

    print_class_roster(roster, count);

    datafile.close();
    delete [] roster;
    return 0;
}

