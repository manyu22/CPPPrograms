#include<iostream>
using namespace std;
class node{
  public:
    node( char v = '@', node* n =NULL):data(v),next(n){}
    char data;
    node* next;
};
node* oddEven( node* head ){
    node *newhead, *current, *temp, *big=NULL, *small=NULL, *prev=NULL, *prevBig=NULL, *prevSmall=NULL;
    int count=1,flag;
    while( head )
    {
        //cout<<"{"<<endl;
	//if(prev!=NULL)cout<<prev->data<<endl;
	//else cout<<" --- \n";
	//cout<<head->data<<" "<<count<<endl;
        current = NULL;
        flag=0;
        if(  int(head->data) <= 91 &&  int(head->data) >= 65 )
	{  // capital alphabet
	    //cout<<"capital\n";
            if( count%2 == 1)
	    {
	        if( big == NULL)
		{
		    current = head;
		    head=head->next;
		    if( prev != NULL )
		      prev->next = current->next;
		    current->next = NULL;
		    flag=1;
		}               
		//cout<<"  countodd\n";
            }
	    else
	    {
	      if( big == NULL){
		prevBig = prev;
		big = head;
		//cout<<"  counteven\n";
	      }
	      //else 
		//cout<<"  countevenbig!=NULL\n";
	    }

	}
	else if( int(head->data) <= 122 &&  int(head->data) >= 97  )
	{ // small alphabets
	    //cout<<"small\n";
	    if( count%2 == 1)
	    {
	      if( small== NULL){
		prevSmall = prev;
		small= head;
		//cout<<"  countodd\n";
	      }
	      //else
		//cout<<"  countoddsmall!=NULL\n";
	    }
	    else
	    {
	      if( small == NULL )
	      {
		  current = head;
		  head=head->next;
		  if( prev!=NULL )
		    prev->next = current->next;
		  current->next = NULL;
		  flag=1;
	      }
	      
	    //  cout<<"  counteven\n";
	    }
      }
      
      if( current == NULL)
      {// no allocation is done
	  //cout<<"current == NULL\n";
	  if( count%2==1 && big!=NULL)
	  {
	    current = big;
	    head = big->next;
	    if( prevBig !=NULL)
	    {
	      prevBig->next = current->next;
	      
	    }
	    prev = prevBig;  
	    big=NULL;
	    current->next = NULL;
	    flag=1;
	    //cout<<"  countodd&&big!=NULL\n";
	  }
	  else if( count%2==0 && small!=NULL)
	  {
	    current = small;
	    head = small->next;
	    if( prevSmall != NULL )
	    {
	      prevSmall->next = current->next;
	     
	    }
	     prev = prevSmall;  
	    small=NULL;
	    current->next = NULL;
	    flag=1;
	    //cout<<"  counteven&&small!=NULL\n";
	  }
	  else
	  {
	  //  cout<<"  elsecase\n";
	    prev = head;
	    head = head->next;
	  }   
      }
      if( count == 1 && flag == 1){
	//cout<<"new head\n";
	newhead = current;
	temp = newhead;
      }	  
      if( flag )
      {
	  temp->next = current;
	  temp = temp->next;
	  count++;
	//  cout<<"currentIncreased\n";
      }
      //cout<<"}\n";
  }
  
  //to print rest dummy nodes with dummy nodes
  if( big !=NULL || small!=NULL )
  {
    node *t = big ? big:small;
    int c =1;
    while(t)
    {
      if( c%2 ==1 )
      { 
	temp->next = new node();
	temp = temp->next;
	c++;
      }
      else
      {
	temp->next = t;
	t=t->next;
	temp = temp->next;
	c++;
      }
    }
  }
 return newhead;
}

void iterate( node * root)
{
  while( root )
  {
    cout<<root->data<<" ";
    root=root->next;
  }
  cout<<endl;
}

int main()
{
  node *p,*q=NULL;
  int n;
  cin>>n;
  while(n--){
    char a;
    cin>>a;
    p = new node(a,q);
    q=p;    
  }
  iterate( q );
  node * newr = oddEven( p );
  iterate( newr );
}