//You have given n dices each has m faces contained number (1, 2, 3.....m) and a number x. Randomly N dices are thrown and 
//then sum of number on each face is calculated, if it is greater than x then u win else loose.
//you have to write a program which calculates the probability of winning if m, n and x is given.
//change value of x,n,m accordingly and set condition in perm function 
#include<cstdio>
int x = 10; 
int count = 0,total = 0; 
main() 
{ 
  int n=2,m=6,sum=0; 
  perm(n,m,sum); 
  printf("Favorable cases : %d and Total cases : %d",count,total); 
  exit(0); 
} 
void perm(int n,int m,int sum) 
{ 
  int i; 
  if(n==0) 
  {
    if(sum == x)) count++;
    total++;
    return;
  } 
  for(i=1;i<=m;i++) 
  { 
    perm(n-1,m,sum+i); 
  } 
}
