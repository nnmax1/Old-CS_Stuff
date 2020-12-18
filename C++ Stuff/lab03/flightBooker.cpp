
// Lab 3. Airlines Booking Program.
//
// This program reads a flight data file, allows a booking
// agent to book seats, and saves the updated information in
// the flight data file.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

// You can put these targeted using directives in global scope.
using std::string;
using std::ifstream;
using std::ofstream;

constexpr int NUMROWS = 12;
constexpr int NUMSEATS = 4;


// Open a flight data file for reading.
void openfile(ifstream &infile, string &fname)
{
    using namespace std;
    cout << "Enter name of the flight data file: ";
    cin >> fname;

    infile.open(fname);
    if (infile.fail( ))
    {
        cout << fname << ": file open failed for input file.\n";
        exit(1);
    }
}

// Write flight information to a flight data file.
void save_flight_data(const char rows[][NUMSEATS],
                      const string &fname)
{
    using namespace std;
    ofstream outfile(fname);
    if (outfile.fail())
    {
        cout << fname << ": file open for writing failed.\n";
        exit(1);
    }
    int i, j;
    for (i = 0; i < NUMROWS; ++i)
    {
        for (j = 0; j < NUMSEATS; ++j)
            outfile << rows[i][j];
        outfile << endl;
    }
    outfile.close();
    return;
}

// Read the booking information for a flight.
void read_flight_data(ifstream &fltdata, 
                      string &fname, 
                      char rows[][NUMSEATS])
{
    using namespace std;
    openfile(fltdata, fname);
    int rownum = 0;
    int seatnum;
    string row;
    while (getline(fltdata, row))
    {
        seatnum = 0;
        for (char seatltr : row)
            rows[rownum][seatnum++] = seatltr;
        rownum++;
    }
    fltdata.close();
    return;
}

// Display the seating layout for a flight.
void showseating(const char rows[][NUMSEATS])
{
    using namespace std;
    int i, j;
    cout << "\n";
    for (i = 0; i < NUMROWS; ++i)
    {
        cout << "[" << setw(2) << i+1 << "] ";
        for (j = 0; j < NUMSEATS - 1; ++j)
            cout << rows[i][j] << " ";
        cout << rows[i][j] << endl;
    }
    return;
}

// Book a seat on this flight.
bool book_seat(char rows[][NUMSEATS], int rnum, char seat)
{
    // First check if the row number is valid
    if (rnum > NUMROWS)
        return false;

    for (int j = 0; j < NUMSEATS; ++j)
    {
        if (rows[rnum - 1][j] == seat)
        {
            rows[rnum - 1][j] = 'X';
            return true;
        }
    }
    return false;
}

// Book a flight.
void book_flight(char rows[][NUMSEATS])
{
    using namespace std;
    int rownum;
    char ans, seatltr;
    bool repeat = true;
    do
    {
        cout << endl;
        cout << "MENU:\n";
        cout << "Show seating [s]\nBook a seat  [b]\nQuit         [q]\n";
        cout << "Enter your choice: ";
        cin >> ans;
        switch(ans)
        {
            case 'b':
            case 'B':
                cout << "Enter the row number followed by the seat letter: ";
                cin >> rownum >> seatltr;
                cout << endl;
                cout << "Seat " << rownum << " " << seatltr << " ";
                if ( book_seat(rows, rownum, seatltr) )
                    cout << "has been booked." << endl;
                else
                    cout << "is not available." << endl;
                break;
            case 's':
            case 'S':
                showseating(rows);
                break;
            case 'q':
            case 'Q':
                repeat = false;
                break;
            default:
                cout << "Unknown option." << endl;
        }
    } while (repeat);
    return;
}

int main()
{
    using namespace std;

    char allrows[NUMROWS][NUMSEATS];
    string flt_dfilename;
    ifstream dfilestr;

    read_flight_data(dfilestr, flt_dfilename, allrows);
    book_flight(allrows);
    save_flight_data(allrows, flt_dfilename);

    return 0;
}
