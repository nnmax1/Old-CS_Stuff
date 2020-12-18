
#include <iostream>
#include <string>
using namespace std;


class MyBase 
{
    public:
        MyBase() {
            cout << "[" << this << "] MyBase: Default constructor." << endl;
        }
        MyBase(char l, int n) : base_ltr(l), base_data(n) {
            cout << "[" << this <<  "] MyBase: Overloaded constructor." << endl;
        }

        virtual ~MyBase() {
            cout << "[" << this << "] MyBase: Destructor." << endl;
        }

        void print_data() {
            cout << "MyBase version:\n";
            cout << base_ltr << " " << base_data << endl;
        }

    private:
        char base_ltr = 'X';

    protected:
        int base_data = -1;
};


class MyChild : public MyBase
{
    public:
        MyChild() : MyBase() {
            cout << "[" << this << "] MyChild: Default constructor." << endl;
            child_msg = "default message";
            base_data = 100;
        }

        MyChild(char l, int n, string m) : MyBase(l, n) , child_msg(m) {
            cout << "[" << this << "] MyChild: Overloaded constructor." << endl;
        }

        virtual ~MyChild() {
            cout << "[" << this << "] MyChild: Destructor." << endl;
        }
/*
        void print_data() {
            cout << base_ltr << " " << base_data << endl;
            cout << "MyChild version:\n";
            cout << child_msg << endl;
        }
*/
  
        void print_data() {
            MyBase::print_data();
            cout << "MyChild version:\n";
            cout << child_msg << endl;
        }
  
    private:
        string child_msg;

};

int main()
{
    MyBase base1;
    cout << endl;
    MyBase base2('A', 17);
    cout << endl;

    MyChild child1;
    cout << endl;
    MyChild child2('Z', -17, "quarantine");
    cout << endl;

    base1.print_data();
    cout << endl;
    base2.print_data();
    cout << endl;
    child1.print_data();
    cout << endl;
    child2.print_data();
    cout << endl;

    return 0;
}

