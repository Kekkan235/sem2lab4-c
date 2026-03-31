#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

class Rational {
private:
    int num, den;
    void simplify();

public:
    Rational(int n = 0, int d = 1);

    int Numerator() const { return num; }
    int Denominator() const { return den; }

    Rational operator+(const Rational& other) const;
    Rational operator-(const Rational& other) const;
    Rational operator*(const Rational& other) const;
    Rational operator/(const Rational& other) const;

    Rational operator+() const { return *this; }
    Rational operator-() const { return Rational(-num, den); }

    Rational& operator+=(const Rational& other);
    Rational& operator-=(const Rational& other);
    Rational& operator*=(const Rational& other);
    Rational& operator/=(const Rational& other);

    bool operator==(const Rational& other) const;
    bool operator!=(const Rational& other) const;
};
#endif