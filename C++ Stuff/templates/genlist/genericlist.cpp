//DISPLAY 17.8 Implementation of GenericList
//This is the implementation file: genericlist.cpp
//This is the implementation of the class template named GenericList.
//The interface for the class template GenericList is in the
//header file genericlist.h.
#ifndef GENERICLIST_CPP
#define GENERICLIST_CPP
#include <iostream>
#include <cstdlib>
#include "genericlist.h" //This is not needed when used as we are using this file,
                 //but the #ifndef in genericlist.h makes it safe.
using namespace std;

//Uses cstdlib:
template<class T>
GenericList<T>::GenericList(int max) : maxLength(max), currentLength(0)
{
    item = new T[max];
}

template<class T>
GenericList<T>::~GenericList()
{
    delete [] item;
}

template<class T>
int GenericList<T>::length() const
{
    return currentLength;
}

//Uses iostream and cstdlib:
template<class T>
void GenericList<T>::add(T newItem)
{
    if ( full() )
    {
        cout << "Error: adding to a full list.\n";
        exit(1);
    }
    else
    {
        item[currentLength] = newItem;
        currentLength = currentLength + 1;
    }
}

template<class T>
bool GenericList<T>::full() const
{
    return (currentLength == maxLength);
}

template<class T>
void GenericList<T>::erase()
{
    currentLength = 0;
}

template<class T>
ostream& operator <<(ostream& outs, const GenericList<T>& theList)
{
    for (int i = 0; i < theList.currentLength; i++)
        outs << theList.item[i] << endl;
    return outs;
}

#endif // GENERICLIST_CPP Notice that we have enclosed all the template
       // definitions in #ifndef... #endif.
