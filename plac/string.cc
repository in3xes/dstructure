#include <iostream>
#include <cstdio>

using namespace std;

void revword(char *str, int len) {
  char *start = str;
  char *end = str + len -1;
  char tmp = 0;
  while (start < end) {
    tmp = *start;
    *start++ = *end;
    *end-- = tmp;
  }
}

int length(char *str) {
  int count  = 0;
  while(*str) {
    count++;
    str++;
  }

  return count;
}

void rev(char *str) {
  int count = 0;
  while(*str) {
    count++;
    if (*str == ' ' || *str == 0) {
      revword(str-count+1, count-1);
      count = 0;
    }
    str++;
  }
  revword(str-count, count);
}    


char* RemoveSpaces( char *str )
{
  if ( NULL == str ) return NULL;
  char *to = str;
  for ( char* from = str ; *from != '\0' ; from++ ) {
    printf("%s\n", str);
    if (*from != ' ')
      *(to++) = *from;
  }
  *to = '\0';
  return str;
}

int main() {
      char str[] = "this is a big bigger biggest string";
      int len = length(str);
      printf("%d\n", len);
      revword(str, 35);
      printf("%s\n", str);
      rev(str);
      printf("%s\n", str);
      char *st = new char;
      st = RemoveSpaces(str);
      printf("%s\n", st);      
      return 0;
}
