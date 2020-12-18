#include <iostream>
#include "germanshepherd.h"
#include "chihuahua.h"
#include "dog.h"

using namespace std;


void callbark(Dog *d)
{
    d->bark();
}


int main()
{
    Dog doggy;
    GermanShepherd shep1;
    Chihuahua chi1;

    doggy.bark();
    shep1.bark();
    chi1.bark();


    GermanShepherd shep2("Max");
    Chihuahua chi2("Fifi");

    shep2.bark();
    chi2.bark();


    Dog *dog1, *dog2, *dog3;
    dog1 = new Dog();
    dog2 = new GermanShepherd("Max2");
    dog3 = new Chihuahua("Fifi2");

    cout << "\n";
    dog1->bark();
    dog2->bark();
    dog3->bark();


    cout << "\n";
    callbark(dog1);
    callbark(dog2);
    callbark(dog3);

    cout << "\n";
    Dog *dogs[3] = {dog1, dog2, dog3};
    for (auto d : dogs)
        callbark(d);


    delete dog1;
    delete dog2;
    delete dog3;

    return 0;
}
