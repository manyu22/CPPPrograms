// copies n bits from a to b starting a index  start from the right that is LSB
#include<iostream>
using namespace std;
int main()
{
  int a,b,n,start;
  cin>>a>>b>>n>>start;
  int temp = 1;
  temp = temp<<start;
  cout<<" "<<temp<<endl;
  int mask = temp;
  for(int i=1;i<n;i++)
  {
    temp= temp<<1;
    mask = mask | temp;
  }
  cout<<" mask1 "<<mask<<endl;
  mask = mask & a;
  cout<<" mask2 "<<mask<<endl;
  b    = b | mask;
  cout<<b<<endl;
}