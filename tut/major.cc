#include <iostream>
using namespace std;

int main() {
	int a[3][3];
	for(int i =0; i<9; i++)
	{
		cout << &a[i/3][i%3] << "\t";
		if(i%3 == 0)
			cout << endl;

	}
	return 0;
}
