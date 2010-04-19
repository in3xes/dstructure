#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#define MAX	1024

using namespace std;

char delimiter[] = { ' ', '\n', '\t', '(', ')', '{', '}', ';' };
string operators[] = { "=", "*", "+", "-", "/"};
string logicalop[] = { "==", "=<", "=>", ">", "<" };
string keywords[] = { "if", "for", "while", "const", "int", "char", "print" };

int keywordlen[] = {2, 3, 5, 5, 3, 4, 5};
int logicaloplen[] = {2, 2, 3, 1, 1};

int keywordnum = 7;
int delimnum = 8;
int oper = 5;
int logop = 5;

bool isdelim(char ch) {
	for( int i = 0; i < delimnum; i++) {
		if(ch == delimiter[i]) 
			return true;
	}
	
	return false;
}

class file {

public:
char * filename;
char * strng();
char * rmspace(char * str_ary, int length);
int length();
int len(char *str_ary, int length);

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
	
	for(int i = 0; i < length; i++) {	
		if(isdelim(test[i])) {
			if(newary[newlen - 1] == ' ') 
				continue;
			else{
				newary[newlen] = ' ';
				newlen++;
			}
		}
		else {
			newary[newlen]  = test[i];
			newlen++;
		}
	}

	char * ans = newary;
	
	return ans;
}

int file::len(char *str_ary, int length) {
	
	char * test = str_ary;
	char * newary;
	int newlen = 0;
	char prev = '\0';
	newary = new char[length];
	
	for(int i = 0; i < length; i++) {	
		if(isdelim(test[i])) {
			if(newary[newlen - 1] == ' ') 
				continue;
			else{
				newary[newlen] = ' ';
				newlen++;
			}
		}
		else {
			newary[newlen]  = test[i];
			newlen++;
		}
	}
	
	return newlen;
}

void print(char * content, int len)
	{
	for( int i = 0; i < len; i++)
		cout << content[i];

	cout << endl;
	}

bool iskeyword(char * word, int size) {

	int res = 0;
	for(int i = 0; i < keywordnum; i++) {
//		cout << size << "\t" << keywordlen[i] << endl;
		if(size == keywordlen[i]) {
			string kword = keywords[i];
			int test = 0;
			for(int j = 0 ; j < size; j++) {
				if(word[j] == kword[j])
				{
//				cout << test << "\t";
					test++;
				if(test == size)
					return true;
				}
				else
					break;
			}
		}
	}

	return false;

}

bool islogicalop(char *word, int size) {
	
	int res = 0;
	for( int i = 0 ; i < logop; i++) {
	//	cout << size << "\t" << keywordlen[i] << endl;
		if(size == logicaloplen[i]) {
			string lword = logicalop[i];
			int test = 0;
			for( int j = 0 ; j < size; j++) {
				if(word[j] == lword[j])
				{
	//			cout << "came here\t";
	//			cout << test << endl;
					test++;
				if(test == size) 
					return true;
				}
				else
					break;
			}
		}
	}

		return false;
	}

bool isoperator(char * word, int size) {
	
	int res = 0;	
	for(int i = 0 ; i < oper; i++) {
		if(size == 1) {
			string oword = operators[i];
			int test = 0;
			for( int j = 0; j < size; j++) {
				if(word[j] == oword[j]) {
					test++;
					if(test == size)
						return true;
					}
				else
					break;
			}
		}
	}
}

void words(char * content, int len) {
	
	vector<char>  buffer;
	int size = 0;
	char * word; 

	for(int i = 0; i < len; i++) {
		if(content[i] == ' ' ) {
			size = buffer.size();
			word = new char[size];
			for( int j = 0; j < buffer.size(); j++) {
				word[j] = buffer[j];
				cout << word[j];
			}
//				cout << word << "\t" << size; 
				if(iskeyword(word, size)) {
					cout << "\t is a keyword";
				}
				else if(islogicalop(word, size)) {
					cout << "\t is logical operator";
				}
				else if(isoperator(word , size)) {
					cout << "\t is an operator";
				}
				else
					cout << "\t is an identifier";


				cout << endl;
				buffer.clear();
			}
		else {
			buffer.push_back(content[i]);
		}

	}
	
}
