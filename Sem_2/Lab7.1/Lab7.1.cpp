#include <iostream>
#include <cmath>

// Перегруженная функция для возведения целого числа в степень n
int power(int base, int exp) {
    if (exp == 0) return 1;
    int result = 1;
    for (int i = 0; i < exp; ++i) {
        result *= base;
    }
    return result;
}

// Перегруженная функция для извлечения корня степени n из десятичного числа
double root(double number, int n) {
    if (n == 0) {
        std::cerr << "Error, the root's power cannot be zero." << std::endl;
        return 0.0;
    }
    if (number < 0 && n % 2 == 0) {
        std::cerr << "Error, an even root cannot be extracted from a negative number." << std::endl;
        return 0.0;
    }
    return pow(number, 1.0 / n);
}

int main() {
    // Демонстрация работы функции power
    int base = 2;
    int exp = 10;
    std::cout << base << " raised to the power of " << exp << " = " << power(base, exp) << std::endl;

    // Демонстрация работы функции root
    double number = 125.0;
    int n = 3;
    std::cout << "The " << n << "th root of " << number << " = " << root(number, n) << std::endl;

    return 0;
}