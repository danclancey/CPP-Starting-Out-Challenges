/*
Modify the class Rational of Programming Challenge 8 to add overloaded operators +, −, *, and / to be used for addition, subtraction, 
multiplication, and division. Test the class by reading and processing from the keyboard (or from a file) a series of rational 
expressions such as

        2 / 3 + 2 / 8
        2 / 3 * – 2 / 8
        2 / 3 – 2/ 8
        2 / 3 / 2 / 8

To facilitate parsing of the input, you may assume that numbers and arithmetic operators are separated by whitespace.
*/

#include <iostream>
#include <numeric> 

using namespace std;

class Rational {
private:
    int numerator;
    int denominator;

    void reduce();  // Helper function to reduce the rational number

public:
    // Param Constructor - takes numerator and denominator  
    Rational(int num = 0, int denom = 1);

    // Overloaded arithmetic operators
    Rational operator+(const Rational& rhs) const;
    Rational operator-(const Rational& rhs) const;
    Rational operator*(const Rational& rhs) const;
    Rational operator/(const Rational& rhs) const;

    // Overload stream insertion operator for output
    friend ostream& operator<<(ostream& out, const Rational& r);

    // Overload stream extraction operator for input
    friend istream& operator>>(istream& in, Rational& r);
};

// Param constructor - Takes numerator and denominator integers
Rational::Rational(int num, int denom) : numerator(num), denominator(denom) {
    if (denominator == 0) {
        cout << "Error: Denominator cannot be zero.\n";
        exit(EXIT_FAILURE);
    }
    reduce();
}

// Helper Function - reduce rational number to reduced form
void Rational::reduce() {
    int gcdValue = gcd(numerator, denominator);  // Find the greatest common divisor
    numerator /= gcdValue;
    denominator /= gcdValue;

    // Ensure denominator is positive
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

// Overloaded + operator
Rational Rational::operator+(const Rational& rhs) const {
    int num = numerator * rhs.denominator + rhs.numerator * denominator;
    int denom = denominator * rhs.denominator;
    return Rational(num, denom);
}

// Overloaded - operator
Rational Rational::operator-(const Rational& rhs) const {
    int num = numerator * rhs.denominator - rhs.numerator * denominator;
    int denom = denominator * rhs.denominator;
    return Rational(num, denom);
}

// Overloaded * operator
Rational Rational::operator*(const Rational& rhs) const {
    int num = numerator * rhs.numerator;
    int denom = denominator * rhs.denominator;
    return Rational(num, denom);
}

// Overloaded / operator
Rational Rational::operator/(const Rational& rhs) const {
    if (rhs.numerator == 0) {
        cout << "Error: Division by zero.\n";
        exit(EXIT_FAILURE);
    }
    int num = numerator * rhs.denominator;
    int denom = denominator * rhs.numerator;
    return Rational(num, denom);
}

// Overload << operator for output
ostream& operator<<(ostream& out, const Rational& r) {
    if (r.denominator == 1) {
        out << r.numerator;   // If denom is 1, just print numerator
    } else {
        out << r.numerator << "/" << r.denominator;
    }
    return out;
}

// Overload >> operator for input
istream& operator>>(istream& in, Rational& r) {
    char slash;
    in >> r.numerator >> slash >> r.denominator;
    if (r.denominator == 0) {
        cout << "Error: Denominator cannot be zero.\n";
        exit(EXIT_FAILURE);
    }
    r.reduce();
    return in;
}

int main() {
    Rational r1, r2;
    char op;

    cout << "Enter a rational expression (e.g., 2/3 + 2/8): ";
    cin >> r1 >> op >> r2;

    Rational result;
    switch (op) {
        case '+':
            result = r1 + r2;
            break;
        case '-':
            result = r1 - r2;
            break;
        case '*':
            result = r1 * r2;
            break;
        case '/':
            result = r1 / r2;
            break;
        default:
            cout << "Invalid operator." << endl;
            return 1;
    }

    cout << r1 << " " << op << " " << r2 << " = " << result << endl;

    return 0;
}

