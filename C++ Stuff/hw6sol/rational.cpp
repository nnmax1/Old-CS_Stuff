
#include <iostream>
#include <cstdlib>   // for exit()


class Rational {
    public:
        // Constructors
        Rational() { }
        Rational(int num, int den);
        // Constructor using initializer list
        Rational(int num) : numerator(num) { }

        // Member functions
        bool input();
        void output();
        int get_numerator();
        int get_denominator();
        void sum(const Rational &a, const Rational &b);

    private:
        // In-class initializers set default values
        // for member variables.
        int numerator = 0;
        int denominator = 1;
};

// main tests the Rational class
int main()
{
    using namespace std;
    Rational a(1,2);
    cout << "The rational number a(1,2):\n";
    a.output();

    cout << "Getting the numerator: " << a.get_numerator();
    cout << " [expected: 1]" << endl;
    cout << "Getting the denominator: " << a.get_denominator();
    cout << " [expected: 2]" << endl;

    Rational b(2);
    cout << "The rational number b(2):\n";
    b.output();
    Rational c;
    cout << "The default rational number:\n";
    c.output();
    if (!c.input())
    {
        cout << "Invalid rational number." << endl;
        exit(1);
    }
    c.output();

    cout << "The sum of 1/2 + 2/1 = 5/2:\n";
    c.sum(a,b);
    c.output();

    Rational d(-2,1);
    Rational e(2,1);
    Rational f;
    f.sum(d,e);
    cout << "The sum of -2/1 + 2/1 = 0/1:\n";
    f.output();

    return 0;
}


Rational::Rational(int num, int den)
{
    if (den)
    {
        numerator = num;
        denominator = den;
    }
    else
    {
        std::cout << "Illegal rational number: cannot have 0 in denominator."
             << std::endl;
        exit(1);
    }
}

int Rational::get_numerator()
{
    return numerator;
}

int Rational::get_denominator()
{
    return denominator;
}

// Input a rational number.
// Returns true if a valid rational number in the form n/m was entered,
// false otherwise.
bool Rational::input()
{
    char op;
    std::cout << "Enter a rational number in the form n/m (n, m are ints): ";
    std::cin >> numerator;
    std::cin >> op;
    std::cin >> denominator;

    if (op != '/' || denominator == 0)
        return false;
    
    return true;
}

void Rational::output()
{
    std::cout << numerator << '/' << denominator << std::endl;
    return;
}

void Rational::sum(const Rational &a, const Rational &b)
{
    numerator = a.numerator * b.denominator + a.denominator * b.numerator;
    denominator = a.denominator * b.denominator;
    return;
}

