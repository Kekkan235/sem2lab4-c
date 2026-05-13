
#include <iostream>
#include "Complex.h"
#include "Rational.h"

using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");

    cout << "--- Тестирование Complex ---\n";
    Complex c1, c2;
    cout << "Введите два комплексных числа (re im через пробел): ";

    if (!(std::cin >> c1 >> c2)) {
    cout << "Ошибка ввода! Ожидались числа.\n";
        return 1;
    }

    cout << "Введенные числа: " << c1 << " и " << c2 << "\n";
    cout << "Сумма: " << (c1 + c2) << "\n";
    cout << "Произведение: " << (c1 * c2) << "\n";
    cout << "c1 > c2: " << (c1 > c2 ? "Да" : "Нет") << "\n";

    Complex c3 = c1;
    cout << "Копия c1 (через конструктор копирования): " << c3 << "\n";

    // Тестирование Rational
    cout << "\n--- Тестирование Rational ---\n";
    Rational r1(1, 2), r2(1, 3);
    cout << "Дробь r1: " << r1.Numerator() << "/" << r1.Denominator() << "\n";
    Rational res = r1 + r2;
    cout << "Результат 1/2 + 1/3 = " << res.Numerator() << "/" << res.Denominator() << "\n";

    return 0;
}
