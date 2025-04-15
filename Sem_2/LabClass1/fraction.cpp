#include "fraction.h"
#include <iostream>
#include <cmath>

void aripr::init(double a0, unsigned r) {
    first = a0;
    second = r;
}

void aripr::read() {
    std::cout << "Enter the first element (a0): ";
    std::cin >> first;
    
    std::cout << "Enter the common difference (r): ";
    std::cin >> second;
    
    while (second <= 0) {
        std::cout << "Common difference must be positive. Enter again: ";
        std::cin >> second;
    }
}

void aripr::show() const {
    std::cout << "Arithmetic Progression: a0 = " << first 
              << ", r = " << second << std::endl;
}

double aripr::element(int j) const {
    return first + second * j;
}

aripr make_arithmetic_progression(double a0, unsigned r) {
    aripr ap;
    ap.init(a0, r);
    return ap;
}