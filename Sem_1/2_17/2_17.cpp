#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n,k=0;
	double x,c,y=0;
	cin >> n >> x;
	
	for(int i=0;i<n;i++)
	{
		c = pow(x,i);
		k *= i;
		if (k==0){k++;}
		y += c/k;
	}
	cout << y << endl;

	return 0;
}