// iterative inorder traversal
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
void iterativeinorder( treenode * root)
{
  stack<treenode*> st;
  treenode *current = root;
  bool done = 1;
  while( done )
  {
    if( current )
    {
      st.push( current );
      current = current->left;
    }
    else
    {
      if( !st.empty() )
      {
	cout<<st.top()->value<<" "<<endl;
	current = st.top()->right;
	st.pop();
      }
      else 
	done = 0;
    }
  }
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
  iterativeinorder( root );
}