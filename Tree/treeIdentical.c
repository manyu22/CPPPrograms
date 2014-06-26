#include<iostream>
using namespace std;

int identical(mytree *root1,mytree *root2)
{
        if(root1==NULL&&root2==NULL)
        return 1;
        else
        if(root1!=NULL && root2!=NULL)
        return((root1->data==root2->data) &&  identical(root1->left,root2->left) &&identical(root1->right,root2->right));    
        else
        return 0;
}
