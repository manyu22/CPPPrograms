#include<iostream>
#include<climits>
using namespace std;
class treenode
{ 
public:
  treenode(int d=0,treenode *l=NULL, treenode*r =NULL):data(d),left(l),right(r){}
  treenode *left;
  treenode *right;
  int data;
};
int kthSmallest( treenode * root, int k)
{
  static int count = 0;
  if( root)
  {
    int temp = kthSmallest( root->left,k );
    if(temp != INT_MIN)return temp;// if kth minimum not found in the left tree then find in the right subtree
    count++;
    if( count == k) return root->data;
    return kthSmallest( root->right,k);
  }
  else return INT_MIN;
}
int main()
{
 
  treenode* root		= new treenode(2);
  root->left 			= new treenode(45);
  root->right			= new treenode(12);
  root->left->left		= new treenode(34);
  root->left->right		= new treenode(67);
  root->right->left		= new treenode(-4);
  root->right->right		= new treenode(-7);
  root->left->right->left 	= new treenode(333);
  cout<<endl<<kthSmallest(root, 4)<<endl;
}