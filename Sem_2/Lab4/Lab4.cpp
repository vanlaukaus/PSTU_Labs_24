//Вариант 15

#include <iostream>
using namespace std;

int main() {
    const int ogsize = 10;
    int arr[ogsize] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int currsize = ogsize;

    cout << "Original array: ";
    for (int i = 0; i < currsize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;

    // 4.2
    int k = 3;
    cout << "Left print from k=" << k << ": ";
    if (currsize > 0) {
        k = k % currsize;
        for (int i = 0; i < currsize; i++) {
            cout << arr[(k - i + currsize) % currsize] << " ";
        }
    }
    cout << endl << endl;

    // 4.3
    if (currsize > 0) {
        for (int i = 0; i < currsize - 1; i++) {
            arr[i] = arr[i + 1];
        }
        currsize--;
        if (currsize > 0) currsize--;
    }

    cout << "Modified array: ";
    for (int i = 0; i < currsize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;

    // 4.4
    k = 2;
    cout << "Right print from k=" << k << ": ";
    if (currsize > 0) {
        k = k % currsize;
        for (int i = 0; i < currsize; i++) {
            cout << arr[(k + i) % currsize] << " ";
        }
    }
    cout << endl;

    return 0;
}
