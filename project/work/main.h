#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#define MAX	1024

using namespace std;

char delimiter[] = { ' ', '\n', '\t' };
string operators[] = { "=", "*", "+", "-", "/", "++" };
string logicalop[] = { "==", "=<", "print", "=>", ">", "<" };
string keywords[] = { "if", "for", "whi", "const", "int", "char" };


int keywordnum = 6;
int delimnum = 3;
int oper = 6;
int logop = 6;

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

bool iskeyword(string word) {

	for(int i = 0; i < keywordnum; i++) {
		if(word == keywords[i])
			return true;
	}
	
	return false;
}

bool islogicalop(char *word) {
	
	for( int i = 0 ; i < logop; i++) {
		if(word == logicalop[i]) {
			return true;
		}
	return false;
	}
}

bool isoperator(char * word) {
	
	for(int i = 0 ; i < oper; i++) {
		if(word == operators[i])
			return true;
	}
	
	return false;
}

void words(char * content, int len) {
	
	vector<char>  buffer;
	int size = 0;
	string word = "";

	for(int i = 0; i < len; i++) {
		if(content[i] == ' ' ) {
			for( int j = 0; j < buffer.size(); j++) {
				word[j] = buffer[j];
			}
				if(iskeyword(word)) {
					cout << "\t is a keyword";
				}
		/*		if(isoperator(word)) {
					cout << "\t is a operator";
				}
				if(islogicalop(word)) {
					cout << "\t is logical operator";
				}
				buffer.erase(buffer.begin(), buffer.end());
				delete(word);
				size = 0; */
				
		//		buffer.clear();
		//		word = "";
				cout << endl;
			}
		else {
			buffer.push_back(content[i]);
		}

	}
}
