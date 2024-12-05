#include <iostream>
using namespace std;
int main()
{
	int a,b,n;
	cin >> a >> b;
	int *ptr_a=&a;
	int *ptr_b=&b;
	n = *ptr_a + *ptr_b;
	cout << n << endl;
	return 0;
}