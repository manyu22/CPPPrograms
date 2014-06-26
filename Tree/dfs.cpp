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
void dfs( treenode *root)
{
  if(root)
  {
      cout<<root->value<<" ";
      for(int i=0;i<2;i++)
      {
	if(i==0 && root->left)
	{
	  dfs(root->left);
	}
	if(i==1 && root->right)
	{
	  dfs(root->right);
	}
      }
  }
  
}
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
  dfs(root);
}