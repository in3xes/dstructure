#include <iostream>
#include <string>
#include <fstream>

#define MAX	1024

using namespace std;

class file {

public:
char * filename;
char * strng();
char * rmspace(char * str_ary, int length);
int length();

	file(char * fname) {
	filename = fname;
	}
};

char * file::strng() {
  //Declerations
  
  char * test;

  fstream outfile(filename ,ios::in);
  outfile.seekg(0, ios::end);
  int len = outfile.tellg();
  outfile.seekg(0, ios::beg);

  test = new char[len];
  outfile.read(test, len-1);

	return test;	
//	string for_return = test;
//	return for_return;
}

int file::length() {
	
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
