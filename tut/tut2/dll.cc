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

int main() 
{
  dll D;

  for(int i = 0; i < 10; i++) {
    D.insert(100 + (i*i));
  }

  // D.print();
  // D.del();
  // D.print();
  // D.insert_rand(45, 4);
  // D.print();
  // D.del_odd();
  // D.print();
  // D.insert(125);

//   D.insert(125);
//   D.insert(104);
//   D.insert(109);
//   D.print();
//   D.del_dup();
   D.print();
   D.print_backward();

}
