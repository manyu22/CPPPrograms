// reverse a string without finding its length
// logic is to use pointer to a pointer, in this way we can save a reference to the start of the string
// till we find its end, when we find it end we start incrementing from the start, so when recursive call return they find the incremented value of 
// address that started from the start. So in this way we can reflect the change in the recusive calls.
#include<iostream>
#include<cstdio>
using namespace std;
void reverseString( char * p, char ** start){
 if ( *p =='\0')return;
 else {
  reverseString( p+1, start );
  if( p - *start == 0 || *start - p > 0 )return;
  else{
    char temp = *p;
    *p = **start;
    **start = temp;
    (*start)++;
  }
  
 }
}
int main()
{
 char arr[50] = "i am abhimanyu";
 char *p = arr;
 reverseString( arr, &p );
 cout<<arr<<endl;
 
}
