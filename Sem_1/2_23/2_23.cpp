#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int num=0;
	float x,max=-1,n;
	double a;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		x=n+(i/n);
		a=sin(x);
		if (max < a){max = a;}
	}
	for (int i = 1; i <= n; i++)
	{
		x=n+(i/n);
		a=sin(x);
		if (a == max) {num++;}
	}
    num--;
	cout << num << endl;
	return 0;
}