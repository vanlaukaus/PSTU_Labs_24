#include <iostream>
using namespace std; 
int main () {
    int n, sum, tmp;
    cout << "Enter a natural number: ";
    cin >> n;
    sum = 0;
    tmp = n;
    while (tmp > 0){
        sum += tmp %10;
        tmp /= 10;
    }
    cout << "Sum: " << sum << endl;
    return 0;
}

