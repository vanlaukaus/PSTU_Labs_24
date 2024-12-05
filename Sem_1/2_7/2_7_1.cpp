#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout << "Any natural number with an integer square root: ";
	int n, k;
	cin >> n;
	k = sqrt(n);
	for (int i = 0; i < k; i ++)
	{
		for (int j = 0; j < k; j++) cout << "* ";
		cout << endl;
	}
	return 0;
}