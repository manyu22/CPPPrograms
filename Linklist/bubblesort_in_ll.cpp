// implement a bubble sort in a linklist
#include<iostream>
using namespace std;
class node
{
public:
  node( int v = 0, node* n=NULL):value(v),next(n){}
  int value;
  node* next;
};

void iterate( node* head)
{
  while( head )
  {
    cout<<head->value<<" ";
    head = head->next;
  }
  cout<<endl;
}
void bubblesort( node *head )
{
  node *end=NULL,*start=head,*temp,*prev;
  bool flag = 1;
  while( flag )
  {
    temp = start;
    flag = 0;
    while( temp != end )
    {
      if( temp->next != NULL && temp->value > temp->next->value )
      {
	int val 	  = temp->value;
	temp->value 	  = temp->next->value;
	temp->next->value  = val;
	flag = 1;
      }
      prev = temp;// saving the previous value
      temp = temp->next;
    }
    prev = end;// reducing the end by one node as now the last node contains the highest value
  }
}
int main()
{
  node *p,*q=NULL,*head;
  int n,a;
  cin>>n;
  while( n-- )
  {
    cin>>a;
    p = new node(a,q);
    q=p;
  }
  head = p;
  iterate( head );
  bubblesort( head );
  iterate( head );
}