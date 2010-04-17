#include <iostream>
#include <string>
#include <fstream>

#define MAX	1024

using namespace std;

class file {

public:
char * filename;
char * strng(char * filename);
char * rmspace(char * str_ary, int length);
int length(char * filename);

	file(string fname) {
	filename = fname;
	}
};
