#include<iostream>
#include<cstring>
using namespace std;
void arrangeby2( char str[], int n, int i)
{
  if( i == 1)
  { 
    str[i] = str[n];
    return;
  }
  char a = str[i-1];
  char b = str[n+i-1];
  cout<<i<<" "<<a<<" "<<b<<endl;
  
  arrangeby2( str, n, i-1);
  
  int x=2*(i-1);
  str[x]=a;cout<<str<<" "<<str[x]<<" ";
  str[x+1]=b;cout<<str[x+1]<<" "<<endl;
}
void arrangeby3(char arr[],int n,int i)
{
     if(i==1)
     {
             arr[1]=arr[n];
             arr[2]=arr[n<<1];        
             return;
     }     
     
     int a=arr[i-1];
     int b=arr[n+i-1];
     int c=arr[2*n+i-1];
     
     arrangeby3(arr,n,i-1);
     
     int x=3*(i-1);
     arr[x]=a;
     arr[x+1]=b;
     arr[x+2]=c;
     
}
int main()
{
  char str[100];
  cin.getline(str, 100);
  cout<<str<<endl;
  //arrangeby2( str, strlen(str)/2, strlen(str)/2);
  arrangeby3( str, strlen(str)/3, strlen(str)/3);
  cout<<str<<endl;
}