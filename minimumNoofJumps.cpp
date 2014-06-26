//Given an array of non-negative integers, you are initially positioned at the first index of the array.
//Each element in the array represents your maximum jump length at that position.
//Your goal is to reach the last index in the minimum number of jumps. 
// n^2 algorithm is easy to follow make an array minjump[] which stores the values to reach to that index in minimum number of jumps
//following is the O(n) algorithm, wee start from the index 0 and for the maximum possible jumps we can have from this index we go 
//to the each index reachable from this index and find max a[j]+j , i.e from whicn index we can reach the farthest and then go to that index in one jump
// and again do the same until we reach the end
#include<iostream>
#include<climits>
using namespace std;
int jump(int arr[], int n) {
    int max=1,i,j,p,count=0;
    if(n==1) return 0;       
    for( i =0;i<n;i=max)
    {
         p=INT_MIN;
         count++;
         if(i+arr[i] >=n-1)
            return count;    
         //if(arr[i]==0)return INT_MAX;
         for(j=i+1;j<=i+arr[i] && j<n;j++)
         {
            if(j+arr[j]>=n-1)
            {
                count++;
                return count;
            }
            else if(j+arr[j]>=p)
            {
                max = j;
                p=j+arr[j];
            }
          }
    }
  return count;        
}
int main()
{
  int arr[] = {2,3,1,1,4};
  cout<<jump(arr, 5)<<endl;
}
