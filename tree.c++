#include <iostream>
using namespace std;

struct node
{
  int data;
  struct node *left;
  struct node *right;
};
struct node *insert(struct node *root, int val)
{
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = val;
  newnode->left = NULL;
  newnode->right = NULL;

  if (root == NULL) // root NULL means box containing nothing
  {
    return newnode;
  }
  else
  {
    if (root->data > val)
    {
      root->left = insert(root->left, val);
    }
    else if (root->data < val)
    {
      root->right = insert(root->right, val);
    }

    return root;
  }
}

void inorder(struct node *root)
{
  if (root != NULL)
  {
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
  }
}

struct node*tree_min(struct node*root){
  while (root->left!=NULL)  //root->left== NULL meanse box left child not present.
  {
    root=root->left;
  }
  return root;
}

              // *******OR********

struct node *tree_min(struct node *root)
{
  if (root->left == NULL)
  {
    return root;
  }
  else
  {
    return tree_min(root->left);
  }
}

struct node *tree_max(struct node *root)
{
  while (root->right != NULL)
  {
    root = root->right;
  }
  return root;
}

int main()
{
  struct node *root = NULL;
  root = insert(root, 45);
  root = insert(root, 48);
  root = insert(root, 10);
  root = insert(root, 5);
  root = insert(root, 40);
  root = insert(root, 20);

  inorder(root);
  cout << "\nminimum node of tree is: " << endl;

  struct node *temp = tree_min(root);
  cout << temp->data << endl;

  cout << "\nmaximum node of tree is: " << endl;
  struct node *ptr = tree_max(root);

  cout << ptr->data << endl;

  return 0;
}
