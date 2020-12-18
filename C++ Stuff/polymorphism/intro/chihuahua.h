#ifndef CHIHUAHUA_H
#define CHIHUAHUA_H

#include <iostream>
#include "dog.h"

using std::string;

class Chihuahua : public  Dog
{
    public:
        Chihuahua() : Dog() { };
        Chihuahua(string n) : Dog(n) {  };
        virtual ~Chihuahua() { };

        virtual void bark();

};

#endif
