#include <iostream>
#include <string>

using namespace std;

struct node {
  string info;
  node *Rlink;
  node *Llink;
};

class dll {

 public:

  node *L;
  void insert(string item);
  void print();
  void del();
  dll() {
    L = NULL;
  }
};

void dll::insert(string item) {
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


int main()
{
  dll D;
  string test = "test1";
  D.insert(test);
  D.insert("test2");
  D.insert("test3");
	cout << "String elements in linked list\n";
  D.print();
	cout << "Deleting element from head\n";
  D.del();
  D.print();

  return 1;
}
