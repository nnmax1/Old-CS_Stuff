//DISPLAY 17.7 Interface for the Class Template GenericList
//This version moves the implementation of the overloaded <<
//to the .cpp file, but requires adding some forward declarations.
#ifndef GENERICLIST_H
#define GENERICLIST_H
#include <iostream>
using namespace std;

//We need a forward declaration of the GenericList template
//class for the friend header declaration that comes right after it.
template<class T>
class GenericList;

//Forward declaration of the friend << for the definition inside the
//GenericList class below. These must be defined here since << is not
//a member of the class.
template<class T>
ostream& operator <<(ostream& outs, const GenericList<T>& theList);

template<class T>
class GenericList
{
    public:
        
        //Initializes the object to an empty list that can hold up to
        //max items of type T.
        GenericList(int max);

        //Returns all the dynamic memory used by the object to the freestore.
        ~GenericList();

        //Returns the number of items on the list.
        int length() const;

        //Precondition: The list is not full.
        //Postcondition: The newItem has been added to the list.
        void add(T newItem);

        //Returns true if the list is full.
        bool full() const;

        //Removes all items from the list so that the list is empty.
        void erase();

        //Overloads the << operator so it can be used to output the
        //contents of the list.
        //Note the <> needed after the operator (or function) name!
        //The implementation is in genericlist.cpp
        friend ostream& operator << <>(ostream& outs,
                const GenericList<T>& theList);
    private:
        T *item; //pointer to the dynamic array that holds the list.
        int maxLength; //max number of items allowed on the list.
        int currentLength; //number of items currently on the list.
};

#endif //GENERICLIST_H

