#include<iostream>
using namespace std;
int gcd(int a, int b)// b is smaller than a
{
  if( b == 0)
    return a;
  else
    return gcd(b, a%b);
}
int main()
{
 int a,b,temp1,temp2;
 cin>>a>>b;
 temp1 = a>b?a:b;
 temp2 = a>b?b:a;
 cout<<gcd( temp1,temp2)<<endl;
}
