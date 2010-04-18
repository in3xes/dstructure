#include "tree.h"

int main() {

	TREEPTR treehead = NULL;
	int i = 0;
	int element[] = {100, 10, 200, 12, 20, 1, 4, 3, 67, 66, 210 , 199};
	while(i < 12) {
		addtotree(&treehead, element[i]);
		i++;
	}
	
	cout << "\nInorder recursive traversal";
	inorderrec(treehead);
	cout << "\nInorder iterative traversal";
	inorderiterative(treehead);

	cout << "\nPreorder recursive traversal ";
	preorderrec(treehead);
	cout << "\nPreorder iterative traversal";
	preorderiterative(treehead);

	cout << "\nPostorder recursive traversal";
	postorderrec(treehead);
	cout << "\nPostorder iterative traversal";
	postorderiterative(treehead);

	cout << endl;

	return 1;
}

