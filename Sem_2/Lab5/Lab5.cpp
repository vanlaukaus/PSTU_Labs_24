#include <iostream>

using namespace std;

void printarr(int** matrix, int rows, int cols) {
    cout << "Generated array:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}

int maxsum(int** matr, int rows, int cols) {
    int max_sum = -2147483648;

    for (int j = 0; j < cols - 1; ++j) {
        int elements_to_keep = rows - (j + 1);
        if (elements_to_keep <= 0) break;

        int sum = 0;
        for (int i = 0; i < elements_to_keep; ++i) {
            sum += matr[i][j];
        }

        if (sum > max_sum) max_sum = sum;
    }

    return max_sum;
}

unsigned int random(unsigned int& seed) {
    seed = (8253729 * seed + 2396403);
    return seed % 100;
}

int main() {
    const int rows = 5;
    const int cols = 5;
    unsigned int seed = 42; 

    int** arr = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = random(seed) + 1;
        }
    }

    printarr(arr, rows, cols);

    int result = maxsum(arr, rows, cols);
    cout << "Max sum: " << result << "\n";

    return 0;
}