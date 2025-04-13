#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void sort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        sort(arr, left, mid);
        sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    std::srand(std::time(0));

    const int size = 20;
    std::vector<int> arr(size);

    for (int i = 0; i < size; i++) {
        arr[i] = std::rand() % 100 + 1;
    }

    std::cout << "Original array:\n";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n\n";

    sort(arr, 0, size - 1);

    std::cout << "Sorted array:\n";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}