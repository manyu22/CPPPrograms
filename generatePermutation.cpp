#include<iostream>
#include<cstring>
using namespace std;
void swap(char s[], int a,int b)
{
  int temp = s[a];
  s[a]=s[b];
  s[b]=temp;
  
}
void permute(char s[], int n,int index)
{
  if( index == n-1)
  {
    cout<<s<<endl; 
  }
  else
  {
    for(int j = index; j < n ;j++)
    {
      swap(s,j,index);
      permute(s,n,index+1);
      swap(s,j,index);
    }
  }
}
int main()
{
  char a[100];
  cin>>a;
  permute(a,strlen(a),0);
}