#include <iostream>
using namespace std;

class ll {
	struct node {
		int info;
		node *next;
	};
	private:
		node *L;

	public:
		void insert(int item);
		void print();
		void del();
		void insert_rand(int item, int position);
		int search(int  item);
		void del_rand(int position);
		ll() {
			L=NULL;
		}
};

void ll::insert(int item) {
	node *p;
	p = new node;
	p->info = item;
	if(L==NULL)
		L=p;
	else {
		p->next = L;
		L=p;
	}
}
void ll::print() {
	node *temp;
	temp = new node;
	temp = L;
	while(temp) {
		cout << temp->info << endl;
		temp = temp->next;
	}
	cout << endl;
}
void ll::del() {
	node *temp;
	temp = new node;
	temp =L;
	L=L->next;
	delete(temp);
}
int ll::search(int item) {
	node *temp;
	temp = new node;
	temp =L;
	int present ;
	while(temp) {
		present = (temp->info == item) ? 1:0 ;
		if (present )
			break;
		temp = temp->next;
	}
	return present;
}

void ll::insert_rand(int item, int position) {
	int cur_pos = 1;
	node *temp;
	node *temp1;
	temp1 = new node;
	temp1->info = item;
	temp = L;
	if(position == 1) {
		temp1->next= L;
		L=temp1;
	}
	else {
		while(cur_pos != position-1) {
			temp = temp->next;
			cur_pos++;
		}
		temp1->next = temp->next;
		temp->next = temp1;
	}
}
void ll::del_rand(int position) {
	int cur_pos = 1;
	node *temp;
	node *temp_del;
	temp = L;
	if(position == 1) {
		L=temp->next;
		delete(temp);
	}
	else {
		while(cur_pos != position -1) {
			temp  = temp->next;
			cur_pos++;
		}
		temp_del = temp->next;
		temp->next = temp_del->next;
		delete(temp_del);
	}
}
int main()
{	
	ll llist;
	llist.insert(22);
	llist.insert(5);
	llist.insert(66);
	llist.insert(6);
	llist.insert(866);
	llist.insert(466);
	llist.insert(646);

	llist.print();
	llist.del();
	llist.print();
	llist.insert_rand(100, 1);
	llist.print();
	llist.del_rand(4);
	llist.print();
	return 1;
}
