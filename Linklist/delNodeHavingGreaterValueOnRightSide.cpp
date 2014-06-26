#include<iostream>
#include<climits>
#include<cstdlib>
using namespace std;
int m = INT_MIN;
class node
{
public:
  node(int val = -1,node* n=NULL):data(val),next(n){}
  int data;
  node* next;
};
void deleteNodeGreaterValueOnRight( node* head)
{
  if(head)
  {
      deleteNodeGreaterValueOnRight(head->next);
      int temp = head->data;
      if(m > head->data)
      {
	head->data = head->next->data;
	node * temp = head->next;
	head->next = head->next->next;
	free(temp);
      }
      else
	m = temp;
  }
}

void iterate( node* root)
{
  while(root)
  {
    cout<<root->data<<" ";
    root=root->next;
  }
  cout<<endl;
}

int main()
{
  node *p,*q=NULL, *head;
  int n;
  cin>>n;
  while(n--)
  {
    int a;
    cin>>a;
    p= new node(a);
    p->next = q;
    q = p;
  }
  head = p;
  iterate( head );
  deleteNodeGreaterValueOnRight( head );
  iterate( head );
}