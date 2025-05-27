#include "List.h"
#include <iostream>

int main() {
    List<int> list1, list2;
    std::cout << "Enter elements for list1 (end with -1): ";
    std::cin >> list1;
    std::cout << "Enter elements for list2 (end with -1): ";
    std::cin >> list2;

    std::cout << "List1: " << list1 << "\n";
    std::cout << "List2: " << list2 << "\n";

    List<int> product = list1 * list2;
    std::cout << "Element-wise product: " << product << "\n";
    std::cout << "Size of list1: " << static_cast<int>(list1) << "\n";

    try {
        std::cout << "Element at index 1: " << list1[1] << "\n";
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}