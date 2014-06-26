# include<iostream>
#include<cstdio>
# define MAX_SIZE 100
// the number of such possible brackets for n pair is actually given by catalan number for n  (2n)!/(n!*(n+1)!)
void _printParenthesis(int pos, int n, int open, int close)// open and close maintains the count of the open and close brakets
{
  static char str[MAX_SIZE];    
 
  if(close == n)
  {
    printf("%s %d\n", str, count);
    return;
  }
  else
  {
    if(open > close) {
        str[pos] = '}';
        _printParenthesis(pos+1, n, open, close+1);
    }
    if(open < n) {
       str[pos] = '{';
       _printParenthesis(pos+1, n, open+1, close);
    }
  }
}

void printParenthesis(int n)
{
  if(n > 0)
     _printParenthesis(0, n, 0, 0);
  return;
}

int main()
{
  int n = 5;
  printParenthesis(n);
  return 0;
}