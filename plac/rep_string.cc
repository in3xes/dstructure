#include <iostream>
#include <string.h>
#include <cstdio>

using namespace std;

int main() {
  char str[] = "this string is a non repeating";
  int len = strlen(str);
  int index[26] = {0};
  int count = 0;
  while(*(str+count)) {
    if (*(str+count) != ' ') {
      index[int(*(str+count)) - 97]++;
      }
	count++;
  }

  count = 0;
  while(*(str+count)) {
    if (*(str+count) != ' ') {
      if (index[int(*(str+count)) - 97] == 1){
	printf("%c\n", *(str+count));
	break;
      }
      }
	count++;
  }


  return 0;
}
