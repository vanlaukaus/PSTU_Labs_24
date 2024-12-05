#include <iostream>
using namespace std;
int main()
{
	int a=5,b=100,k;
	int *ptr_a=&a;
	int *ptr_b=&b;	
	k = *ptr_a;
	*ptr_a = *ptr_b;
	*ptr_b = k;
	cout << a <<" "<<b << endl;
	return 0;
}