#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	if (n <= 2 ) { cout << "Erro! The number must be greater than 2" << endl; return 0; }
	else 
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n - i; j++) { cout << " "; }
			for (int j = 0; j <= i; j++) { cout << "*"; }
			cout << endl;
		}
	}
	return 0;
}
