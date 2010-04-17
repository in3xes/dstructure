#include <iostream>
using namespace std;
#define MAX	1023

void print_array(int a[], int n) {
	for(int i=0; i<n; i++) {
		cout << a[i] << endl;
	}
}

int enter_elements(int a[]) {
	int n = 0;
	cout<<"Enter the number of elemets\t";
	cin  >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	return n;
}

int remove_duplicate(int a[], int n) {
	int s = n;
	for(int i = 0; i < s; i++) {
		for(int j = i+1; j< s; j++) {
			if(a[i] == a[j]) {
				for(int k = j; k < s-1; k++) {
					a[k] = a[k+1];
				}
			s--;
			j--;
			}
		}
	}
	return s;
}
int main()
{
	int size = 0;
	int Array[MAX] = {0};
	size = enter_elements(Array);
	size = remove_duplicate(Array, size);
	print_array(Array, size);
}
