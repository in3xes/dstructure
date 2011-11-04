#include <iostream>
using namespace std;

class ll {
  struct node {
    int info;
    node *next;
  };
  
private:
  node *list;
public:
  int insert(int val);
  int del();
};


int ll::insert(int val) {
  node *p;
  p = new node;
  p->info = val;
  if(L == NULL)
    L=p;
  else {
    p->next = L;
    L=p;
  }
}

int main () {
  return 0;
}
