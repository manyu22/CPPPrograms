#include<iostream>
#include<cstring>
using namespace std;
long long hexToDec( string s )
{
  long long ans=0,temp=1;
  for(int i = s.length()-1;i>=0;i--)
  {
    if( s[i] >= 'A' && s[i] <= 'F')
    {      
      ans = ans + temp*( (s[i]-'A') + 10 ); 
      temp *= 16;
    }
    else if( s[i] >= 'a' && s[i] <= 'f')
    {
      ans = ans + temp*( (s[i]-'a') + 10 ); 
      temp *= 16;
    }
    else if( s[i]>= '0' && s[i] <= '9')
    {
      ans = ans + temp*(s[i]-'0'); 
      temp *= 16;
    }
  }
  return ans;
}

int main()
{
  string s;
  cin>>s;
  cout<<hexToDec( s )<<endl;;
  
}