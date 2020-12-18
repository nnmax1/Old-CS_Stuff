#ifndef GERMANSHEPHERD_H
#define GERMANSHEPHERD_H

#include <iostream>
#include "dog.h"

using std::string;

class GermanShepherd : public Dog
{
    public:
        GermanShepherd() : Dog() { };
        GermanShepherd(string n) : Dog(n) {  };
        virtual ~GermanShepherd() { };

        virtual void bark();

};

#endif
