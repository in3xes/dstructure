#include <iostream>
#include <assert.h>
#include <stdbool.h>

using namespace std;

struct node {
	void *element;
	struct node * next;
};

typedef struct node *STACKPTR;

STACKPTR getnode(void * element) {
	STACKPTR temp;
	temp = new node;
	
	temp->element = element;
	temp->next = NULL;
	
	return temp;
}

void pushstack(STACKPTR *topref, void * info) {

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

void * popstack(STACKPTR * topref) {
	if(!isemptystack(*topref)) {
		STACKPTR temp = *topref;
		*topref = temp->next;
		temp->next = NULL;
	}
	assert(0);
}

