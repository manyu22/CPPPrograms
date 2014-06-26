// find the LCA in a BST
#include<iostream>
using namespace std;
class treenode
{
public:
  treenode( int v = 0, treenode* l=NULL, treenode* r = NULL):data(v),left(l),right(r){}
  int data;
  treenode* left;
  treenode* right;
};

int checknode( treenode * root, int value )// to check if a value exist in the tree or not
{
  if( root == NULL )
    return 0;
  else if( root->data == value )
    return 1;
  else if( value < root->data )
    return checknode( root->left, value);
  else if( value > root->data )
    return checknode( root->right, value);  
}
treenode * LCA_iterative( treenode* root, int a, int b)
{
  if( root == NULL )return NULL;
  if( !checknode(root,a) || !checknode( root,b) )
    return NULL;
  while( root )
  {
     if( min(a,b) > root->data )
      root = root->right;
     else if( max(a,b) < root->data )
      root = root->left;
     else 
      return root;
  }
  return NULL;
}

int main()
{
  treenode* root		= new treenode(24);
  root->left 			= new treenode(21);
  root->right			= new treenode(30);
  root->left->left		= new treenode(14);
  root->left->right		= new treenode(23);
  root->right->left		= new treenode(27);
  root->right->right		= new treenode(31);
  root->left->right->left 	= new treenode(22);
  
  treenode* temp = LCA( root,14,23);
  if( temp )cout<<temp->data<<endl;
  else cout<<" LCA not exist "<<endl;
}