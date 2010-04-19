#include "main.h"

int main(int argc, char * argv[]) {

//	file F("notes");
	file F(argv[1]);
	char * file_content = F.strng();
	int l = F.length();
	cout << "Length:\t" << l << endl;
	int *fl;
	char * fc_remoed = F.rmspace(file_content, l, fl);
	
	char * word = "if";

	print(fc_remoed, *fl);

	return 1;
}
