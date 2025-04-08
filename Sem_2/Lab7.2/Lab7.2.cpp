#include <iostream>
#include <cstdarg>
#include <cmath>

using namespace std;

int oct2dec(int oct) {
    int dec = 0, i = 0;
    while (oct != 0) {
        int digit = oct % 10;
        if (digit >= 8) {
            cerr << "Error: Number " << oct << " is not a valid octal number!" << endl;
            return -1;
        }
        dec += digit * pow(8, i);
        ++i;
        oct /= 10;
    }
    return dec;
}

void convertoct2dec(int count, ...) {
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; ++i) {
        int oct = va_arg(args, int);
        int dec = oct2dec(oct);
        if (dec != -1) {
            cout << "Octal: " << oct << " -> Decimal: " << dec << endl;
        }
    }

    va_end(args);
}

int main() {
    cout << "3 numbers:" << endl;
    convertoct2dec(3, 10, 20, 37);

    cout << "\n5 numbers:" << endl;
    convertoct2dec(5, 7, 15, 24, 32, 77);

    cout << "\n6 numbers:" << endl;
    convertoct2dec(6, 1, 12, 34, 56, 70, 100);

    return 0;
}