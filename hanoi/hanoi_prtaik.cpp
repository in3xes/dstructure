/*
  Name: 
  Copyright: 
  Author: 
  Date: 25-02-10 16:05
  Description: 
*/

#include<iostream>

#define MAX_DISKS 100
using namespace std;


void move(int el[], int from_c, int to_c, int temp_c, int length)
{
	int i=0, el_allbutone[MAX_DISKS], el_last[1];

	/* el_allbutone represents all except the last disk from the
	   current stack being transferred */
	/* el_last represents the last disk */
	/* el_last is kept as an array for uniformity, even though it
	   has only one element */

	if (length == 1)
	{
		cout<<"Move the topmost disk on tower "<<from_c<<" to tower "<<to_c<<".\n";
		
		
	} 
	
	else 
	{
		/* Initialize the el_allbutone array */


		for (i=0;i<(length-1);i++)
		{
			el_allbutone[i]=el[i];
		}

		el_last[0]=el[length-1];

		/* Move top (n-1) disks to the 'temporary' tower */
		move(el_allbutone, from_c, temp_c, to_c, length-1);

		/* Move the last disk to the 'destination' tower */
		move(el_last, from_c, to_c, temp_c, 1);

		/* Move the (n-1) disks from the 'temporary' to the
		   'destination' tower */

		move(el_allbutone, temp_c, to_c, from_c, length-1);
		
	}
}

long long int number_of_moves(int n)
{				
	// Since T(n) = 2T(n-1) + 1 for n > 1
	// and T(1) = 1
	// If n is greater than one, then return 2*T(n-1) + 1
	// Else return 1

	return (n > 1 ? 2*number_of_moves(n-1) + 1 : 1);
}


int main()
{				
	int el[MAX_DISKS];	// Represents the disks initially
	
	int n;
	cout<<"Tower of Hanoi\n---------------\n";
	
	cout<<"Enter the number of disks:";
	cin>>n;
	
	if (n==0)
	{
		cout<<"\nZero disks require zero moves.\n";
		return 0;
	}
	
	for (int i=0;i<n;i++)
	{
		el[i]=i;
	}
	
	cout<<"\n1: Start tower";
	cout<<"\n2: Destination tower";
	cout<<"\n3: Third tower";
	cout<<"\n";
	
	move(el,1,2,3,n);

	cout<<"\nNumber of moves: "<<number_of_moves(n)<<"\n";
	
	return 0;
}	
