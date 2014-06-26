// A function that fills count array with count of nodes at every
// level of given binary tree
void getMaxWidthRecur(struct node *root, int count[], int level)
{
  if(root)
  {
    count[level]++;
    getMaxWidthRecur(root->left, count, level+1);
    getMaxWidthRecur(root->right, count, level+1);
  }
} 
/* Function to get the maximum width of a binary tree*/
int getMaxWidth(struct node* root)
{
  int width;
  int h = height(root); 
  // Create an array that will store count of nodes at each level
  int *count = (int *)calloc(sizeof(int), h);
 
  int level = 0;
 
  // Fill the count array using preorder traversal
  getMaxWidthRecur(root, count, level);
 
  // Return the maximum value from count array
  return getMax(count, h);
} 
