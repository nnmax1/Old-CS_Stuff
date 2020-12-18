
#include <iostream>
#include <cstdio>
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

    TemperatureList temps(num_temps);
    temps.fillTemperatures(cin);

    // Display the list of temps
    cout << endl;
    cout << temps;

    double temp_to_find;
    char again;
    do
    {
        cout << "Enter a temperature to locate in the list: ";
        cin >> temp_to_find;
        if (has_temp(temps, temp_to_find))
            cout << temp_to_find << " is in the list of temperatures." << endl;
        else
            cout << temp_to_find << " is NOT in the list of temperatures." << endl;

        cout << "Again? y/n ";
        cin >> again;
    } while (again != 'n');

    return 0;
}

// Constructor definition
TemperatureList::TemperatureList(int sz)
{
    fprintf(stderr, "TRACER: (%p)->TemperatureList(int sz)\n", this);
    list = new double[sz];
    size = sz;
}

// Copy constructor definition
TemperatureList::TemperatureList(const TemperatureList &templist)
{
    fprintf(stderr, "TRACER: (%p)->TemperatureList(const Temperatureint &templist)\n", this);
    size = templist.size;
    list = new double[size];
    // now we have to copy the values into the new object's array
    for (int i = 0; i < size; ++i)
        list[i] = templist.list[i];
}


// Destructor definition
TemperatureList::~TemperatureList()
{
    fprintf(stderr, "TRACER: (%p)->~TemperatureList()\n", this);
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
