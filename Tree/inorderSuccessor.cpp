#include<iostream>
using namespace std;
class treenode
{
public:
  treenode( int d=0,treenode* l=NULL, treenode* r = NULL):data(d),left(l),right(r){}
  int data;
  treenode* left;
  treenode* right;
};
treenode * minimum( treenode * root)
{
  if( root->left)
    return minimum( root->left);
  else
    return root;
}
treenode * inorderSuccessor( treenode *root, treenode* p)
{
  if( p->right)
    return minimum( p->right);
  else
  {
    treenode * succ = NULL;
    while( root )// start from the root and search down the tree
    {
      if( p->data < root->data )
      {
	succ = root;
	root = root->left;
      }
      else if( p->data > root->data)
      {
	root = root->right;
      }
      else break;// if p = root
    }
    return succ;
  }
}
int main()
{
  treenode* root 			= new treenode(8);
  root->left     			= new treenode(3);
  root->right    			= new treenode(10);
  root->left->left			= new treenode(2);
  root->left->right			= new treenode(4);
  root->left->right->right      	= new treenode(6);
  root->left->right->right->left	= new treenode(5);
  root->left->right->right->right	= new treenode(7);
  
  treenode * temp= inorderSuccessor( root,root->left->right->right);
  if( temp )
    cout<<temp->data<<endl;
  else cout<<"not exist"<<endl;
}