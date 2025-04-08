#include <iostream>
#include <cstdlib> 
#include <ctime>   

void selsort(int arr[], int s) {
    for (int i = 0; i < s - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < s; ++j) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            int t = arr[i];
            arr[i] = arr[min];
            arr[min] = t;
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

    selsort(arr, s);

    std::cout << "Sorted array: ";
    for (int i = 0; i < s; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}