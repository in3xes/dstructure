/*(C) Pradeepkumar Gayam <deepu.aprjc@gmail.com>		*/


#include <iostream>
using namespace std;

class structure
{

public:	

  structure()
  {
    store = new node();
		
  }
  struct node 
  {	
    int value;
    node *next;
  };
  node *store; 
  int initial(int len);
  int print(int len);
  int insert(int val, int position);
  int search(int sear);
};

int structure::initial(int len)
{

  node *p = new node();

  for(int i=0; i< len; i++)
    {
      node *p = new node();
      cout << p->value << endl;

      if(i==1)
	{
	  cout << "Enter value "<< i << "\t";
	  cin >> p->value; 
	  store->value = p->value;
	  store->next = NULL;
	}
      else
	{
	  cout << "Enter value " << i << "\t";
	  cin >> p->value;
	  store->next = p;
	  store = store->next;
	}
    }

  return 0;
}

int structure::print(int len)
{
  //	while(store.next != NULL);
  for(int i = 0; i<len; i++)
    {
      cout << store->value <<endl;
      store = store->next;
    }
}

int main()
{
  structure d_s;	
  //	cout << d_s.store.value << endl;
  d_s.initial(5);
  d_s.print(5);
  return 0;
}
