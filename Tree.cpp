#include<iostream>
#include<algorithm>

using namespace std;
#define MAX 100
#define rep(i,m,n) for(int i=m;i<n;i++)

struct Node
{
  int data;
  Node *left;
  Node *right;
};

/**
 * Node * 
 * BuildBinaryTree(int *arr,int p,int q) 
 * 
 * @brief   This function recursively create Binary Tree from an array of integers
 * @arg     This function takes a pointer to an integer array, array start index and array end index
 * @return  This function returns pointer to Tree created by function, which is of type Node
 * 
 **/
Node * BuildBinaryTree(int *arr,int p,int q)
{
    Node *temp = new Node();
    if(p < q)
    {
        int mid = p + (q-p)/2;
        temp->data = arr[mid];
        
        //If mid is equal to p then left child of p is NULL
        if(mid != p)
            temp->left = BuildBinaryTree(arr,p,mid-1);
        else
            temp->left = NULL;

        temp->right = BuildBinaryTree(arr,mid+1,q);
        return temp;
    }
    else
    {
        temp->data = arr[p];
        temp->left = NULL;
        temp->right = NULL;
        return  temp;
    }
}

/**
 * int
 * Check(Node *node, int m, int c)
 * 
 * @brief   This function checks whether supplied binary tree is BST or not
 * @arg     Ths function takes pointer to root node of type Node, comparison int and checker int
 * @return  This function returns -1 if given tree is not BST 
**/
int Check(Node *node, int m, int c)
{
    if(c == -1)
        return -1;
    if(node != NULL)
    {
        m = Check(node->left, m, 0);
        if(m <= node->i)
        {
            m = node->data;
        }
        else
        {
            c = -1;
            return -1;
        }
        m = Check(node->right, m, 0);
        if(node->data <= m)
        {
            return m;
        }
        else
        {
            c = -1;
            return c;
        }
    }
    else
        return m;

}

/**
 *void 
 *Read(Node *node)
 * 
 * @brief   This function prints inorder traversal of supplied binary tree root pointer
 * @arg     This function takes a pounetr of Node type.
 * @return  This function returns nothing.
**/
void Read(Node *node)
{
    if(node != NULL)
    {
        Read(node->lt);
        cout<< node->i<<" ";
        Read(node->rt);
    }
}


/**
 * int
 * BTIterativeHeight(Node *root)
 * @brief      This is an iterative procedure to calculate height of Binary Tree
 * @arg        A pointer of Node type
 * @return     An integral height of a Binary Tree
**/

int
BTIterativeHeight(Node *root)
{
    if(root == NULL) return 0;  //If root is NULL then height is ZERO

    Node *temp;
    int height=0,lcount=0,nextlcount=0;
    queue<Node *> q;
    q.push(root);
    lcount++;

    while(!q.empty())
    {
        while(lcount != 0)
        {
            temp = q.front();
            q.pop();
            lcount--;
            if(temp->lt != NULL)
            {
                q.push(temp->lt);
                nextlcount++;
            }
            if(temp->rt != NULL)
            {
                q.push(temp->rt);
                nextlcount++;
            }
        }
        if(lcount==0) height++;
        lcount=nextlcount;
        nextlcount=0;
    }
    return height;
}


/**
 * int
 *  BTRecursiveHeight(Node *root)
 * @brief      This is a recursive procedure to calculate height of Binary Tree
 * @arg        A pointer of Node type
 * @return     An integral height of a Binary Tree
**/

int BTRecursiveHeight(Node *node)
{
    if(node == NULL) return 0;
    else { return max(BTRecursiveHeight(node->lt)+1,BTRecursiveHeight(node->rt)+1); }

}

/**
 * Node *
 * Search(Node *root,int i)
 * 
 * @brief     This function searches for Node with particular value in a BST
 * @arg       This function takes root pointer node of type Node and integral value to serach for node in tree
 * @return    This function returns Node corresponding to value else returns NULL
**/
Node *Search(Node *root,int i)
{
    if(root == NULL) return NULL;

    if(root->data == i) return root;
    if(i < root->data)
        return Search(root->left,i);
    else
        return Search(root->right,i);

}

