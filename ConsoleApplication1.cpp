/**
 * Выполнил: (Твое ФИО)
 * Программа реализует классы Complex и Rational с переопределением операторов.
 * Входные данные: ввод чисел пользователем с клавиатуры.
 * Выходные данные: результаты арифметических и логических операций.
 */

#include <iostream>
#include "Complex.h"
#include "Rational.h"

int main() {
    // Настройка вывода для корректного отображения (по желанию)
    setlocale(LC_ALL, "Russian");

    // Тестирование Complex
    std::cout << "--- Тестирование Complex ---\n";
    Complex c1, c2;
    std::cout << "Введите два комплексных числа (re im через пробел): ";

    if (!(std::cin >> c1 >> c2)) {
        std::cout << "Ошибка ввода! Ожидались числа.\n";
        return 1;
    }

    std::cout << "Введенные числа: " << c1 << " и " << c2 << "\n";
    std::cout << "Сумма: " << (c1 + c2) << "\n";
    std::cout << "Произведение: " << (c1 * c2) << "\n";
    std::cout << "c1 > c2: " << (c1 > c2 ? "Да" : "Нет") << "\n";

    Complex c3 = c1;
    std::cout << "Копия c1 (через конструктор копирования): " << c3 << "\n";

    // Тестирование Rational
    std::cout << "\n--- Тестирование Rational ---\n";
    Rational r1(1, 2), r2(1, 3);
    std::cout << "Дробь r1: " << r1.Numerator() << "/" << r1.Denominator() << "\n";
    Rational res = r1 + r2;
    std::cout << "Результат 1/2 + 1/3 = " << res.Numerator() << "/" << res.Denominator() << "\n";

    return 0;
}