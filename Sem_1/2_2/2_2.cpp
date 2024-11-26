#include <iostream>
using namespace std;

int main ()
{
  int N, sum;
  cin >> N;
  int i = 1;
  sum = 1;
  while (i <= N)
    {
      sum *= i;
      i++;
    }
  cout << sum << endl;
  return 0;
}
