#include <iostream>
#include <stdlib.h>
using namespace std;
#define MAX 4 

class queue {
	
	private:
		int Q[MAX];
		int Qfront;
		int Qrear;
	public:
		void insert(int item);
		void del();
		void display();
		queue() {
			Qfront = Qrear = -1;
		}
};

void queue::insert(int item) {
		if(Qrear == MAX -1) {
			cout << "Queue filled\n";
		}
		else {
			Qrear++;
			Q[Qrear] = item;
		}
}

void queue::del() {
	if(Qrear != -1 && Qfront != Qrear) {
		if(Qfront < Qrear)
			Qfront++;
		else
			cout << "No elements in Queue\n";
	}
	else
		cout << "No element in Queue\n";
}

void queue::display() {
	if(Qrear != -1 && Qfront != Qrear) {
		for(int i = Qfront+1; i <=Qrear; i++) {
			cout << Q[i] << endl;
		}
	}
	else
		cout << "No elements in Queue";
}

int main()
{
	queue Q;
	
	Q.del();
	for(int i=0; i < 5; i++) {
		Q.insert(i);
	}
	Q.display();
	Q.del();
	Q.display();
	
	return 1;
}
