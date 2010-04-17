#include <iostream>
using namespace std;

int main()
{
	struct node {
		char a[3];
		char b[5];
		char c[9];
		char d[1];
	};
	node test;
	cout  << &test.a << endl;
	cout  << &test.b << endl;
	cout  << &test.c << endl;
	cout  << &test.d << endl;

	int asdf[3][4][5][6];
	return 1;
}
