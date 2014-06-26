//A majority element in an array A[] of size n is an element that appears more than n/2 times (and hence there is at most one such element).
// the algorithm below works with by first finding the candidate for majority element and then checking if it is majority element or not
// naive approach is O(n^2) by finding frequency of each element, but the following one is O(n)
// the algorithm for finding the candidate for majority explicitly assume that one element occurs at least N/2 times
#include<iostream>
using namespace std;
int findCandidate(int arr[], int n)
{
  int majIndex = 0;
  int count = 1;
  for(int i = 1; i < n ; i++)
  {
    if( arr[i]== arr[majIndex])
      count++;
    else if( arr[i] != arr[majIndex])
      count--;
    if( count == 0 )
    {
      majIndex = i;
      count = 1;
    }
  }
  return arr[ majIndex ];
}
bool isMajority(int arr[],int n, int cand)
{
  int count =0;
  for(int i = 0;i < n;i++)
    if(arr[i] == cand )
      count++;
  if( count > n/2)
    return 1;
  else 
    return 0;
}
void majorityElement( int arr[], int n)
{
  int cand = findCandidate( arr, n);
  //cout<<cand<<endl;
  if( isMajority( arr, n, cand ))
    cout<<cand<<endl;
  else 
    cout<<"Element Does Not Exist\n";
}
int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  majorityElement( arr, n);
  
}
