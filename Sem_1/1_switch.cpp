#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    cout << "Please enter two initial numbers and choose the operation to perform - 1 for addition, 2 for substraction, 3 for multiplication, 4 for division" << endl;
    int a, b, c, max;
    cin >> a >> b >> c;
    if (b == 0, c == 4)
    {
        cout << "You can't divide by zero!" << endl;
        return 0;
    }
    else
        switch (c)
        {
        case 1: max = a + b; break;
        case 2: max = a - b; break;
        case 3: max = a * b; break;
        case 4: max = a / b; break;
        default:
        {
            cout << "Please choose a defined option";
            return 0;
        }
        }
    cout << max << endl;
    return 0;
}