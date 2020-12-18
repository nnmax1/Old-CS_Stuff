
#include <iostream>
#include <cstdlib>
using namespace std;


class TemperatureList
{
    public:
        // Constructor
        TemperatureList(int sz);
        
        // Copy constructor
        TemperatureList(const TemperatureList &templist);

        // Destructor
        ~TemperatureList();

        void fillTemperatures(istream &instr);

        friend ostream& operator <<(ostream& outs,
                const TemperatureList& theObject);

    private:
        double *list; // a pointer to an array of temperatures in Fahrenheit
        int size;     // the size of the array
};


int main()
{
    int num_temps;
    cout << "How many temperatures do you have? ";
    cin >> num_temps;

    TemperatureList temps(num_temps);
    temps.fillTemperatures(cin);

    // Make a new TemperatureList that is a copy of temps
    TemperatureList temps2(temps);
    
    // Display the list of temps2
    cout << endl;
    cout << temps2;

    return 0;
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
