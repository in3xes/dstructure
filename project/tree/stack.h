#include <iostream>
#include <assert.h>
#include <stdbool.h>

using namespace std;

struct treenode {
	int info;
	bool isvisited;
	struct treenode * left;
	struct treenode * right;
};

typedef struct treenode * TREEPTR;

struct node {
	treenode * element;
	struct node * next;
};

typedef struct node *STACKPTR;

STACKPTR getnode(TREEPTR element) {
	STACKPTR temp;
	temp = new node;
	
	temp->element = element;
	temp->next = NULL;
	
	return temp;
}

void pushstack(STACKPTR *topref, TREEPTR info) { 
	STACKPTR temp = getnode(info);
	if( *topref == NULL ) {
		temp->next = NULL;
		*topref = temp;
		return;
	}
	
	temp->next = *topref;
	*topref = temp;
}

bool isemptystack(STACKPTR top) {
	if(top == NULL) 
		return true;
	else
		return false;
}

TREEPTR popstack(STACKPTR * topref) {
	if(!isemptystack(*topref)) {
		STACKPTR temp = *topref;
		*topref = temp->next;
		temp->next = NULL;

		return temp->element;
	}
	return  NULL;
	
}

