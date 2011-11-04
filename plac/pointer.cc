#include <iostream>
using namespace std;

int main () {
  int a = 42;
  int *b = &a;
  cout << b << " " << *b << endl;

  b = 0; // There's no NULL in C++, it uses 0
  // cout << b << " " << *b << endl; //this will segfault
  
  int* c;
  // *c = 22 // This will segfault
  return 0;
}

