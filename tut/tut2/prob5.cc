#include <iostream>
using namespace std;

struct node {
  int info;
  node *Rlink;
  node *Llink;
};

class dll {

public:
  node *L;
  void sol(dll B);
  bool ifprime(int i);
  int length();
  void insert_rand(int item, int position);
  void insert(int item);
  void print();

  dll () {
    L = NULL;
  }
};


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

bool dll::ifprime(int i) {
  for(int k = 2; k < i; k++) {
    if(i%k == 0)
      return false;
    else
      continue;
  }
  return true;
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

void dll::sol(dll B) {

  int lenB = B.length();
  int lenA = length();
  node *temp;
  temp = new node;
  insert_rand(B.L->info, 2);
  temp = B.L->Rlink;
  int num = 3;
  for(int i = 0; i < lenB; i++) {
      while(!ifprime(num) && (lenA >= num)) {
	num++;
      }
      num++;
      if(lenA >= num) {
	insert_rand(temp->info, num-1);
	temp = temp->Rlink;
	lenA++;
//	cout << lenA << "\t" << num-1 << endl;
      }
      else
	break;
    }
}

int main() {

  dll A, B;

  B.insert(6666);
  B.insert(5555);
  B.insert(4444);
  B.insert(3333);
  B.insert(2222);
  B.insert(1111);
	
	cout << "Elements in double linked list B\n";
	B.print();
  for(int j = 0; j < 10; j++)
  {
    A.insert(10-j);
  }
	cout << "Elements in double linked list A before insertion\n";
  A.print();
	cout << endl;
  A.sol(B);
	cout << endl;
	cout << "Elements in double linked list after insertion\n";
  A.print();
}
