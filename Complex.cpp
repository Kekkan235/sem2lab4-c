#include "Complex.h"
#include <cmath>


using namespace std;
Complex::Complex() : re(0), im(0) {}

Complex::Complex(double x, double y) : re(x), im(y) {}

Complex::Complex(const Complex& other) : re(other.re), im(other.im) {}

Complex& Complex::operator=(const Complex& other) {
    if (this != &other) {
        re = other.re;
        im = other.im;
    }
    return *this;
}

Complex Complex::operator+(const Complex& other) const {
    return Complex(re + other.re, im + other.im);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(re - other.re, im - other.im);
}

Complex Complex::operator*(const Complex& other) const {
    return Complex(re * other.re - im * other.im, re * other.im + im * other.re);
}

Complex Complex::operator/(const Complex& other) const {
    double denom = other.re * other.re + other.im * other.im;
    return Complex((re * other.re + im * other.im) / denom, (im * other.re - re * other.im) / denom);
}

Complex& Complex::operator++() { re++; im++; return *this; }
Complex Complex::operator++(int) { Complex temp = *this; ++(*this); return temp; }
Complex& Complex::operator--() { re--; im--; return *this; }
Complex Complex::operator--(int) { Complex temp = *this; --(*this); return temp; }

double Complex::abs() const { return std::sqrt(re * re + im * im); }

bool Complex::operator>(const Complex& other) const { return this->abs() > other.abs(); }
bool Complex::operator<(const Complex& other) const { return this->abs() < other.abs(); }
bool Complex::operator==(const Complex& other) const { return re == other.re && im == other.im; }
bool Complex::operator!=(const Complex& other) const { return !(*this == other); }

ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.re << (c.im >= 0 ? " + " : " - ") << std::abs(c.im) << " * i";
    return os;
}

istream& operator>>(std::istream& is, Complex& c) {
    is >> c.re >> c.im;
    return is;
}
