// detect the loop in the linklist and remove it
#include<iostream>
using namespace std;
class node
{
public:
  node(int v,node* n=NULL):value(v),next(n){}
  int value;
  node *next;
};
node *intersectAt;// stores the point where fast and slow pointer intersect
bool detectLoop( node *head )
{
  node *fast = head,*slow = head;
  while( fast && slow && fast->next )
  {
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast)
    {
      intersectAt = slow;
      return 1;//loop found
    }
      
  }
  return 0;
}
int lengthOfLoop()
{
  node * temp = intersectAt;
  int len=1;
  temp = temp->next;
  while( intersectAt != temp )
  {
    temp = temp->next;
    len++;
  }
  return len;
}
int len;// to store the length of the LL
bool removeLoop( node * head)
{
  if( detectLoop( head) )
  {
    int loopLength = lengthOfLoop();
    node *ptr1 = head;
    node *ptr2 = head;
    node *prev = NULL;
    //move ptr2 to the k node from start 
    for( int i = 0; i< loopLength; i++)
    {
      ptr2=ptr2->next;
    }
    // now iterate both the pointer so that they coincide that point will be the start of the loop
    int lenBeforeLoop = 0;
    while( ptr1 != ptr2 )
    {
      ptr1 = ptr1->next;
      ptr2 = ptr2->next;
      lenBeforeLoop++;
    }    
    // Get pointer to the last node
    ptr2 = ptr2->next;
    while(ptr2->next != ptr1)
       ptr2 = ptr2->next;
 
    // Set the next node of the loop ending node to fix the loop
    ptr2->next = NULL;
    len = lenBeforeLoop + loopLength ;
  }
  else
    cout<<"loop is not present\n";
}
void iterate( node *root )
{
  while( root )
  {
    cout<<root->value<<" ";
    root = root->next;
  }
  cout<<endl;  
}
int main()
{
  node *p,*q=NULL,*root;
  p = new node(1);
  p->next = new node(2);
  p->next->next = new node(3);
  p->next->next->next = new node(4);
  p->next->next->next->next = new node(5);
  p->next->next->next->next->next = new node(6);
  p->next->next->next->next->next->next = p;
  cout<<detectLoop( p )<<endl;
  cout<<lengthOfLoop()<<endl;
  removeLoop( p );
  iterate( p );
  cout<<len<<endl;
}