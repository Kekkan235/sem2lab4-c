#include "Rational.h"
#include <numeric> 
#include <cmath>
#include <algorithm> 

using namespace std;
int get_gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void Rational::simplify() {
    if (den == 0) return;
    if (den < 0) { num = -num; den = -den; }

    int common = get_gcd(num, den);

    num /= common;
    den /= common;
}

Rational::Rational(int n, int d) : num(n), den(d) {
    simplify();
}

Rational Rational::operator+(const Rational& other) const {
    return Rational(num * other.den + other.num * den, den * other.den);
}

Rational Rational::operator-(const Rational& other) const {
    return Rational(num * other.den - other.num * den, den * other.den);
}

Rational Rational::operator*(const Rational& other) const {
    return Rational(num * other.num, den * other.den);
}

Rational Rational::operator/(const Rational& other) const {
    return Rational(num * other.den, den * other.num);
}

Rational& Rational::operator+=(const Rational& other) {
    *this = *this + other;
    return *this;
}

Rational& Rational::operator-=(const Rational& other) {
    *this = *this - other;
    return *this;
}

Rational& Rational::operator*=(const Rational& other) {
    *this = *this * other;
    return *this;
}

Rational& Rational::operator/=(const Rational& other) {
    *this = *this / other;
    return *this;
}

bool Rational::operator==(const Rational& other) const {
    return num == other.num && den == other.den;
}

bool Rational::operator!=(const Rational& other) const {
    return !(*this == other);
}
