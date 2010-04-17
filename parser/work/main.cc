#include "main.h"

int main(int argc, char * argv[]) {
//int main() {

//	file F("notes");
	file F(argv[1]);
	char * file_content = F.strng();
	cout << file_content << endl;
	
	int l = F.length();
	
	cout << "Length:\t" << l << endl;

	string fc_remoed = F.rmspace(file_content, l);
	
	cout << fc_remoed << endl;
	return 1;
}
