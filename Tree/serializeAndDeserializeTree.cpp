#include<iostream>
#include<fstream>
using namespace std;
class node
{
public:
  node(int v=-1,node*l=NULL,node*r=NULL):value(v),left(l),right(r){}
  int value;
  node*left;
  node*right;
};
void serialize(FILE* fptr, node* root)
{
  if(!root)
  {
    fprintf(fptr,"-1 ");//-1 is delimiter
  }
  else
  {
    fprintf(fptr,"%d ",root->value);
    serialize(fptr,root->left);
    serialize(fptr,root->right);
  }
}
node* deserialize(FILE* fptr)
{
  int token;
  bool isNumber;
  fscanf(fptr,"%d",&token);
  if( token != -1)
  {
    cout<<token<<" ";
    node *p = new node(token);
    p->left = deserialize(fptr);
    p->right = deserialize(fptr);
    return p;
  }
  return NULL;
}
void postOrder(node* root)
{
  if(root)
  {
    cout<<root->value<<" "<<endl;
    postOrder(root->left);
    postOrder(root->right);
  }
}
int main()
{
  FILE *fptr = fopen("serializedtree","w");
  
  node* root = new node(30);
  root->left = new node(10);
  root->right = new node (20);
  root->left->left = new node(50);
  root->right->left = new node(45);
  root->right->right=new node(35);
  
  serialize(fptr,root);
  fclose(fptr);
  
  FILE *fptr1 = fopen("serializedtree","r");
  node* root1 = deserialize(fptr1);
  postOrder( root1);  
  
  
}