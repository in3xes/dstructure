#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>
#define MAX	1024

using namespace std;

char delimiter[] = { ' ', '\n', '\t', '(', ')', '{', '}', ';' };
string operators[] = { "=", "*", "+", "-", "/"};
string logicalop[] = { "==", "=<", "=>", ">", "<" };
string keywords[] = { "if", "for", "while", "const", "int", "char", "print", "main" };

int keywordlen[] = {2, 3, 5, 5, 3, 4, 5, 4};
int logicaloplen[] = {2, 2, 3, 1, 1};

int keywordnum = 8;
int delimnum = 8;
int oper = 5;
int logop = 5;

struct node {

	int type;
	char * value;
	int ssize;
	int id;
	node * next;
};

class llist {

	public:
	node * L;
	int length;
	
	void insert(char * word, int size, int type, int id);
	int search(char * word, int size, int type);
	int len();
	void prin();

	llist() {
		L = NULL;
		length = 0;
	}
};

void llist::insert(char * word, int size, int type, int id) {

	node * p;
	p = new node;
	for(int i = 0; i < size; i++) {
		p->value[i] == word[i];
	}
	p->value = word;
	p->ssize = size;
	p->type = type;
	p->id = id;
	length++;
	if( L == NULL)
		L=p;
	else {
		p->next = L;
		L = p;
	}
//	prin();
}

int llist::search(char * word, int size, int type) {
	node * temp;
	temp = new node;
	temp =L;

	int pos = 1;

	while(temp) {
		if(temp->type == type) {
			if(temp->ssize == size) {
				int test = 0;
				for(int i = 0 ; i < size; i++) {
					if(temp->value[i] == word[i]) {
						test++;
						if(test == size) {
							return temp->id;
						}
					}
					else
						break;
				}
			}
		}
		temp = temp->next;
		pos++;
	}

	return -1;
}

void llist::prin() {

	node * temp;
	temp = new node;
	temp = L;
	
	while(temp) {
		cout << temp->value << "\t" << temp->ssize << "\t" << temp->type << "\t" << temp->id << endl;
		
		temp = temp->next;
	}
}
int llist::len() {

	node * temp;
	temp = new node;
	temp =L;

	int len = 0;	
	while(temp) {
		
		len++;
		temp = temp->next;
	}

	return len;
}

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

int iskeyword(char * word, int size) {

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
					return i;
				}
				else
					break;
			}
		}
	}

	return -1;
}

int islogicalop(char *word, int size) {
	
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
					return i;
				}
				else
					break;
			}
		}
	}

		return -1;
}

int isoperator(char * word, int size) {
	
	int res = 0;	
	for(int i = 0 ; i < oper; i++) {
		if(size == 1) {
			string oword = operators[i];
			int test = 0;
			for( int j = 0; j < size; j++) {
				if(word[j] == oword[j]) {
					test++;
					if(test == size)
						return i;
					}
				else
					break;
			}
		}
	}

	return -1;
}

int isnumber(char * word, int size) {
	
	if(word[0] == '0' && size == 1)
		return 0;

	int a = atoi(word);
	
	if(a > 0) {
		return a;
	}
	
	return -1;

}

llist iden;

	
void words(char * content, int len) {
	
	vector<char>  buffer;
	int size = 0;
	char * word; 

	for(int i = 0; i < len; i++) {
		if(content[i] == ' ' ) {
			cout << "< ";
			size = buffer.size();
			word = new char[size];
			for( int j = 0; j < buffer.size(); j++) {
				word[j] = buffer[j];
				cout << word[j]; 
			}
				cout << " " ;
//				cout << word << "\t" << size; 
				if(iskeyword(word, size) != -1) {
					cout << "kw." << iskeyword(word, size);
				}
				else if(islogicalop(word, size) != -1) {
					cout << "lo." << islogicalop(word, size);
				}
				else if(isoperator(word , size) != -1) {
					cout << "op." << isoperator(word, size);
				}
				else if(isnumber(word, size) != -1) {
					cout << "const." << isnumber(word, size);
				}
				else {
					if(iden.search(word, size, 1) == -1) {
						iden.insert(word, size, 1, iden.length + 1);
						cout << "iden." << iden.length;
					}
					else {
						cout << "iden." << iden.search(word, size, 1);
					}
				}
					cout << " >";
					cout << endl;
					buffer.clear();
				
			}
		else {
			buffer.push_back(content[i]);
		}

	}
	
}

