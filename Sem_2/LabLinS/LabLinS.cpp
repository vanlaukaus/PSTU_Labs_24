#include <iostream>
#include <cstdlib>
#include <ctime>   

using namespace std;

int lins(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1;
}

int main() {
    srand(time(0));

    const int size = 150;
    int arr[size];

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100 + 1;
    }

    cout << "Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    int target;
    cout << "Enter a number to search for: ";
    cin >> target;

    int res = lins(arr, size, target);

    if (res != -1) {
        cout << "Found at index " << res << endl;
    }
    else {
        cout << "Not found in the array" << endl;
    }

    return 0;
}