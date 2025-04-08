#include <iostream>
using namespace std;

const int N = 8;
int board[N][N] = { 0 };

bool safe(int row, int col) {
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool res(int col) {
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++) {
        if (safe(i, col)) {
            board[i][col] = 1;

            if (res(col + 1))
                return true;

            board[i][col] = 0;
        }
    }
    return false;
}
void outp() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << (board[i][j] ? " I " : ". ");
        cout << endl;
    }
}
int main() {
    if (res(0))
        outp();
    else
        cout << "No solution exists";

    return 0;
}