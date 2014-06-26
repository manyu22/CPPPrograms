// infix to postfix based on the shunting engine algorithm
#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

char prefix[100];
char postfix[100];

bool isOperator( char sym )
{
  if( sym == '+'|| sym == '-'|| sym == '/'|| sym == '*')
    return 1;
  else return 0;
}
int priority( char sym )
{
    if( sym == '+'|| sym == '-')return 1;
    else if( sym == '/' || sym == '*') return 2;
}
void infixToPostfix( char infix[], int n)
{
  int j = 0;
  stack<char> st;
  for( int i = 0; i< n ;i++)
  {
    if( isOperator(infix[i]) )
    {
      if( st.empty())// if stack is empty just push the operator onto the stack
	st.push( infix[i]);
      else if( priority( infix[i]) > priority( st.top() ) ){//if priority is greater then push onto the stack
	st.push( infix[i] );
      }	
      else// else check with the top if new opartor's priority <= then top of the stack then pop from the stack and append to the postfix string
      {
	while( !st.empty() && (priority(infix[i])<= priority(st.top())) )
	{
	  postfix[j++] = st.top();
	  st.pop();
	}
	st.push( infix[i] );
      }      
    }
    else
    {
      postfix[j++] = infix[i];
    }
  }
  while( !st.empty())// pop from the stack until empty
  {
    postfix[j++]= st.top();
    st.pop();
  }
  postfix[j] = '\0';
}
// similarly we can convert to prefix using 2 stacks and traversing from the back of the infix string
int main()
{
  char string[100];
  cin>>string;
  infixToPostfix( string, strlen(string));
  cout<<postfix<<endl;
}