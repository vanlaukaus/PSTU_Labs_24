#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int num;
	float x,max=-1,n;
	double a;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		x=n+(i/n);
		a=sin(x);
		if (max < a){max = a; num=i;}
	}
	cout << max << endl << num << endl;

	return 0;
}