#include <iostream>
#include <queue>
using namespace std;


bool comp(int a,int b)
{
  return a>b?1:0;
}
int main ()
{
  priority_queue<int,comp> mypq;

  mypq.push(30);
  mypq.push(100);
  mypq.push(25);
  mypq.push(40);

  cout << "Popping out elements...";
  while (!mypq.empty())
  {
     cout << " " << mypq.top();
     mypq.pop();
  }
  cout << endl;

  return 0;
}