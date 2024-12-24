#include <iostream>
using namespace std;
int main () {
    int N, S = 0, j = -1;
    cout << "How many numbers should there be: ";
    cin >> N;
    for (int i = 1; i <= N; ++i) 
    {
        S += j * i;
        j *= -1;
    }
    cout << "Sum: " << S << endl;
    return 0;
}
