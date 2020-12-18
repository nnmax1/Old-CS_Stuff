
#include <iostream>
#include <cstdlib>
using namespace std;


class TemperatureList
{
    public:
        // Constructors
        TemperatureList();
        TemperatureList(int sz);
        
        // Copy constructor
        TemperatureList(const TemperatureList &templist);

        // Destructor
        ~TemperatureList();

        // Assignment operator
        TemperatureList& operator=(const TemperatureList &rhs);

        void fillTemperatures(istream &instr);
        double *get_list() { return list; };
        int get_size() { return size; };

        friend ostream& operator <<(ostream& outs,
                const TemperatureList& theObject);

    private:
        double *list; // a pointer to an array of temperatures in Fahrenheit
        int size;     // the size of the array
};


bool has_temp(TemperatureList templist, double tgt)
{
    int sz = templist.get_size();
    double *tlist = templist.get_list();
    for (int i = 0; i < sz; ++i)
        if (tlist[i] == tgt)
            return true;

    return false;
}

int main()
{
    int num_temps;
    cout << "How many temperatures do you have? ";
    cin >> num_temps;

    TemperatureList temps1(num_temps);
    temps1.fillTemperatures(cin);

    TemperatureList temps2;  // uses default constructor
    temps2 = temps1;

    // Display the list of temps
    cout << endl;
    cout << temps2;

    TemperatureList temps3;
    temps3 = temps1 = temps1;
    cout << temps3;

    return 0;
}

// A default constructor
TemperatureList::TemperatureList()
{
    list = nullptr;
    size = 0;
}


// Constructor definition
TemperatureList::TemperatureList(int sz)
{
    list = new double[sz];
    size = sz;
}

// Copy constructor definition
TemperatureList::TemperatureList(const TemperatureList &templist)
{
    size = templist.size;
    list = new double[size];
    // now we have to copy the values into the new object's array
    for (int i = 0; i < size; ++i)
        list[i] = templist.list[i];
}


// Destructor definition
TemperatureList::~TemperatureList()
{
    delete [] list;
}

// Assignment operator
TemperatureList& TemperatureList::operator=(const TemperatureList &rhs)
{
    // if we're doing obj1 = obj1;
    if (this == &rhs)
        return *this;

    // Otherwise, first, we need to delete the existing array of temperatures
    // but only if it has been allocated (don't try to delete a nullptr)
    if (list)
        delete [] list;
    size = rhs.size;
    list = new double[size];
    // now we have to copy the values
    for (int i = 0; i < size; ++i)
        list[i] = rhs.list[i];

    // return this object using the "this" pointer
    return *this;
}
    


void TemperatureList::fillTemperatures(istream &instr)
{
    for (int i = 0; i < size; ++i)
        instr >> list[i];
}


//Uses iostream:
ostream& operator <<(ostream& outs, const TemperatureList& theObject)
{
    for (int i = 0; i < theObject.size; i++)
        outs << theObject.list[i] << " F\n";
    return outs;
}
