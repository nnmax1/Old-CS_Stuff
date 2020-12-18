#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// DO NOT put using namespace std; into a header file!

using std::istream;
using std::ostream;
using std::ifstream;
using std::string;
using std::vector;

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

#endif
