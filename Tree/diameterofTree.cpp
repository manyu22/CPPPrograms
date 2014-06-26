#include<iostream>
using namespace std;
class treenode
{
public:
  treenode( int v =0, treenode* l=NULL, treenode* r=NULL):value(v),left(l),right(r){}
  int value;
  treenode* left;
  treenode* right;
};

int height( treenode * root)
{
  if( root == NULL)return 0;
  else {
    return max( height(root->left), height( root->right) )+1;
  }
}

int diameter( treenode * root)
{
  if( root== NULL)return 0;
  else{
    int lDia = diameter( root->left);
    int rDia = diameter( root->right);
    int lh   = height( root->left);
    int rh   = height( root->right);
    return max( max( lDia, rDia), lh+rh+1);
  }
}
// the implementation using the height is O(n^2) as we are traversing tree for diameter and height as well
//The above implementation can be optimized by calculating the height in the same recursion rather than calling a height() separately.
// since we need to get two information i.e about height and the diameter from the same function so we use pointer to get the other
// about the height
//The second parameter is to store the height of tree. Initially, we need to pass a pointer to a location with value as 0.

int OptimizedDiameter( treenode* root, int * height)
{
  if( root == NULL)
  {
    *height = 0;
    return  0; // if root is null than diameter and height are both zero
  }
  else 
  {
   int lDia=0, rDia=0, lh=0, rh=0;
   lDia = OptimizedDiameter( root->left, &lh);
   rDia = OptimizedDiameter( root->right, &rh);
   *height = max( lh, rh) + 1;
   
   return max(max(lDia, rDia),lh+rh+1);
  }
}
// the above version is of O(n) complexity
int main()
{
  treenode* root	= new treenode(2);
  root->left 		= new treenode(45);
  root->right		= new treenode(12);
  root->left->left	= new treenode(34);
  root->left->right	= new treenode(67);
  root->right->left	= new treenode(-4);
  root->right->right	= new treenode(-7);
  root->left->right->left = new treenode(333);
  int height = 0;
  cout<< OptimizedDiameter( root,&height )<<endl;
  cout<< diameter( root )<<" "<<height<<endl;
}