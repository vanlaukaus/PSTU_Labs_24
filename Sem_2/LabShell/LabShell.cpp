#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void ssort(vector<int>& arr) {
    int n = arr.size();

    for (int g = n / 2; g > 0; g /= 2) {
        for (int i = g; i < n; i++) {
            int temp = arr[i];
            int j;

            for (j = i; j >= g && arr[j - g] > temp; j -= g) {
                arr[j] = arr[j - g];
            }

            arr[j] = temp;
        }
    }
}

int main() {
    srand(time(0));

    int size = 20; 
    vector<int> arr(size);

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl;

    ssort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}