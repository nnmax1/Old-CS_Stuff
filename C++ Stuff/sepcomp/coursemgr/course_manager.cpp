
// A program to manage a course. Uses the Student class.
// This version of Student stores grades in a dynamic array of doubles.
// As a consequence, we implement the Big 3: a destructor, a copy
// constructor, and the assignment operator.
//

#include <iostream>
#include <string>
#include <vector>

#include "student.h"

int main()
{
    using namespace std;

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
