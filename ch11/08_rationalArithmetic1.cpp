/*
A rational number is a quotient of two integers. For example, 12/5, 12/–4, –3/4, and 4/6 are all rational numbers. A rational number 
is said to be in reduced form if its denominator is positive and its numerator and denominator have no common divisor other than 1. 
For example, the reduced forms of the rational numbers given above are 12/5, –3/1, –3/4, and 2/3.

Write a class called Rational with a constructor Rational(int, int) that takes two integers, a numerator and a denominator, and stores 
those two values in reduced form in corresponding private members. The class should have a private member function void reduce() that 
is used to accomplish the transformation to reduced form. The class should have an overloaded insertion operator << that will be used 
for output of objects of the class.
*/

#include <iostream>
#include <numeric>

using namespace std;

class Rational {
    private:
        int numerator;
        int denominator;

        void reduce();

    public:
        Rational(int num, int denom);
        friend ostream& operator<<(ostream& out, const Rational& r);

};

// Helper Function - reduce rational number to reduced form 
void Rational::reduce() {
    int gcdValue = gcd(numerator, denominator);
    numerator /= gcdValue;
    denominator /= gcdValue; 
    
    // Ensure denom is positive 
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

// Param constructor - Takes numerator and denominator integers 
Rational::Rational(int num, int denom) : numerator(num), denominator(denom) {
    if (denominator == 0) {
        cout << "Error: Denominator cannot be zero.\n";
        exit(EXIT_FAILURE);
    }

    reduce();
}

// Overload << oeprator for output 
ostream& operator<<(ostream& out, const Rational& r) {
    if (r.denominator == 1) {
        out << r.numerator;   // If denom is 1, just print numerator
    } else {
        out << r.numerator << "/" << r.denominator;
    }

    return out;
}

int main() {
    // Create test case objects 
    Rational r1(12, 5);
    Rational r2(12, -4);
    Rational r3(-3, 4);
    Rational r4(4, 6);

    cout << "12/5 Reduced:  " << r1 << endl;
    cout << "12/-4 Reduced: " << r2 << endl;
    cout << "-3/4 Reduced:  " << r3 << endl;
    cout << "4/6 Reduced:   " << r4 << endl;

    return 0;
}
