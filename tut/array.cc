#include <iostream>
using namespace std;

int main()
{
	int a[15];
	for(int i =0; i<=19; i++) {
		a[i] = i+1;
	}
	for(int j=0; j<=19; j++) {
		cout << &a[j] << endl;
	}
//	cout << a[11] << endl;
	return 1;
}
