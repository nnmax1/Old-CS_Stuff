#ifndef DOG_H
#define DOG_H

#include <iostream>
using std:: string;

class Dog
{
    public:
        Dog() { };
        Dog(string n): name(n) { };
        virtual ~Dog() { };

        virtual void bark();

    protected:
        string name = "dog";
};

#endif
