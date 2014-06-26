#include<iostream>
#include<stack>
#include<cstdlib>
using namespace std;
typedef struct node
{
        int data;
        struct node *left;
        struct node *right;
}mytree;
mytree* add(int val)
{
        mytree* node=(mytree*)malloc(sizeof(mytree));
        node->data=val;
        node->left=NULL;
        node->right=NULL;        
        return node;
}
bool isIsomorphic( mytree* r1, mytree * r2)
{
 if( r1  && r2 )
 {
   if(r1->data == r2->data)
   {
     if(r1->left && r2->left  && r1->left->data == r2->left->data)
     {
	return (isIsomorphic( r1->left, r2->left) && isIsomorphic(r1->right, r2->right));
     }
     else if( r1->left && r1->right && r1->left->data == r2->right->data)
     {
	return (isIsomorphic(r1->left,r2->right) && isIsomorphic(r1->right, r2->left));
     }
     else return false;
   }
   else 
     return false;
 }
 else if( !r1 && !r2 )
  return true; 
 else
  return false;   
}
int isomorphic(mytree* t1,mytree* t2)
{
    if(t1==NULL && t2==NULL)
    return 1;
    if(((t1==NULL)&&(t2!=NULL))||((t1!=NULL)&&(t2==NULL)))
    return 0;
    if(t1->data!=t2->data)  
    return 0;  
    if((t1->left==NULL)&&(t2->left==NULL))
    return isomorphic(t1->right,t2->right);
    if(((t1->left!=NULL)&&(t2->left!=NULL))&&((t1->left->data)==(t2->left->data)))
    return (isomorphic(t1->left,t2->left)&&isomorphic(t1->right,t2->right));
    else
    return (isomorphic(t1->left,t2->right)&&isomorphic(t1->right,t2->left));    

    
    
}
int main()
{
    
     mytree *root = add(1);
  root->left        = add(2);
  root->right       = add(3);
  root->right->left  = add(4);
  root->right->right = add(5);
 
   mytree *root1 = add(1);
  root1->left        = add(2);
  root1->right       = add(3);
  root1->left->left  = add(4);
  root1->left->right = add(5);
  cout<<isomorphic(root,root1);
  cout<<endl;
  cout<<isIsomorphic(root,root1);
  cout<<endl;
 //getchar();
 return 0;
}
