#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int isOperator( char sym ) // to check for the operator
{
  if( sym == '+'|| sym == '-' || sym == '/' || sym == '*')
    return 1;
  else return 0;
}
char postfix[ 100 ];
char prefix[ 100 ];
void prefixToPostfix( char prefix[], int n)
{
  stack<char> st;
  int j=0;
  for( int i=0;i<n;i++)
  {
    if( isOperator(prefix[i]) )
    {
      st.push( prefix[i] );
    }
    else
    {
      postfix[j++] = prefix[i];
      while( !st.empty() && st.top() == '#')
      {
	st.pop();			// # popped
	char temp = st.top();
	st.pop(); 			// oparator popped
	postfix[j++] = temp;
      }
      st.push('#');  // by inserting # we basically keeps a check if we have two operands in our postfix string over which a operator will perform
    }
  }
  postfix[j] = '\0';
}
// similar is the conversion from postfic to prefix, scanning from the end and maintaining two stacks in this case one for operators and one for the output
// thanks to abhilasha for the explaination.
void postfixToPrefix( char postfix[], int n)
{
  stack<char> st1, st2;
  for( int i = n-1; i>=0; i--)
  {
    if( isOperator(postfix[i]) ){
      st1.push( postfix[i] );
    }
    else
    {
      st2.push( postfix[i]);
      while( !st1.empty() && st1.top() == '#')
      {
	st1.pop();
	char temp = st1.top();
	st1.pop();
	st2.push(temp);
      }
      st1.push('#');
    }
  }
  int i = 0;
  while(!st2.empty()) // 
  {
    prefix[i++]=st2.top();
    st2.pop();
  }
  prefix[i] = '\0';
}

int main()
{
  char string[100];
  cin>>string;
  prefixToPostfix( string, strlen(string));
  cout<<postfix<<endl;
  postfixToPrefix( postfix, strlen(string));
  cout<<prefix<<endl;
  return 0;
}