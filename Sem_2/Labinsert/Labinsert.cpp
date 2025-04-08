#include <iostream>
#include <cstdlib>
#include <ctime> 

void inssort(int arr[], int s) {
    for (int i = 1; i < s; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    srand(time(0));

    const int size = 10;
    int arr[s];

    for (int i = 0; i < s; ++i) {
        arr[i] = rand() % 100 + 1;
    }

    std::cout << "Unsorted array: ";
    for (int i = 0; i < s; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    inssort(arr, s);

    std::cout << "Sorted array: ";
    for (int i = 0; i < s; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}