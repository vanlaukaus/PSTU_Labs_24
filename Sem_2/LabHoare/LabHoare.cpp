#include <iostream>
#include <cstdlib>
#include <ctime>

int part(int arr[], int low, int high) {
    int pivot = arr[low + (high - low) / 2];
    int i = low - 1;
    int j = high + 1;

    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j) {
            return j;
        }

        std::swap(arr[i], arr[j]);
    }
}

void hsort(int arr[], int low, int high) {
    if (low < high) {
        int pi = part(arr, low, high);
        hsort(arr, low, pi);
        hsort(arr, pi + 1, high);
    }
}

int main() {
    std::srand(std::time(0));

    const int size = 20;
    int arr[size];

    std::cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        arr[i] = std::rand() % 100; 
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    hsort(arr, 0, size - 1);

    std::cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    return 0;
}