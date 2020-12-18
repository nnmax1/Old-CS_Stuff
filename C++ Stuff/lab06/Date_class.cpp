
// Lab 6A: The Date class.
//
// Implement a class to represent dates.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

//----------------------------------------------------------------------
//  TODO: Define the class Date.
//----------------------------------------------------------------------  

class Date {
    public:
        Date();  // a default date: 1/1/1970

        // Prompts user to input a date with the format month/day/year. 
        void input();

        // Display this object's date in the format of month/day/year 
        void output();

        // Check whether the invoking object's date is before the date d
        // Returns true if the invoking object's date is before d, and
        // returns false otherwise. 
        bool is_before(const Date &d);

        // Check whether the invoking object's date is the same as another
        // date d.
        bool is_same(const Date &d);

    private:
        int year;
        int month;
        int day;
};


//************** DO NOT MODIFY MAIN ************************************
//    Except to comment out portions for testing, or to add code
//    for testing.  If you add code for testing, be sure to comment
//    it out before you submit your file.
//**********************************************************************
int main()
{
    Date day1;
    Date day2;
    
    cout << "Default dates:\n";
    day1.output();
    cout << endl;
    day2.output();
    cout << endl;

    char ans;
    bool more_dates = true;
    while (more_dates)
    {
        cout << endl;
        cout << "Day1: ";
        day1.input();

        cout << "Day2: ";
        day2.input();

        if (day1.is_same(day2))
        {
            day1.output();
            cout << " is the same as ";
            day2.output();
            cout << endl;
        }
        else if (day1.is_before(day2))
        {
            day1.output();
            cout << " is before ";
            day2.output();
            cout << endl;
        }
        else
        {
            day1.output();
            cout << " is after ";
            day2.output();
            cout << endl;
        }

        cout << "Enter more dates? y/n: ";
        cin >> ans;
        if (ans != 'y')
            more_dates = false;
    }

    return 0;

}
//----------------------------------------------------------------------
//                MEMBER FUNCTION DEFINITIONS
//----------------------------------------------------------------------

// TODO: implement a default constructor with a date of 1/1/1970

Date::Date()
{
    year = 1970;
    month = 1;
    day = 1;
}


// TODO: implement the member function output.
// Display the invoking object's date in the terminal in the
// format of month/day/year  

void Date::output()
{
   cout << month << '/' <<day << '/' << year;
}


// TODO: implement the member function is_before.
/* Check whether the invoking object is a date before the given date d  
   Parameter : 
       d : the date that we are comparing to the invoking object
  Returns true if the invoking object is a date before date d and
  returns false otherwise.
*/

bool Date::is_before(const Date &d)
{
    if (year < d.year)
        return true;
    else if (year == d.year && month < d.month)
        return true;
    else if (year == d.year && month == d.month && day < d.day)
        return true;

    return false;
}


// TODO: implement the member function is_same.
// Check whether the invoking object's date is the same as another
// date d.


bool Date::is_same(const Date &d)
{
    return (year == d.year && month == d.month && day == d.day);
}


/* Prompt the user to enter a date in the format of month/day/year. 
 * Read the user's input and check to make sure it is valid; if valid,
 * set the invoking object to the entered date.
 * If the input is invalid, display an error message and ask the user to retry.
 * Valid dates:
 *  -- any year after year 1
 *  -- month between 1 and 12
 *  -- day between 1 and 31
 */
void Date::input()
{
    constexpr char DATESEP = '/';
    int mo, yr, dy;
    char sep1, sep2;
    bool valid = false;

    while (!valid)
    {
        cout << "Enter a date in form month/day/year: ";
        cin >> mo >> sep1 >> dy >> sep2 >> yr;
        if (sep1 != DATESEP || sep2 != DATESEP)
        {
            cout << "Invalid date format. Try again." << endl;
        }
        else if (yr < 1 || mo < 1 || mo > 12 || dy < 1 || dy > 31) 
        {
            cout << "Invalid date values. Try again." << endl;
        }
        else  // date is good
            valid = true;
    }
    // set the values
    year = yr;
    month = mo;
    day = dy;
    return;
}

