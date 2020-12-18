

#include <cstring>
#include <cstdio>

#include "mystring.h"

// Default constructor
MyString::MyString() 
{
    data = new char[1];
    data[0] = '\0';
    len = 0;
}

// Overloaded Constructor
MyString::MyString(const char* p)
{
    if (p) 
    {
        len = strlen(p);
        data = new char[len+1];
        strncpy(data, p, len+1);
    } else 
    {
        data = new char[1];
        data[0] = '\0';
        len = 0;
    }
}

// Destructor
MyString::~MyString() 
{
    delete [] data;
}

// Copy constructor 
MyString::MyString(const MyString& s) 
{
    len = s.len;
    data = new char[len+1];
    strncpy(data, s.data, len+1);
}

// Assignment operator
MyString& MyString::operator=(const MyString& rhs)
{
    if (this == &rhs) 
    {
        return *this;
    }

    // first, deallocate memory that 'this' used to hold
    delete [] data;

    // now copy from rhs
    len = rhs.len;
    data = new char[len+1];
    // initialize data
    for (int i = 0; i < len+1; ++i)
        data[i] = '\0';
    strncpy(data, rhs.data, len+1);

    return *this;
}

// operator+
MyString operator+(const MyString& s1, const MyString& s2)
{

    MyString temp;

    delete [] temp.data;

    temp.len = s1.len + s2.len;

    temp.data = new char[temp.len+1];
    strncpy(temp.data, s1.data, temp.len+1);
    int n = (temp.len + 1) - strlen(temp.data);
    strncat(temp.data, s2.data, n);

    return temp;
}

// put-to operator
std::ostream& operator<<(std::ostream& os, const MyString& s)
{
    os << s.data;
    return os;
}

// get-from operator
std::istream& operator>>(std::istream& is, MyString& s)
{

    std::string temp;
    is >> temp;

    delete [] s.data;

    s.len = strlen(temp.c_str());
    s.data = new char[s.len+1];
    strncpy(s.data, temp.c_str(), s.len+1);

    return is;
}

