#include <iostream>
#include <string>
#include <fstream>

#define MAX	1024

using namespace std;

class file {

public:
char * filename;
char * strng();
char * rmspace(char * str_ary, int length, int *fl);
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

char * file::rmspace(char *str_ary, int length, int *fl) {
	
	char * test = str_ary;
	char * newary;
	int newlen = 0;
	char prev = '\0';
	newary = new char[length];

  //Exctraction of string
  for(int i =0; i < length; i++) {
    if(test[i] == '\n' || test[i] == '\t') {
      newary[newlen] = ' ';
      newlen++;
      prev = ' ';
      continue;
    }
    if(prev == ' '){
      if(test[i] == ' ')
	continue;
    }

    newary[newlen] = test[i];
    newlen++;
    prev = test[i];
  }
	
	fl = &newlen;
	return newary;
}

string keywords[] = { "if", "for", "while", "int", "char" };
int keywordnum = 5;

bool iskeyword(char * word) {
	
	if(keywords[0] == word){
		cout << "yes\n";
		return true;
	}
	else {
		cout << "no\n";
		return false;
	}
}

void print(char * content, int len)
	{
	for( int i = 0; i < len; i++)
		cout << content[i];
	}
	
void words(char * content, int len) {
	
	char * buffer;
	cout << len << endl;
	for(int i = 0; i < len; i++) {
		if(content[i] == ' ' )
			cout << endl;
		else
			cout << content[i];
	}
}
		
