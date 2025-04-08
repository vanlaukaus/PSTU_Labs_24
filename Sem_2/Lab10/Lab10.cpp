//v15
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    int rows, cols;
    cout << "Input the number of rows: ";
    cin >> rows;
    cout << "Input the number of columns: ";
    cin >> cols;

    int** arr = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols];
    }

    cout << "\nOriginal array:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = rand() % 100;
            cout << arr[i][j] << "\t";
        }
        cout << "\n";
    }

    int maxVal = arr[0][0];
    int maxRow = 0, maxCol = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (arr[i][j] > maxVal) {
                maxVal = arr[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }
    cout << "\nBiggest value: " << maxVal << " (row " << maxRow + 1 << ", column " << maxCol + 1 << ")\n";

    int newRows = rows - 1;
    int newCols = cols - 1;
    int** newArr = new int* [newRows];
    for (int i = 0; i < newRows; ++i) {
        newArr[i] = new int[newCols];
    }

    for (int i = 0, new_i = 0; i < rows; ++i) {
        if (i == maxRow) continue;
        for (int j = 0, new_j = 0; j < cols; ++j) {
            if (j == maxCol) continue; 
            newArr[new_i][new_j] = arr[i][j];
            new_j++;
        }
        new_i++;
    }

    cout << "\nArray with the row and column containing the biggest value removed:\n";
    for (int i = 0; i < newRows; ++i) {
        for (int j = 0; j < newCols; ++j) {
            cout << newArr[i][j] << "\t";
        }
        cout << "\n";
    }

    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    for (int i = 0; i < newRows; ++i) {
        delete[] newArr[i];
    }
    delete[] newArr;

    return 0;
}
