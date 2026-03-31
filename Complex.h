#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

// Класс для работы с комплексными числами [cite: 51]
class Complex {
private:
    double re, im; // Поля действительной и мнимой части [cite: 52]

public:
    Complex(); // Конструктор по умолчанию [cite: 53]
    Complex(double x, double y); // Конструктор с параметрами [cite: 53]
    Complex(const Complex& other); // Конструктор копирования [cite: 54]

    Complex& operator=(const Complex& other); // Оператор присваивания [cite: 54]

    // Арифметические операции [cite: 56]
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;

    // Инкремент и декремент [cite: 57, 58]
    Complex& operator++();    // Префиксный
    Complex operator++(int);  // Постфиксный
    Complex& operator--();    // Префиксный
    Complex operator--(int);  // Постфиксный

    // Логические операции (по модулю) [cite: 59]
    double abs() const;
    bool operator>(const Complex& other) const;
    bool operator<(const Complex& other) const;
    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;

    // Ввод-вывод [cite: 60]
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& is, Complex& c);
};

#endif