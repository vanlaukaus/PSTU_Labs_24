#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	if (n % 2 == 0 || n <= 3)
	{
		cout << "Ошибка" << endl;
		return 0;
	}
	else
	{
		for (int i = 0; i <= n; i++)
		{
			if (i % 2 != 0)
			{
				for (int q = 1; q <= (n - i) / 2; q++)
				{
					cout << " ";
				}
				for (int j = 0; j < i; j++)
					cout << "*";
				cout << endl;
			}
		}
	}
	return 0;
}

