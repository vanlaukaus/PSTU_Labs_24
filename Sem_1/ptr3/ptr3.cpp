#include <iostream>
using namespace std;
int main()
{
	float a,b,n;
	cin >> a >> b;
	float *ptr_a=&a;
	float *ptr_b=&b;
	n = *ptr_a + *ptr_b;
	cout << n << endl;
	return 0;
}