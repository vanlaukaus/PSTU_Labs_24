#include <iostream>
#include <vector>
#include <algorithm> 
#include <cstdlib>
#include <ctime>

void sortc(std::vector<int>& arr) {
    if (arr.empty()) return;

    int max_val = *std::max_element(arr.begin(), arr.end());
    int min_val = *std::min_element(arr.begin(), arr.end());

    int range = max_val - min_val + 1;
    std::vector<int> count(range, 0);
    std::vector<int> output(arr.size());

    for (int num : arr) {
        count[num - min_val]++;
    }

    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min_val] - 1] = arr[i];
        count[arr[i] - min_val]--;
    }

    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

int main() {
    std::srand(std::time(0));
    std::vector<int> arr(20);

    for (int& num : arr) {
        num = std::rand() % 100; 
    }

    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    sortc(arr);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}