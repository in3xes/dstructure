#include <iostream>
#include <stdlib.h>
using namespace std;
#define MAX 6 

class queue {
	
	private:
		int Q[MAX];
		int Qfront;
		int Qrear;
		int Qcount;
	public:
		void insert(int item);
		void del();
		void display();
		queue() {
			Qfront = Qrear = -1;
			Qcount = 0;
		}
};

void queue::insert(int item) {
		if(Qcount == MAX ) {
			cout << "Queue filled\n";
		}
		else {
			Qcount++;
			cout << Qcount << endl;
			Qrear = (Qfront + Qcount)%MAX;
			Q[Qrear] = item;
		}
}

void queue::del() {
	if(Qcount != 0 ) {
			Qfront = (Qfront+1)%MAX;
			Qcount--;
	}
	else
		cout << "No element in Queue to delete\n";
}

void queue::display() {
	int tmp_count = 0;
	if(Qcount != 0 ) {
		for(int i = (Qfront+1)%MAX; ; i=(i+1)%MAX) {
			cout << i << "\t" << Q[i] << endl;
			tmp_count++;
			if(tmp_count%Qcount == 0)
				break;
		}
		cout << endl;
	}
	else
		cout << "No elements in Queue to display\n";
}

int main()
{
	queue Q;
	
	Q.del();
	for(int i=0; i < 6; i++) {
		Q.insert(100 + i);
	}
	Q.display();
	Q.del();
	Q.del();
	Q.del();
	for(int i=0; i < 6; i++) {
		Q.insert(100 + i);
	}
	Q.display();
	Q.del();
	Q.del();
	Q.del();
	Q.display();
//	Q.del();
//	Q.del();

//	Q.display();
	
	return 1;
}
