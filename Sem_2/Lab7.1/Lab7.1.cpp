//v15
#include <iostream>
#include <cmath>

// Ïåðåãðóæåííàÿ ôóíêöèÿ äëÿ âîçâåäåíèÿ öåëîãî ÷èñëà â ñòåïåíü n
int power(int base, int exp) {
    if (exp == 0) return 1;
    int result = 1;
    for (int i = 0; i < exp; ++i) {
        result *= base;
    }
    return result;
}

// Ïåðåãðóæåííàÿ ôóíêöèÿ äëÿ èçâëå÷åíèÿ êîðíÿ ñòåïåíè n èç äåñÿòè÷íîãî ÷èñëà
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
    // Äåìîíñòðàöèÿ ðàáîòû ôóíêöèè power
    int base = 2;
    int exp = 10;
    std::cout << base << " raised to the power of " << exp << " = " << power(base, exp) << std::endl;

    // Äåìîíñòðàöèÿ ðàáîòû ôóíêöèè root
    double number = 125.0;
    int n = 3;
    std::cout << "The " << n << "th root of " << number << " = " << root(number, n) << std::endl;

    return 0;
}
