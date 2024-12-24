#include <iostream>
using namespace std;
int main()
{
	int n,srv,k=0,k1=0;
	bool flag = false;	

	cin >> n;
	if (n==0) return 0;
	else {k++;k1++;}
	srv=n;
	while(!flag)
	{
		cin >> n;
		k++;
		if (n==0) {k--;flag = true;}
		else
		{
			if (srv < n) {k1++;}
		}
	}
	if (k==k1) cout << "The numbers are sorted correctly" << endl;

	return 0;
}