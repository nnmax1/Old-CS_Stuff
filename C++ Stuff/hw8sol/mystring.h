

#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <iostream>

class MyString {

  public:

    // default constructor
    MyString();

    // overloaded constructor
    MyString(const char* p);

    // destructor
    ~MyString();

    // copy constructor 
    MyString(const MyString& s);

    // assignment operator
    MyString& operator=(const MyString& s);

    // concatenates two strings
    friend MyString operator+(const MyString& s1, const MyString& s2);

    // insertion (or put-to) operator
    friend std::ostream& operator<<(std::ostream& os, const MyString& s);

    // extraction (or get-from) operator
    friend std::istream& operator>>(std::istream& is, MyString& s);

  private:
    char* data;
    int len;
};

#endif
