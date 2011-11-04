#include <iostream>
using namespace std;

int main() {
  char str[] = "this string is a non repeating";
  int index[26] = {0};
  int count = 0;
  while(*(str+count)) {
    if (*(str+count) != ' ') {
      // cout << int(*(str+count)) << " " << *(str+count) << "  ";
      index[int(*(str+count)) - 97]++;
      }
	count++;
  }
  // for(int x = 0; x < 26; x++) {
  //   cout << index[x] << " ";
  // }
  // cout << endl;

  count = 0;
  while(*(str+count)) {
    if (*(str+count) != ' ') {
      if (index[int(*(str+count)) - 97] == 1){
	cout << *(str+count) << endl;
	break;
      }
      }
	count++;
  }


  return 0;
}
