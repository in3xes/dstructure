#include <iostream>
using namespace std;

int rabit(int n) {
	if(n == 0) {return 1;}
	else if(n == 1) {return 2;}
	else { return (2*rabit(n-1) -2*rabit(n-2));}
}
	
int main() 
{

	int a = 33;
	for(int i = 0; i < 30; i++) {
	cout << rabit(i) << endl;
	}

	return 1;
}

