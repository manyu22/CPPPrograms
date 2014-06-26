#include<iostream>
#include<stack>
using namespace std;

stack<int> inbox;
stack<int> outbox;

void enqueue( int value )
{
  inbox.push( value );
}
int dequeue()
{
  int temp;
  if( !outbox.empty() ){    
    temp = outbox.top();
    outbox.pop();
    return temp;
  }    
  else{
    while( !inbox.empty() ){
      outbox.push( inbox.top());
      inbox.pop();
    }
    if( !outbox.empty() ){
      temp = outbox.top();
      outbox.pop();
      return temp;
    }
    else return NULL;
  }
}
int main()
{
  enqueue( 10 );
  enqueue( 20 );
  enqueue( -1);
  cout<<dequeue()<<endl;
  cout<<dequeue()<<endl;
  cout<<dequeue()<<endl;
  cout<<dequeue()<<endl;
}
