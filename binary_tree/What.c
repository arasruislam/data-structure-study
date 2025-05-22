#include <stdio.h>
#include <stdlib.h>

struct node
{
  int item;

  struct node *left;
  struct node *right;
};

// inorder
void inorderTraverse(struct node *root)
{
  if (root == NULL)
    return;

  inorderTraverse(root->left);
  printf("%d ", root->item);
  inorderTraverse(root->right);
}
// preorder
void preorderTraverse(struct node *root)
{
  if (root == NULL)
    return;

  printf("%d ", root->item);
  preorderTraverse(root->left);
  preorderTraverse(root->right);
}
// postorder
void postorderTraverse(struct node *root)
{
  if (root == NULL)
    return;

  postorderTraverse(root->left);
  postorderTraverse(root->right);
  printf("%d ", root->item);
}

// create new node
struct node *createNode(int item)
{
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->item = item;
  temp->left = temp->right = NULL;
  return temp;
};

// insert left
void insertLeft(struct node *root, int item)
{
  root->left = createNode(item);
}

// insert right
void insertRight(struct node *root, int item)
{
  root->right = createNode(item);
}

main()
{
  struct node *root = createNode(1);
  insertLeft(root, 2);
  insertRight(root, 3);
  insertLeft(root->left, 4);

  printf("Inorder: ");
  inorderTraverse(root);
  printf("\n");
  printf("Preorder: ");
  preorderTraverse(root);
  printf("\n");
  printf("Postorder: ");
  postorderTraverse(root);
  printf("\n");

  return 0;
}