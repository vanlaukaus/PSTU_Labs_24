#include <iostream>
using namespace std;

int main()
{
    float a, b;
    cin >> a >> b;
    if (a > 0 && b > 0) 
    {
        cout << a / b << endl;
        return 0;
    }
    else if ((a == 0 || b == 0) && (a != 0 || b != 0)) 
    {
        cout << a / b << endl;
        return 0;
    }
    else 
    {
        cout << "You can't divide by zero!" << endl;
        return 0;
    }
}