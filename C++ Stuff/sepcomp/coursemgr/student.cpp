// Implementation file for the Student class.
// We must #include "student.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>

#include "student.h"

using std::vector;
using std::string;
using std::ifstream;
using std::istringstream;
using std::istream;
using std::ostream;
using std::cout;
using std::endl;

//---------------------------------------------------------------------
//            MEMBER FUNCTION DEFINITIONS
//---------------------------------------------------------------------
Student::Student()
{
    last = "Student";
    first = "Default";
    id = 999999;
}

Student::Student(string lname, string fname, UnsInt idnum)
{
    last = lname;
    first = fname;
    id = idnum;
}

Student::~Student()
{
    if (grades)
        delete [] grades;
}

Student::Student(const Student &s)
{
    last = s.last;
    first = s.first;
    id = s.id;
    capacity = s.capacity;
    numgrades = s.numgrades;
    grades = nullptr;
    if (numgrades > 0)
    {
        grades = new double[capacity];
        for (int i = 0; i < numgrades; ++i)
            grades[i] = s.grades[i];
    }
}

Student& Student::operator=(const Student &rhs)
{
    if (this == &rhs)
        return *this;

    last = rhs.last;
    first = rhs.first;
    id = rhs.id;
    capacity = rhs.capacity;
    numgrades = rhs.numgrades;
    if (grades)
    {
        delete [] grades;
        grades = nullptr;
    }
    if (numgrades > 0)
    {
        grades = new double[capacity];
        for (int i = 0; i < numgrades; ++i)
            grades[i] = rhs.grades[i];
    }
    return *this;
}

string Student::get_name() const
{
    return first + " " + last;
}

UnsInt Student::get_id() const
{
    return id;
}

void Student::set_name(string new_last, string new_first)
{
    last = new_last;
    first = new_first;
    return;
}

void Student::set_id(UnsInt new_id)
{
    id = new_id;
    return;
}

void Student::add_grade(double newgrade)
{
    if (grades == nullptr)
        grades = new double[capacity];
    else if (numgrades > capacity * CAP_RATE)
        add_capacity(INCR_AMT);
    grades[numgrades] = newgrade;
    numgrades++;
    return;
}

void Student::add_capacity(int cap_incr_amt)
{
    capacity += cap_incr_amt;
    double *newgrades = new double[capacity];
    for (int i = 0; i < numgrades; ++i)
        newgrades[i] = grades[i];
    delete [] grades;
    grades = newgrades;
    return;
}

void Student::compact_grades(int index)
{
    for (int i = index; i < numgrades - 1; ++i)
        grades[i] = grades[i+1];
    return;
}


double Student::remove_grade(int gradeindex)
{
    double removed = grades[gradeindex];
    compact_grades(gradeindex);
    numgrades--;
    return removed;
}

double Student::average() const
{
    double sum = 0.0;
    for (int i = 0; i < numgrades; ++i)
        sum += grades[i];
    return sum / numgrades;
}

bool Student::has_grades() const
{
    return numgrades > 0;
}

void Student::print_student_grades() const
{
    if (has_grades())
    {
        int i;
        cout << " ";
        for (i = 0; i < numgrades - 1; ++i)
            cout << grades[i] << " ";
        cout << grades[i] << " ";
        cout << "AVERAGE: " << average();
    }
    return;
}

//---------------------------------------------------------------------
//            NON-MEMBER FUNCTION DEFINITIONS
//---------------------------------------------------------------------

// Open a file for reading.
// Parameters:
//   infile  :  the input data file
//   filename:  the name of the file to open
void openfile(ifstream &infile, string filename)
{
    infile.open(filename);
    if (infile.fail())
    {
        cout << filename << ": file open failed for input file.\n";
        exit(1);
    }
}

// Reads a class roster from a data file and creates a course roster.
// Parameters:
//   rfname  : the name of the class roster file
//   myclass: the list of Students
void get_class_from_file(string rfname, vector<Student> &myclass)
{
    ifstream dfclass;
    openfile(dfclass, rfname);

    Student new_student;
    while (dfclass >> new_student)
        myclass.push_back(new_student);

    dfclass.close();
}

void print_class_roster(const vector<Student> &myclass)
{
    for (Student s : myclass)
    {
        cout << s;
        s.print_student_grades();
        cout << endl;
    }
}

istream& operator>>(istream &instr, Student &s)
{
    string student_record, in_last, in_first;
    UnsInt in_id;
    getline(instr, student_record);
    istringstream rec(student_record);
    rec >> in_last >> in_first >> in_id;
    s = Student(in_last, in_first, in_id);
    double grade;
    while (rec >> grade)
        s.add_grade(grade);
    return instr;
}

ostream& operator<<(ostream &outstr, const Student &s)
{
    outstr << "[" << s.id << "] " << s.first << " "
           << s.last;
    return outstr;
}
