#include "List.h"
#include "Pair.h"
#include <iostream>

int main() {
    List<Pair> list1, list2;
    std::cout << "Enter pairs for list1 (e.g., '1:2.5 3:4' end with -1:0): ";
    std::cin >> list1;
    std::cout << "Enter pairs for list2 (end with -1:0): ";
    std::cin >> list2;

    std::cout << "List1: " << list1 << "\n";
    std::cout << "List2: " << list2 << "\n";

    List<Pair> product = list1 * list2;
    std::cout << "Element-wise product: " << product << "\n";
    std::cout << "Size of list1: " << static_cast<int>(list1) << "\n";

    try {
        std::cout << "Element at index 0: " << list1[0] << "\n";
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}