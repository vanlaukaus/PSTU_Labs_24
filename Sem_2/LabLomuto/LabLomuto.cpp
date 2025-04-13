#include <iostream>
#include <cstdlib>
#include <ctime>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];  
    int i = low;           

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            std::swap(arr[i], arr[j]);
            i++;  
        }
    }
    std::swap(arr[i], arr[high]);
    return i;
}

void sort(int arr[], int low, int high) {
    if (low < high) {

        int pi = partition(arr, low, high);

        sort(arr, low, pi - 1);
        sort(arr, pi + 1, high);
    }
}

void arraygen(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; 
    }
}

void arrayprint(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    srand(time(0));

    const int SIZE = 10;
    int arr[SIZE];

    arraygen(arr, SIZE);

    std::cout << "Original array: ";
    arrayprint(arr, SIZE);

    sort(arr, 0, SIZE - 1);

    std::cout << "Sorted array: ";
    arrayprint(arr, SIZE);

    return 0;
}