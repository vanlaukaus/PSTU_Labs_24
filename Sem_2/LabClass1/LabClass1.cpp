#include "fraction.h"
#include <iostream>

int main() {
    aripr ap1;
    
    std::cout << "Enter progression parameters:\n";
    ap1.read();
    ap1.show();
    
    int j;
    std::cout << "Enter element index to calculate: ";
    std::cin >> j;
    std::cout << "a" << j << " = " << ap1.element(j) << std::endl;
    
    aripr ap2 = make_arithmetic_progression(5.5, 2);
    std::cout << "\nCreated with make function:\n";
    ap2.show();
    std::cout << "a3 = " << ap2.element(3) << std::endl;
    
    return 0;
}