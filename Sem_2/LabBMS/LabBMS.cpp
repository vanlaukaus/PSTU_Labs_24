#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <ctime>

std::unordered_map<int, int> badheur(const std::vector<int>& pattern) {
    std::unordered_map<int, int> badChar;
    int m = pattern.size();

    for (int i = 0; i < m - 1; ++i) {
        badChar[pattern[i]] = m - 1 - i;
    }

    return badChar;
}

int bms(const std::vector<int>& array, const std::vector<int>& pattern) {
    int n = array.size();
    int m = pattern.size();

    if (m == 0 || m > n) return -1;

    auto badChar = badheur(pattern);

    int shift = 0;
    while (shift <= n - m) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == array[shift + j]) {
            j--;
        }

        if (j < 0) {
            return shift;
        }
        else {
            int bcShift = badChar.count(array[shift + j]) ?
                badChar[array[shift + j]] : m;
            shift += std::max(1, bcShift - (m - 1 - j));
        }
    }

    return -1;
}

int main() {
    std::srand(std::time(0));

    int arraySize = 200;
    std::vector<int> array(arraySize);
    for (int i = 0; i < arraySize; ++i) {
        array[i] = std::rand() % 10;
    }

    std::cout << "Generated array: ";
    for (int num : array) {
        std::cout << num << " ";
    }
    std::cout << "\n\n";

    std::cout << "Enter the pattern to search for: ";
    std::vector<int> pattern;
    int num;

    while (std::cin >> num) {
        pattern.push_back(num);
        if (std::cin.peek() == '\n') break;
    }

    int index = bms(array, pattern);

    if (index != -1) {
        std::cout << "\nPattern found starting at index " << index << "\n";
    }
    else {
        std::cout << "\nPattern not found in the array\n";
    }

    return 0;
}