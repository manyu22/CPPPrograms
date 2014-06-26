#include<iostream>
using namespace std;
class node
{
public:
  node(int v,node* p=NULL, node* n=NULL):data(v),prev(p),next(n){}
  node* next;
  node* prev;
  int data;
};

void display( node *head)
{
  while(head)
  {
    cout<<head->data<<" ";
    head = head->next;
  }
  cout<<endl;
}
node* reverse( node *head)
{
  node *temp,*newHead;
  while( head )
  {
    temp = head->next;
    head->next = head->prev;
    head->prev = temp;
    newHead = head;
    head = temp;    
  }
  return newHead;
}
int main()
{
  node *root = new node(1,NULL);
  root->next = new node(2,root);
  root->next->next = new node(3,root->next);
  root->next->next->next = new node(4,root->next->next);
  root->next->next->next->next = new node(5,root->next->next->next);
  display(root);
  root = reverse( root );
  display( root );
}