/**
This is the header file containing the declaration of primary functions related to Binary Tree

@name   Tree.h
**/

struct Node
{
  int data;
  Node *left;
  Node *right;
};


Node *  BuildBinaryTree(int *arr,int p,int q);
int     Check(Node *node, int m, int c);
void    Read(Node *node);
int     BTIterativeHeight(Node *root);
int     BTRecursiveHeight(Node *node);
Node *  Search(Node *root,int i);
