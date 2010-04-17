#include <iostream>
using namespace std;
#define MAX	5


float* mirror(float *p[], int n) {
	float Final[n];
	for(int i = 0; i < n; i++) {
		Final[i] = *p[n-i-1];
	}

	for(int i = 0; i < n; i++) {
		cout << Final[i] << endl;
	}
	return Final;
}

int main()
{
	int n;
	cout << "Enter the number of elements in array\t";
	cin >> n;
	float Array[n];
	float *Point[n];

	for(int i = 0; i < n; i++) {
		cout << "Enter element " << i+1 << "\t";
		cin >> Array[i]; 
		Point[i] = &Array[i];
	}

	mirror(Point, n);

	return 1;
}
