

#include "mystring.h"

MyString add(MyString s1, MyString s2)
{
    MyString temp(" and ");
    return s1 + temp + s2;
}

int main() 
{
    using namespace std;

    MyString s1;

    MyString s2("hello");

    MyString s3(s2);

    s1 = s2;

    cout << s1 << "," << s2 << "," << s3 << endl;

    MyString s4("hello ");

    MyString s5("world!");

    MyString s6;
    
    s6 = s4 + s5;

    cout << s6 << endl;
    
    cout << s4 + s5 << endl;
    
    cout << s4 + "world!" << endl;
    
    cout << "hello " + s5 << endl;

    // this is an error
    // cout << "hello " + "world!" << endl;

    MyString s7("one");
    MyString s8("two");

    MyString s9 = add(s7, s8);

    cout << s9 << endl;

    return 0;
}

