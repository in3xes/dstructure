#include "main.h"

int main(int argc, char * argv[]) {

//	file F("notes");
	file F(argv[1]);
	char * file_content = F.strng();
	int l = F.length();
	char * fc_removed = F.rmspace(file_content, l);
	int rl = F.len(file_content, l);
	
	words(fc_removed, l);
//	char * test = ">";
//	islogicalop(test, 1);

//	char * a ;
//	a = new char[2];
//	a[0] = '(';
//	a[1] = '8';
	
//	isnumber(a);
//	iden.prin();

//	cout << endl;

	stable.prin();
//	stable.prints();
	return 1;

}
