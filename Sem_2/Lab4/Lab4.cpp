//Вариант 15

#include <iostream>
using namespace std;
int main() {
    //1
    int ring[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    int k;
    cout << "1.1" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << ring[i] << " ";
    }
    cout << endl;
    cout << "Enter k: ";
    cin >> k;
    //4
    cout << "4.4" << endl;
    for (int i = k; i < 10; i++)
    {
        cout << ring[i] << " ";
        if (i == 9)
        {
            for (int n = 0; ii <= k; n++)
            {
                cout << ring[n] << " ";
            }
        }
    }
    cout << endl;
    return 0;
}
