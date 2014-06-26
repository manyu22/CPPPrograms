#include<iostream>
using namespace std;

class node
{
public:
  node( int v = 0, node * n = NULL):value(v),next(n){}
  int value;
  node * next;
};
// reverse the complete linklist
node *reverse( node * head )
{
  node *p,*q=NULL,*temp;
  temp = head;
  while( temp )
  {
    p = q; // q stores the address to previous node that it copies to p now
    q = temp;// q now points to current node
    temp = temp->next;// iterator temp now point to next node
    q->next = p;
  }
  return q;
}
// reverse the list in parts
node * reverseInPart( node * head , int n)
{
  node *p,*q=NULL,*temp;
  int k = n;
  temp= head;
  if( head == NULL )return NULL;
  while(k-- && temp )
  {
    p = q;
    q = temp;
    temp = temp->next;
    q->next = p;
  }
  head->next = reverseInPart( temp , n);// this is the important step
  return q;
}
void iterate( node* head)
{
  while( head )
  {
    cout<<head->value<<" ";
    head = head->next;
  }
  cout<<endl;
}
int main()
{
  node *p,*q=NULL,*head;
  int n;
  cin>>n;
  while(n--)
  {
    int v;
    cin>>v;
    p = new node(v,q);
    q=p;
  }
  head = p;
  iterate( head );
  head = reverse( head );
  iterate( head );
  head = reverseInPart( head , 3);
  iterate( head );
}