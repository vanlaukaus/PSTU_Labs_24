#include <iostream>
using namespace std;

int main()
{
    cout << "Any natural number greater than 2: ";
    int N;
    cin >> N;
    if (N > 2) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= i; j++)
            {
                cout << "*";
            }
            for (int k = 0; k < N - i; k++)
            {
                cout << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "The number has to be greater than 2!" << endl;
    }
    return 0;
}

