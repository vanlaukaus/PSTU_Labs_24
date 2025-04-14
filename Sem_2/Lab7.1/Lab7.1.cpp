//v15
#include <iostream>
#include <cmath>

int calcfunc(int base, int n) {
    int result = 1;
    for (int i = 0; i < n; ++i) {
        result *= base;
    }
    return result;
}

double calcfunc(double base, int n) {
    if (base < 0 && n % 2 == 0) {
        std::cerr << "Cannot extract an even root of a negative number!" << std::endl;
        return NAN;
    }
    return pow(base, 1.0 / n);
}

int main() {

    int intbase = 2;
    int exp = 3;
    std::cout << intbase << " raised to the power of " << exp << " = " << calcfunc(intBase, exponent) << std::endl;
    
    double doubbase = 27.0;
    int deg = 3;
    std::cout << "The " << deg << "th root of " << doubbase << " = " << calcfunc(doubbase, deg) << std::endl;
    
    return 0;
}
