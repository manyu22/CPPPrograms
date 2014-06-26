#include<iostream>
#include<stack>
using namespace std;
class treenode
{
  public:
    treenode( int val = 0, treenode* a = NULL, treenode* b = NULL ):value(val),left(a),right(b){}
    int value;
    treenode * left;
    treenode * right;
};
// A function to print all left boundry nodes, except a leaf node.
// Print the nodes in TOP DOWN manner
void printLeftBoundary( treenode * root){
  if(root){
    if( root->left){
      cout<<root->value<<" ";
      printLeftBoundary(root->left);
    }   
    else if( root->right){
      cout<<root->value<<" ";
      printLeftBoundary(root->right);
    }      
  }
}
// A function to print all right boundry nodes, except a leaf node
// Print the nodes in BOTTOM UP manner
void printRightBoundary( treenode * root){
  if(root){
    if( root->right ){
      // to ensure bottom up order, first call for right
            //  subtree, then print this node
      printRightBoundary( root->right );
      cout<<root->value<<" ";
    }      
    else if( root->left ){
      printRightBoundary( root->left);
      cout<<root->value<<" ";
    }
  }
}
// A simple function to print leaf nodes of a binary tree
void printLeaves( treenode * root){
  if( root ){
    printLeaves( root->left );
    if( !root->left && ! root->right )
      cout<<root->value<<" ";
    printLeaves( root->right );
  }
}
void printBoundary( treenode * root){
  if( root ){
    cout<<root->value<<" ";
    printLeftBoundary( root->left );
    printLeaves( root->left );
    printLeaves( root->right );
    printRightBoundary( root-> right );
  }
}

int main(){
  treenode* root	= new treenode(2);
  root->left 		= new treenode(45);
  root->right		= new treenode(12);
  root->left->left	= new treenode(34);
  root->left->right	= new treenode(67);
  root->right->left	= new treenode(-4);
  root->right->right	= new treenode(-7);
  root->left->right->left = new treenode(333);
  printBoundary( root );
  cout<<"\n";
}