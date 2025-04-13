#include <iostream>
#include <algorithm> 
#include <cstdlib> 
#include <ctime>    

using namespace std;

int bins(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1; 
}

int main() {

    srand(time(0));

    const int SIZE = 150;
    int arr[SIZE];

    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 500;
    }

    sort(arr, arr + SIZE);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    int target;
    cout << "Enter a number to search for: ";
    cin >> target;

    int res = bins(arr, SIZE, target);

    if (res != -1)
        cout << "Found " << target << " at index " << res << endl;
    else
        cout << target << " not found in the array." << endl;

    return 0;
}