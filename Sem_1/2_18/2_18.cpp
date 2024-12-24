#include <iostream>
using namespace std;
int main()
{
	int n,n1,n_itog=0;
	float k=0.1;
	cin >> n;
	n1=n;
	while (n1 > 0)
	{
		n1 = n1/10;
		k*=10; 
	}
	while (n>0)
	{
		n_itog += (n%10)*k; 
		k/=10;
		n=n/10;
	}
	cout << n_itog << endl;
		
	return 0;
}