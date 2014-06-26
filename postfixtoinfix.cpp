//postfic to infix conversion, similar to postfix evaluation
#include<cstring>
#include<iostream>
#include<stack>
using namespace std;
bool isOperator( char sym)
{
  if( sym=='+'||sym=='-'||sym=='*'||sym=='/')
    return 1;
  else 
    return 0;
}
string postfixToInfix( string postfix)
{
  stack<string> st;
  for( int i = 0; i < postfix.length(); i++)
  {
    if( isOperator(postfix[i]) )
    {
      string temp  = "";
      string operand2 = st.top();
      st.pop();
      string operand1 = st.top();
      st.pop();
      temp += operand1 + postfix[i] + operand2;
      st.push(temp);
    }
    else{
      string temp = "";
      temp += postfix[i];
      st.push( temp );
    }
  }
  return st.top(); 
}

int main()
{
  string s;
  cin>>s;
  cout<<postfixToInfix( s )<<endl;
  return 0;
}