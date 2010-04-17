/* (C) 2010 Pradeepkumar Gayam <deepu.aprjc@gmail.com>				*/
/* Fri, Feb 05 2010, 2100							*/
/*
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License with
  the Debian GNU/Linux distribution in file /usr/doc/copyright/GPL;
  if not, write to the Free Software Foundation, Inc., 59 Temple Place,
  Suite 330, Boston, MA  02111-1307  USA
*/


#include <iostream>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

#define ATYPE int
#define VTYPE int 
#define MAX 100
#define MIN 0

using namespace std;

/* typedef struct {
	ATYPE array[MAX];
	VTYPE top;
	} Array;

*/

class stack {

	private:
		
	int Array[MAX];
	int top;
	
	public:
	
	void push(int item);
	void pop();
	void print();
	int print_one(int x);
	int find_small();
	int return_top();
	int return_top_value();

	stack();
};

stack::stack(void) {
	top = -1;
	}
void stack::push(int item) {
	
	if(top < MAX-1)	{
		top++;
		Array[top] = item;
	}
}

void stack::pop() {
	
	if(top >=0) {
		Array[top] = 0;
		top--;
	}
}

void stack::print() {
	
	for(int i = top; i >= 0; i--) {
		cout << Array[i] << endl;
	}
}

int stack::print_one(int x) {
//	if(top != (-1)) {
		if(Array[x] > MAX || Array[x] < MIN)
			return 0;
		else
			return  Array[x];
//	}
//	else
//		return 0;
}

int stack::find_small() {
	
	if(Array[top] == 1)
		return 1;
	else
		return 0;
}

int stack::return_top() {
	if (top < 0)
		return 0;
	else
		return Array[top];
}

int stack::return_top_value() {
	return top;
}

class hanoi : public stack {

	private:

	VTYPE N;
	
	public:

	stack A,B,C;
	void create_array(int x);
	void move_small();
	void move_legal();
	void print_towers();
	int find_small();
	void shift(stack *A, stack *B);

	hanoi() {
	}

};

void hanoi::create_array(int x) {
	
	N = x;

	for(int i = N; i > 0; i--) {
		A.push(i);
		B.push(0);
		C.push(0);
	}
	for(int i = N; i > 0; i--) {
		B.pop();
		C.pop();
	}

		
}

int hanoi::find_small() {
	
	if(A.find_small())
		return 1;
	if(B.find_small())
		return 2;
	if(C.find_small())
		return 3; 
}

void hanoi::move_small() {

	if(N%2 == 1) {
	
		switch (find_small()) {
			case 1 :
				A.pop();
				B.push(1);
				break;
			case 2 :
				B.pop();
				C.push(1);
				break;
			case 3 :
				C.pop();
				A.push(1);
		}
	}
	else {
		switch (find_small()) {
			case 1 :
				A.pop();
				C.push(1);
				break;
			case 2 :
				B.pop();
				A.push(1);
				break;
			case 3 :
				C.pop();
				B.push(1);
		}
	}
}

void hanoi::shift(stack *A, stack *B) {
	int tmp = 0;
	if(A->return_top_value() == -1) {
		shift(B,A);
	}
	else {
		tmp = A->return_top();
		A->pop(); 
		B->push(tmp);
	}
}

void hanoi::move_legal() {
	int tmp = 0;	
	switch (find_small()) {
		case 1 :
			if(B.return_top() < C.return_top() )
				shift(&B, &C);
			else if (B.return_top() > C.return_top() )
				shift(&C, &B);
			else {
				exit(1);
			}
			break;
		case 2 :
			if(A.return_top() < C.return_top() )
				shift(&A, &C);
			else if (A.return_top() > C.return_top()) 
				shift(&C,&A);
			else {
//				cout << A.return_top() << "\t" << C.return_top() << "\t" << C.return_top_value() << endl;
				exit(2);
			}
			break;
		case 3 :
			if(A.return_top() < B.return_top() )
				shift(&A, &B);
			else if (A.return_top() > B.return_top())
				shift(&B, &A);
			else {
				exit(3); 
			}
	 } 
}

void hanoi::print_towers() {
	
	for(int i = 0; i < 2; i++) {
		cout <<" | \t | \t | \n";
	}
	for(int i = N-1; i >=0; i--) {
	cout << " " << A.print_one(i) << " \t " << B.print_one(i) << " \t " << C.print_one(i) << " \n";
	}
	cout << "___\t___\t___\n";
	cout << "-------------------\n";
//	for(int i=0; i < 30; i++) {
//		cout << endl;
//	}
}


int main(int argc, char **argv)
{
	if(argc < 2) {
		cout << "Usage : "<<argv[0]<<" N (N = Number of disks)\n";
		exit(4);
	}
	int a = atoi(argv[1]);
	hanoi h;
	h.create_array(a);
	cout << "Intial tower\n";
	h.print_towers();
	int count = 0;

	for(int i = 0; i >=0; i++) {
		count++;
		h.move_small();
		cout << "Move number: " << count << endl;
		h.print_towers();
		sleep(1);
//		getchar();

		count++;
		h.move_legal();
		cout << "\rMove number: " << count << endl;
		h.print_towers();
		sleep(1);
//		getchar();
	}
	
}
