#include <iostream>
#include <stdlib.h>
using namespace std;

  struct node {
    int info;
    node *Rlink;
    node *Llink;
  };

class dll {

public:
  node *L;
  int length();


  dll() {
    L=NULL;
  }

  //Tutorial Functions
  void insert(int item); //Equls to AddToHead()
  void print(); //PrintForward()
  void print_backward(); //PrintBackward()
  void del_odd();
  void del_dup();
  void del(); //DeleteFromHead()

  void insert_tail(int item); // Equals to AddToTail()
  void del_from_tail(); // DeleteFromTail()
  void del_rand(int position); //DeleteNode()
  int count_recur(int count, node *N); // Recursive count
  int search(int item); //IsInList()
  void insert_rand(int item, int position); //Addnode()

};

void dll::insert(int item) {
  node *temp;
  temp = new node;
  temp->info = item;
  if(L==NULL) 
    L=temp;
  else {
    temp->Rlink =L;
    L->Llink = temp;
    L=temp;
  }
}

void dll::print() {
  node *temp;
  temp = new node;
  temp = L;
  while(temp) {
    cout << temp->info << endl;
    temp = temp->Rlink;
  }
  cout << endl;
}

void dll::print_backward() {
  node *temp;
  temp = new node;
  temp = L;

  int lengt = length();
  int aray[lengt];
  int index = 0;
  while(temp) {
    aray[index] = temp->info;
    temp = temp->Rlink;
    index++;
  }
  for(int i = 0; i < lengt; i++) {
    cout << aray[lengt - i - 1] << endl;
  }
}

int dll::length() {
  node *temp;
  temp = L;
  int len = 0;
  while(temp) {
    temp = temp->Rlink;
    len++;
  }
  return len;
}


int dll::search(int item) {
  node *temp;
  temp = L;
  int pos = -1;
  while(temp) {
    temp = temp->Rlink;
    pos++;
    if(temp->info == item)
      break;
  }
  return pos;
}

void dll::del() {
  node *temp;
  temp = L;
  if(temp != NULL) {
    L = L->Rlink;
    L->Llink = NULL;
    delete(temp);
  }
  else
    cout << "LIST IS EMPTY\n";
}

void dll::insert_rand(int item, int position) {
  int cur_pos = 1;
  node *temp, *temp1;
  temp = new node;
  temp1 = new node;
  temp1->info = item;
  temp = L;
  if(position == 1) 
    insert(item);
  else {
    while(cur_pos != position-1) {
      temp = temp->Rlink;
      cur_pos++;
    }
    temp1->Rlink = temp->Rlink;
    temp->Rlink = temp1;
    temp1->Llink = temp;
    //temp->Rlink->Llink = temp1;
  }
}

void dll::del_rand(int position) {
  int cur_pos = 1;
  node *temp, *temp1;
  temp = new node;
  temp1 = new node;
  temp1 = L;
  temp = temp1->Rlink;
  if(position == 1) {
    del();
  }
  else {
    while(cur_pos < position-1) {
      temp1 = temp1->Rlink;
      temp = temp1->Rlink;
      cur_pos++;
    }

    temp1->Rlink = temp->Rlink;
    temp->Rlink->Llink = temp1;
    delete(temp);
  }
}

void dll::del_odd() {
  int len = length();
  for(int i = 0; i < len; i++) {
    if(i%2 == 1) {
      del_rand(len - i);
    }
  }
}

void dll::del_dup(){

  node *temp;
  temp = new node;
  temp = L;
  node *tmp;
  int index = 1;
  tmp = new node;
  while(temp){
    int i = 0;
    tmp = temp->Rlink;
    while(tmp) {
      i++;
      //    cout << tmp->info << "\t" << temp->info << endl;
      if(tmp->info == temp->info) {
	del_rand(i+index);
      }
      tmp = tmp->Rlink;
    }
    index++;
    temp = temp->Rlink;
  }
}
int dll::count_recur(int count, node *N) {
  if(N == NULL)
    return count++;
  else
       return count_recur(count, N->Rlink)+1;
}

void print_menu() {

	cout <<	"Press 'a' to add to head\t\n";
	cout << "press 'f' to print forward\t\n";
	cout << "Press 'b' to print backward\t\n";
	cout << "Press 'o' to delete nodes at odd positions\t\n";
	cout << "Press 'd' to dleete duplicate nodes\t\n";
	cout << "Press 'n' to delete a node\t\n";
	cout << "Press 'c' to count number of nodes\t\n";
	cout << "Press 's' to check weather an element is in list or not\t\n";
	cout << "Press 'i' to insert element at specific node\t\n";
	cout << endl;
}

void small_menu() {
	cout << "Press 'm' for menu \t\n";
	cout << "Press 'q' to quit \t\n";
}

int main() 
{
  dll D;

	char input = '\0';
  for(int i = 0; i < 10; i++) {
    cout << "Inserting " << (100 +(i*i)) << endl;
    D.insert(100 + (i*i));
  }
	
	cout << "\nElements in list are :\n";
	D.print();

	while(true) {
		small_menu();
		cin >> input;
		switch(input) {
			case 'm':
				print_menu();
				break;
			case 'a':
				cout << "Enter an element to add to head :\t";
				int elem;
				cin >> elem;
				D.insert(elem);
				break;
			case 'f':
				cout << endl;
				D.print();
				break;
			case 'b':
				cout << endl;
				D.print_backward();
				break;
			case 'o':
				D.del_odd();
				break;
			case 'd':
				D.del_dup();
				break;
			case 'n':
				cout << "Enter the position of node you want to dele :\t";
				int pos;
				cin >> pos;
				D.del_rand(pos);
				break;
			case 'c':
				cout << "Number of elements in list is :\t";
				int count; 
				count = D.count_recur(count, D.L);
				cout << count << endl;
				break;
			case 's':
				cout << "Enter the elements to  search\n";
				int el;
				cin >> el;
				if(D.search(el) != -1){
					cout << "Position of elements is :\t";
					cout << D.search(el);
				}
				else
					cout << "Element not present\n";
				
				break;
			case 'i':
				cout << "Enter an element to insert :\t";
				int element;
				cin >> element;
				cout << "Enter position where you want to insert :\t";
				int position;
				cin >> position;
				D.insert_rand(element, position);
				break;
			case 'q':
				exit(0);
		}
	}
}
