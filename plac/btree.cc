#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

struct node {
  int info;
  bool visited;
  node *left;
  node *right;
};

node* init(int x) {
  node *temp = new node;
  temp->info = x;
  temp->visited = false;
  temp->right = temp->left = 0;

  return temp;
}

void insert(node* &root, int x) {

  if(root == 0) {
    root = init(x);
    return;
  }
  else if(root->info > x) {
    insert(root->left, x);
  }
  else {
    insert(root->right, x);
  }
}

void inorder(node *tree) {
  if(tree != 0) {
    inorder(tree->left);
    inorder(tree->right);
    printf("%d\n", tree->info);
  }
}

void postorder_iter(node * tree) {

  stack <node*> postorder;
  
  node * cur = tree;
  do{
    while(cur) {
      postorder.push(cur);
      cur = cur->left;
    }
    if(!postorder.empty()) {
      cur = postorder.top();
      postorder.pop();
      if(cur->right == 0) {
	cout << cur->info << endl;
	cur = 0;
      }
      else {
	if(cur->visited) {
	  cout << cur->info << endl;
	  cur = 0;
	}
	else {
	  cur->visited = true;
	  postorder.push(cur);
	  cur = cur->right;
	}
      }
    }
  }
  while(!postorder.empty() || cur != 0);
}	

int main() {
  node * tree = 0;
  insert(tree, 10);
  for(int x = 1; x<20; x++)
    insert(tree, x);

  cout << tree->info << endl;
  inorder(tree);
  postorder_iter(tree);

  return 0;
}
