#include <iostream>
using namespace std;
int main()
{
	int n,k,max,min;
	int *ptrk = &k;
	cin >> n;
	cin >> *ptrk;
	max = *ptrk;
	min = *ptrk;
	for (int i=1; i<n; i++)
	{
		cin >> *ptrk;
		if (*ptrk > max){max = *ptrk;}
		else if(*ptrk<min){min = *ptrk;}
	}
	
	cout << max << endl << min << endl;

	return 0;
}