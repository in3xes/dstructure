#include <iostream>
using namespace std;
void hanoi(int n,int from,int to,int use) { 
if(n>0) {
	hanoi(n-1,from,use,to);
	cout<<"Move from "<<from<<" to "<<to<<endl;
	hanoi(n-1, use,to,from);
	}
}

int main() { 
	int n=0;
	cout<<"Enter the number of disks\t";
	cin>>n;
	hanoi(n,1,2,3);

	return 1;
}
