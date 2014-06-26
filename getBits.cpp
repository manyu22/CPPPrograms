#include<iostream>
using namespace std;
int main()
{
  int a;
  cin>>a;
  char str[32];
  int temp =a;
  int count =31;
  for(int i=0;i<32;i++)
  {
    if( temp%2 )str[count--] = '1';
    else str[count--] = '0';
    temp >>= 1;
  }
  cout<<str<<endl;
}