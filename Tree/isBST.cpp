// to check if a tree given is binary search tree or not
// the following program runs as a inorder traversal will search, if the node values are sorted then the tree is BST otherwise not
#include<iostream>
using namespace std;
class treenode
{
  public:
    treenode( int val = 0, treenode* a = NULL, treenode* b = NULL ):value(val),left(a),right(b){}
    int value;
    treenode * left;
    treenode * right;
};
bool isBST( treenode *root)
{
  static treenode* prev = NULL;
  if(root)
  {
    if( !isBST( root->left ))
      return false;
    
    if( prev!=NULL && prev->value >= root->value )
      return false;
    prev = root;//crutial
    return isBST(root->right);
  }
  return true;
}
int main(){
  
  treenode* root		= new treenode(2);
  root->left 			= new treenode(45);
  root->right			= new treenode(12);
  root->left->left		= new treenode(34);
  root->left->right		= new treenode(67);
  root->right->left		= new treenode(-4);
  root->right->right		= new treenode(-7);
  root->left->right->left 	= new treenode(333);
  cout<<isBST(root)<<endl;
}