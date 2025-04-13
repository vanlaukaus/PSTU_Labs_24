#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int ints(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        int pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[pos] == target) {
            return pos;
        }
        else if (arr[pos] < target) {
            low = pos + 1;
        }
        else {
            high = pos - 1;
        }
    }
    return -1;
}

int main() {
    srand(time(0));

    const int SIZE = 200;
    int arr[SIZE];

    arr[0] = rand() % 10;
    for (int i = 1; i < SIZE; i++) {
        arr[i] = arr[i - 1] + (rand() % 5 + 1);
    }

    cout << "Generated sorted array:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n\n";

    int target;
    cout << "Enter a number to search: ";
    cin >> target;

    int result = ints(arr, SIZE, target);

    if (result != -1) {
        cout << "Number found at index " << result << endl;
    }
    else {
        cout << "Number not found in the array" << endl;
    }

    return 0;
}