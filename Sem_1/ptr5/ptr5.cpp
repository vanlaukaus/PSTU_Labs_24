#include <iostream>
using namespace std;
int main()
{
	int n,k;
	cin >> n;
	k=n;
	int *ptrk = &k;

	for (int i=n-1; i>1; i--){*ptrk *= i;}
	
	cout << *ptrk << endl;

	return 0;
}