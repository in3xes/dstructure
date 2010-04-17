#include "main.h"

char * file::strng(char * filename) {
  //Declerations
  
  char * test;

  //Initializations
  fstream outfile(filename ,ios::in);
  outfile.seekg(0, ios::end);
  int length = outfile.tellg();
  outfile.seekg(0, ios::beg);

  test = new char[length];
  outfile.read(test, length);

	return test;
}

int file::length(char *filename) {
	
	fstream outfile(filename, ios::in);
	outfile.seekg(0, ios::end);
	int len = outfile.tellg();
	outfile.seekg(0, ios::beg);

	return len;
}

char * file::rmspace(char *str_ary, int length) {
	
	char * test = str_ary;
	char * newary;
	int newlen = 0;
	char prev = '\0';
	newary = new char[length];

  //Exctraction of string
  for(int i =0; i < length; i++) {
    if(test[i] == '\n') {
      cout << ' ';
      newary[newlen] = ' ';
      newlen++;
      prev = '\n';
      continue;
    }
    if(prev == ' ' || prev == '\n'){
      if(test[i] == ' ')
	continue;
    }

    newary[newlen] = test[i];
    newlen++;
    prev = test[i];
  }

	return newary;
}
