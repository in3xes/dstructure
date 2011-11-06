#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

int main()
{
  int val;
  cin >> val;
  bitset <8> bs = val;

  // for(int a = 0; a< 126; a++) {
  //   cout << a << " " << (char ) a << " ";
  // }

  cout << bs.count() << endl;
  return 0;
}
