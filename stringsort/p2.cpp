#include <iostream>
#include <string.h>
using namespace std;
#define MAX 100
class strng {

public:
	
  int length;
  string strngs[MAX];
  string result[MAX];
  char *strng_tmp;

  bool operator>(char *str);
  void insert();
  void insert_pos(int position, int cur_len, string item);
  void insert_sort();
  void print();

  strng(char *a) {
    strng_tmp = a;
  }
};

bool strng::operator>(char *str) {

  if((int) strng_tmp[0] > (int )str[0])
    return true;
  else if((int ) strng_tmp[0] < (int )str[0])
    return false;
  else
    return true;
}

void strng::insert_pos(int position, int cur_len, string item) {
  for(int i = cur_len; i >= position; i--) {
    strngs[i+1] = strngs[i];
  }
	
  strngs[position] = item;
}

void strng::insert()	{
	
  string input;
	
  for(int i = 0; i < MAX; i++){
    cin >> input;
    if(input != "-1"){
      cout << "Enter -1 to stop\n";
      strngs[i] = input;
    }
    else {
      length = i+1;
      break;
    }
  }
}

void strng::insert_sort() {

  result[0] = strngs[0];

  for(int i =0; i < length; i ++) {
  }
}

void strng::print() {

  for(int i = 0; i < length; i ++) {
    cout << strngs[i] << endl;
  }
}


int main()
{
  strng a("kadfdf");
		
  a.insert();
  cout << a.length << endl;
  a.print();
  a.insert_pos(2, a.length, "tesing");
	
  a.result[0] = a.strngs[0];
  for(int i = 0; i < a.length; i ++){
    a.result[i]

      return 1;
  }

