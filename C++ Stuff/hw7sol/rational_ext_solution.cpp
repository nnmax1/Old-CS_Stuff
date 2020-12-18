
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cassert>
using namespace std;

class Rational {
    public:
        friend Rational operator-(const Rational &rA, const Rational &rB);
        friend Rational operator+(const Rational &rA, const Rational &rB);
        friend Rational operator*(const Rational &rA, const Rational &rB);
        friend Rational operator/(const Rational &rA, const Rational &rB);
        friend bool operator<(const Rational &rA, const Rational &rB);
        friend bool operator>(const Rational &rA, const Rational &rB);
        friend bool operator<=(const Rational &rA, const Rational &rB);
        friend bool operator>=(const Rational &rA, const Rational &rB);
        friend bool operator==(const Rational &rA, const Rational &rB);
        friend bool operator!=(const Rational &rA, const Rational &rB);

        friend ostream& operator<<(ostream &outs, const Rational &r);
        friend istream& operator>>(istream &instr, Rational &r);

        Rational() { };
        Rational(int num) : numerator(num), denominator(1) { }
        Rational(int num, int den);

        int get_numerator() const;
        int get_denominator() const;

    private:
        int numerator = 0;
        int denominator = 1;
};

int gcd(int m, int n);
void normalize(int &numer, int &denom);

int main(int argc, char *argv[])
{
    Rational a(1,2);
    cout << "The rational number a(1,2): " << a << endl;

    Rational b(2);
    cout << "The rational number b(2): " << b << endl;

    Rational c;
    cout << "The default rational number: " << c << endl;

    Rational d(3,48);
    cout << "The rational number d(3,48): " << d << endl;

    ifstream rdata("rationals.txt");
    if (rdata.fail())
    {
        cerr << "File open failed." << endl;
        exit(1);
    }
    cout << "Reading data from rationals.txt..." << endl;
    constexpr int NUMRATS = 5;
    Rational tmp[NUMRATS];
    for (int i = 0; i < NUMRATS; ++i)
        rdata >> tmp[i];

    for (int i = 0; i < NUMRATS; ++i)
        cout <<  tmp[i] << endl;

    rdata.close();

    Rational result;
    result = tmp[0] + tmp[3];
    cout << "adding " << tmp[0] << " + " << tmp[3] << " = " << result << endl;
    result = tmp[0] - tmp[1];
    cout << "subtracting " << tmp[0] << " - " << tmp[1] << " = " << result << endl;

    result = c + c;
    cout << "Adding 0/1 + 0/1 = " << result << endl;

    cout << "Testing declarations" << endl;
    cout << "Rational x, y(2), z(-5,-6), w(1,-3);" << endl;
    Rational x, y(2), z(-5,-6), w(1,-3);
    cout << "z = " << z << ", y = " << y << ",  z = " << z
        << ", w = " << w << endl;

    cout << "Testing >> overloading: \nEnter "
        << "a fraction in the format "
        << "integer_numerator/integer_denominator" 
        << endl;
    cin >> x;
    cout << "You entered the equivalent of: " << x << endl;
    cout << z << " -  (" << w << ") = " << z - w << endl;

    cout << "Testing the constructor and normalization routines: " << endl;
    y =Rational(-128, -48);
    cout << "y = Rational(-128, -48) outputs as " << y << endl;
    y =Rational(-128, 48);
    cout << "y = Rational(-128, 48) outputs as " << y << endl;
    y = Rational(128,-48);
    cout << "y = Rational(128, -48) outputs as " << y << endl;
    Rational e(1,1);
    cout << "Rational e(1,1); e outputs as: " << e << endl;
    Rational ww = y*e;
    cout <<  y << " * " << e << " = " << ww << endl;

    w = Rational(25,9);
    z = Rational(3,5);
    cout << "Testing arithmetic and relational " 
        << " operator overloading" << endl;
    cout << w << " * " << z << " = " << w * z << endl;
    cout << w << " + " << z << " = " << w + z << endl;
    cout << w << " - " << z << " = " << w - z << endl;
    cout << w << " / " << z << " = " << w / z << endl;

    cout << w << " <  " << z << " = " << (w < z) << endl;
    cout << w << " < " << w << " = " << (w < w) << endl;
    cout << w << " <= " << z << " = " << (w <= z) << endl;
    cout << w << " <= " << w << " = " << (w <= w) << endl;

    cout << w << " >  " << z << " = " << (w > z) << endl;
    cout << w << " > " << w << " = " << (w > w) << endl;
    cout << w << " >= " << z << " = " << (w >= z) << endl;
    cout << w << " >= " << w << " = " << (w >= w) << endl;

    assert(w == w);
    assert(w != z);
    assert(z < w);
    assert(w > z);
    assert(w <= w);
    assert(z >= z);

    w = Rational(-21,9);
    z = Rational(3,5);
    cout << w << " * " << z << " = " << w * z << endl;
    cout << w << " + " << z << " = " << w + z << endl;
    cout << w << " - " << z << " = " << w - z << endl;
    cout << w << " / " << z << " = " << w / z << endl;
    cout << w << " <  " << z << " = " << (w < z) << endl;
    cout << w << " < " << w << " = " << (w < w) << endl;
    cout << w << " <= " << z << " = " << (w <= z) << endl;
    cout << w << " <= " << w << " = " << (w <= w) << endl;

    cout << w << " >  " << z << " = " << (w > z) << endl;
    cout << w << " > " << w << " = " << (w > w) << endl;
    cout << w << " >= " << z << " = " << (w >= z) << endl;
    cout << w << " >= " << w << " = " << (w >= w) << endl;

    return 0;
}


int gcd(int m, int n)
{
    // check for 0 numerator
    if (m == 0)
        return 1;
    int t;
    m = abs(m);
    n = abs(n);
    if (n < m)
    {
        t = m;
        m = n;
        n = t;
    }
    int r = m % n;
    while (r != 0)
    {
        r = m % n;
        m = n;
        n = r;
    }
    return m;
}


void normalize(int &numer, int &denom)
{
    assert(denom != 0);
    int g = gcd(numer, denom);
    numer = numer / g;
    denom = denom / g;

    if ( (numer > 0 && denom < 0) || (numer < 0 && denom < 0) )
    {
        numer = -numer;
        denom = -denom;
    }
}

Rational::Rational(int num, int den)
{
    normalize(num, den);
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

int Rational::get_numerator() const
{
    return numerator;
}

int Rational::get_denominator() const
{
    return denominator;
}

Rational operator+(const Rational &rA, const Rational &rB)
{
    int num = rA.numerator * rB.denominator + rA.denominator * rB.numerator;
    int den = rA.denominator * rB.denominator;
    normalize(num, den);
    Rational sum(num, den);
    return sum;
}

Rational operator-(const Rational &rA, const Rational &rB)
{
    int num = rA.numerator * rB.denominator - rA.denominator * rB.numerator;
    int den = rA.denominator * rB.denominator;
    normalize(num, den);
    Rational difference(num, den);
    return difference;
}

Rational operator*(const Rational &rA, const Rational &rB)
{
    int num = rA.numerator * rB.numerator;
    int den = rA.denominator * rB.denominator;
    normalize(num, den);
    Rational product(num, den);
    return product;
}


Rational operator/(const Rational &rA, const Rational &rB)
{
    int num = rA.numerator * rB.denominator;
    int den = rA.denominator * rB.numerator;
    normalize(num, den);
    Rational quotient(num, den);
    return quotient;
}


bool operator==(const Rational &rA, const Rational &rB)
{
    return (rA.numerator * rB.denominator == rB.numerator * rA.denominator);
}


bool operator!=(const Rational &rA, const Rational &rB)
{
    return !(rA == rB);
}


bool operator<(const Rational &rA, const Rational &rB)
{
    return (rA.numerator * rB.denominator < rB.numerator * rA.denominator);
}


bool operator>(const Rational &rA, const Rational &rB)
{
    return (rA.numerator * rB.denominator > rB.numerator * rA.denominator);
}


bool operator<=(const Rational &rA, const Rational &rB)
{
    return (rA < rB) || (rA == rB);
}


bool operator>=(const Rational &rA, const Rational &rB)
{
    return (rA > rB) || (rA == rB);
}

ostream& operator<<(ostream &outs, const Rational &r)
{
    outs << r.numerator << '/' << r.denominator;
    return outs;
}

istream& operator>>(istream &instr, Rational &r)
{
    char ch;
    instr >> r.numerator >> ch >> r.denominator;
    if (ch != '/')
    {
        instr.setstate(ios::failbit);
        cerr << "bad rational number format" << endl;
        exit(1);
    }
    normalize(r.numerator, r.denominator);
    return instr;
}

