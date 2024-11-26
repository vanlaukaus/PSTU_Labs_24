#include <iostream>
using namespace std;

int main ()
{
  int N, sum;
  cin >> N;
  int i = 0;
  sum = 0;
  while (i <= N)
    {
      sum += i;
      i++;
    }
  cout << sum << endl;
  return 0;
}
