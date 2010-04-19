#include "stack.h"


TREEPTR gettreenode(int x) {
	TREEPTR temp;
	temp = new treenode;
	temp->info = x;
	temp->left = temp->right = NULL;
	temp->isvisited = false;
	
	return temp;
}

void addtotree(TREEPTR * treeref, int x) {
	if((*treeref) == NULL) {
		TREEPTR temp = gettreenode(x);
		*treeref = temp;
		return;
	}
	if(x < (*treeref)->info)
		addtotree(&(*treeref)->left, x);
	else
		addtotree(&(*treeref)->right, x);

}

void inorderrec(TREEPTR tree) {
	if(tree != NULL) {
		inorderrec(tree->left);
		cout << "\n" << tree->info;
		inorderrec(tree->right);
	}
}

void preorderrec(TREEPTR tree) {
	if(tree != NULL) {
		cout << "\n" << tree->info;
		preorderrec(tree->left);
		preorderrec(tree->right);
	}
}

void postorderrec(TREEPTR tree) {
	if(tree != NULL) {
		postorderrec(tree->left);
		postorderrec(tree->right);
		cout << "\n" << tree->info;
	}
}

void inorderiterative(TREEPTR tree){

	STACKPTR stacktop = NULL;
	
	TREEPTR current = tree;

	do{
		while(current != NULL) {
			pushstack(&stacktop, current);
			current = current->left;
	}

	if(!isemptystack(stacktop)) {
		current = popstack(&stacktop);
		cout << "\n" << current->info;
		current = current->right;
	}
	}
	while(!isemptystack(stacktop) || current != NULL);

}


void preorderiterative(TREEPTR tree) {

	STACKPTR stacktop = NULL;

	TREEPTR current = tree;

	do {
		while(current != NULL) {
			cout << "\n" << current->info;
			pushstack(&stacktop,  current->right);
			current = current->left;
		}
		
		if(!isemptystack(stacktop)) {
			current = (TREEPTR ) popstack(&stacktop);
		}
	}while(!isemptystack(stacktop) || current != NULL);
}

void postorderiterative(TREEPTR tree) {

	STACKPTR stacktop = NULL;

	TREEPTR current = tree;

	do {
		while(current != NULL ) {
			pushstack(&stacktop, current);
			current = current->left;
		}
		
		if(!isemptystack(stacktop)) {
			current = (TREEPTR ) popstack(&stacktop);
			if(current->right == NULL) {
				cout << "\n" << current->info;
				current = current->right;
			}
			else{
				if(current->isvisited == true ) {
					cout << "\n" << current->info;
					current = NULL;
				}
				else {
					current->isvisited = true;
					pushstack(&stacktop, current);
					current = current->right;
				}
			}
		}
	}while(!isemptystack(stacktop) || current != NULL);
}
