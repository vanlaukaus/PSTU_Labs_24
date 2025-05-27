#include <iostream>
#include "Pair.h"

int main() {
    Pair p1(10, 5.5);
    Pair p2(3, 2.3);

    Pair p3 = p1 - p2;
    std::cout << "p1 - p2 = " << p3 << std::endl;

    Pair p4 = p1 + 5;
    std::cout << "p1 + 5 = " << p4 << std::endl;

    Pair p5 = p1 + 2.5;
    std::cout << "p1 + 2.5 = " << p5 << std::endl; 

    Pair p6;
    std::cout << "Input your pair: ";
    std::cin >> p6;
    std::cout << "Received: " << p6 << std::endl;

    Pair p7 = p1 - p6;
    std::cout << "p1 - p6 = " << p7 << std::endl;

    Pair p8 = p6 - p2;
    std::cout << "p6 - p2 = " << p8 << std::endl;

    Pair p9 = p6 + 10;
    std::cout << "p6 + 10 = " << p9 << std::endl;

    Pair p10 = p6 + 56.14;
    std::cout << "p6 + 3.14 = " << p10 << std::endl;

    return 0;
}