
// Lab 8.  Implementing the "Big 3" in the IntVector class.
//
// TODO:
//  1.  Implement the Big 3 for the IntVector class.
//  2.  Implement the function has_item. This function deliberately
//      uses call-by-value in order to test the copy constructor (do NOT
//      change the parameter v to call-by-reference).
//
// IntVector is a simplified version of the STL vector class: it
// allows you to create a dynamic array of type int.
//

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

// A class for a dynamic array.
class IntVector 
{
    public:
        typedef unsigned int UnsInt;
        friend ostream& operator<<(ostream &outs, const IntVector &myv);

        IntVector();

        // The "Big 3"




        UnsInt get_size() const { return size; }
        UnsInt get_capacity() const { return capacity; }

        void add(int item);
        int *get_list() const { return list; }

    private:
        static constexpr int CAP_AMT = 20;
        static constexpr double THRESHOLD_CAP = 0.75;
        int *list;
        UnsInt size = 0;
        UnsInt capacity = CAP_AMT;
        void increase_capacity();
};


// Determine if an item is in a list of integers.
// Parameters:
//   v  : the list of integers (KEEP AS CALL-BY-VALUE)
//   tgt: the item to locate
// Returns true if tgt is in v, false otherwise.
bool has_item(IntVector v, int tgt);


int main()
{
    // Testing the default constructor
    IntVector v1;
    cout << "Testing the default constructor with v1:" << endl;
    cout << "capacity = " << v1.get_capacity() << " size = " 
         << v1.get_size() << endl;

/*
    // Read data from a file
    string filename;
    cout << "Enter the name of a data file: ";
    cin >> filename;

    ifstream dfile(filename);
    if (dfile.fail())
    {
        cout << "File open failed." << endl;
        exit(1);
    }

    double input;
    while (dfile >> input)
        v1.add(input);
    dfile.close();

    cout << "After reading data from the file and adding to v1:" << endl;
    cout << "capacity = " << v1.get_capacity() << " size = " 
         << v1.get_size() << endl;
    // Display the object
    cout << v1 << endl;

    // Testing the copy constructor
    IntVector v2(v1);
    cout << "Testing the copy constructor with v2:" << endl;
    cout << "capacity = " << v2.get_capacity() << " size = " 
         << v2.get_size() << endl;
    cout << v2 << endl;

    // Testing the assignment operator
    IntVector v3;
    v3 = v2;
    cout << "Testing the assignment operator with v3:" << endl;
    cout << "capacity = " << v3.get_capacity() << " size = " 
         << v3.get_size() << endl;
    cout << v3 << endl;

    // Testing copy constructor in a function call
    // Requires implementing the function has_item
    char again;
    do
    {
        cout << "Enter a number to locate: ";
        cin >> input;
        if (has_item(v2, input))
            cout << input << " is in the list." << endl;
        else
            cout << input << " is NOT in the list." << endl;

        cout << "Check again? y/n ";
        cin >> again;
    } while (again != 'n');

*/


    return 0;
}

/*-----------------------------------------------------------------------
          FUNCTION IMPLEMENTATIONS BELOW
 ------------------------------------------------------------------------*/

IntVector::IntVector()
{
    list = new int[capacity];
}



std::ostream& operator<<(std::ostream &outs, const IntVector &myv)
{
    outs << "{";
    unsigned int i;
    for (i = 0U; i < myv.size - 1; ++i)
        outs << myv.list[i] << ", ";
    outs << myv.list[i] << "}";
    return outs;
}

void IntVector::increase_capacity()
{
    capacity += CAP_AMT;
    int *new_list = new int[capacity];
    unsigned int i;
    for (i = 0U; i < size; ++i)
        new_list[i] = list[i];
    delete [] list;
    list = new_list;
}


void IntVector::add(int item)
{
    if (size > capacity * THRESHOLD_CAP)
        increase_capacity();
    list[size++] = item;
    return;
}

