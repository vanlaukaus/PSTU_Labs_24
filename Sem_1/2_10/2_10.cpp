#include <iostream>
using namespace std;
int main()
{
	int n, t, max;
	cin >> n;

	cin >> max;
	for (int i=0; i<n-1; i++)
	{
		cin >> t;
		if (t > max) {max = t;}
	}
	cout << max << endl;	

	return 0;
}