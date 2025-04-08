#include <iostream>
#include <cstdlib> 
#include <ctime>   

void bubbsort(int arr[], int s) {
    for (int i = 0; i < s - 1; ++i) {
        for (int j = 0; j < s - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}

int main() {
    srand(time(0));

    const int s = 10;
    int arr[s];

    for (int i = 0; i < s; ++i) {
        arr[i] = rand() % 100 + 1;
    }

    std::cout << "Unsorted array: ";
    for (int i = 0; i < s; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    bubbsort(arr, s);

    std::cout << "Sorted array: ";
    for (int i = 0; i < s; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}