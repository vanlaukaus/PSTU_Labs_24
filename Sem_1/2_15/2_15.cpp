#include <iostream>
using namespace std;

int main() {
    int n;
    int s;
    cout << "Enter a natural number: ";
    cin >> n;
    cout << "Enter the digit to search for: ";
    cin >> s;
    bool f = false;

    for (int i = 0; i < 5; i++) {
        if (n == s) {
            f = true;
            break;
        }
    }

    if (f) {
        cout << "Digit " << s << " belongs to N" << endl;
    } else {
        cout << "Digit " << s << " does not belong to N" << endl;
    }
    return 0;
}
