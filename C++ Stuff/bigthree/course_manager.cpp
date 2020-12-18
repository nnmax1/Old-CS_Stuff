
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

typedef unsigned int UnsInt;

class Student {
    public:
        friend istream& operator>>(istream &instr, Student &s);
        friend ostream& operator<<(ostream &outstr, const Student &s);

        Student();
        Student(string lname, string fname, UnsInt idnum);

        // The Big 3
        ~Student();
        Student(const Student &s);
        Student& operator=(const Student &rhs);

        string get_name() const;
        UnsInt get_id() const;
        bool has_grades() const;

        void set_name(string new_last, string new_first);
        void set_id(UnsInt new_id);
        void add_grade(double newgrade);
        double remove_grade(int gradeindex);
        void print_student_grades() const;
        double average() const;

    private:
        static constexpr double CAP_RATE = 0.7;
        static constexpr int INCR_AMT = 5;
        string last;
        string first;
        UnsInt id;
        double *grades = nullptr;
        int numgrades = 0;
        int capacity = INCR_AMT;
        // Helper functions
        void add_capacity(int cap_incr_amt);
        void compact_grades(int index);
};

//------------------------------------------------------------------
//         NON-MEMBER FUNCTION DECLARATIONS
//------------------------------------------------------------------
void openfile(ifstream &infile, string filename);
void get_class_from_file(string rfname, vector<Student> &myclass);
void print_class_roster(const vector<Student> &myclass);

// TESTER PROGRAM
int main()
{
    // Store the roster in a vector of type Student.
    vector<Student> cisc2000;

    // Read in student records from a file
    string rosterfile;
    cout << "Name of roster file: ";
    cin >> rosterfile;

    get_class_from_file(rosterfile, cisc2000);
    cout << "Number of students: " << cisc2000.size()<< endl;

    // Print original roster from file
    cout << "Original class roster:" << endl;
    print_class_roster(cisc2000);

    // Add some grades to each student
    constexpr int NUMGRADES = 4;
    double extra_grades[] = {99.5, 99.6, 99.7, 99.8};

    for (Student &s : cisc2000)
    {
        for (int i = 0; i < NUMGRADES; ++i)
        {
            s.add_grade(extra_grades[i]);
        }
    }

    // Print class roster with added grades
    cout << "\nClass roster with added grades:" << endl;
    print_class_roster(cisc2000);

    // Copy the course
    cout << "\nCopying the course to CISC 2200:" << endl;
    // A second vector for the new course
    vector<Student> cisc2200;
    for (Student s : cisc2000)
        cisc2200.push_back(Student(s));  // use the copy constructor

    cout << "\nCISC 2200 class roster:" << endl;
    print_class_roster(cisc2200);

    // Remove the grades from a student
    cout << "\nRemoving grades from Billy Zanely in CISC2200:" << endl;
    cout << cisc2200[2];
    cisc2200[2].print_student_grades();
    cout << endl;
    while (cisc2200[2].has_grades())
    {
        cout << "Removing: " << cisc2200[2].remove_grade(0) << endl;
        cout << cisc2200[2];
        cisc2200[2].print_student_grades();
        cout << endl;
    }

    cout << "\nCISC 2200 class roster:" << endl;
    print_class_roster(cisc2200);

    // Assign a student from one class to another
    cout << "\nAssigning Billy Zanely from CISC 2200 to CISC 2000:" << endl;
    cisc2000[2] = cisc2200[2];

    cout << "\nCISC 2000 class roster:" << endl;
    print_class_roster(cisc2000);

    // Testing defaults
    Student s1;
    cout << "Default student:\n";
    cout << s1 << endl;
    Student s2;
    s2 = s1;
    cout << "Second default student:\n";
    cout << s2 << endl;
    Student s3(s2);
    cout << "Third default student:\n";
    cout << s3 << endl;
    s1 = s1;
    cout << "Default student:\n";
    cout << s1 << endl;

    return 0;
}

//---------------------------------------------------------------------
//                    Constructors
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

//---------------------------------------------------------------------
//                    The Big 3
//---------------------------------------------------------------------
// The destructor
Student::~Student()
{
    if (grades)
        delete [] grades;
}


// The copy constructor
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


// The assignment operator
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


//---------------------------------------------------------------------
//                 Other Member Function Definitions
//---------------------------------------------------------------------

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
    using namespace std;
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
