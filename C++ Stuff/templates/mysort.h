#ifndef _MYSORT_H_
#define _MYSORT_H_

// Adapted from DISPLAY 17.2 in Savitch.
// A Generic Sorting Function.  This file implements a generic
// version of selection sort.
//
// For templates, it is customary to not separate the declaration from 
// the definition, so you will often see the entire function definition
// in either the header or .cpp file.

template<typename T>
void swapValues(T& variable1, T& variable2)
{
    T temp;

    temp = variable1;
    variable1 = variable2;
    variable2 = temp;
}


template<typename BaseType>
int indexOfSmallest(const BaseType a[], int startIndex, int numberUsed)
{
    BaseType min = a[startIndex];
    int indexOfMin = startIndex;

    for (int index = startIndex + 1; index < numberUsed; index++)
        if (a[index] < min)    // operator< must be defined for BaseType
        {
            min = a[index];
            indexOfMin = index;
        }

    return indexOfMin;
}


template<typename BaseType>
void sort(BaseType a[], int numberUsed)
{
    int indexOfNextSmallest;
    for(int index = 0; index < numberUsed - 1; index++)
    {
        indexOfNextSmallest =
            indexOfSmallest(a, index, numberUsed);
        swapValues(a[index], a[indexOfNextSmallest]);
    }
}

#endif
