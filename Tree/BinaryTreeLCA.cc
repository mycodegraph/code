#include<iostream>
#include<stack>

using namespace std;
#define END(node) while(node->right != NULL) node = node->right;


struct Node
{
    int key;
    Node *left, *right, *next;
    Node(int _data):key(_data),next(NULL),left(NULL),right(NULL){}
};

Node *TreeToDLL(Node *root)
{
    if(root == NULL) return NULL;

    Node *left = TreeToDLL(root->left);
    Node *right = TreeToDLL(root->right);

    Node *dll=NULL;
    if(left != NULL)
    {
        dll = left;
        END(left);
        left->right = root;
        root->left = left;
    }
    else
    {
        dll = root;
    }

    root->right = right;
    if(right != NULL) right->left = root;

    return dll;

}
Node *LCAUtil(Node *root, int key1, int key2, bool &first_node, bool & sec_node)
{
    if(root == NULL) return NULL;

    if(key1 == root->key)
    {
        first_node = true;
        return root;
    }
    if(key2 == root->key)
    {
        sec_node = true;
        return root;
    }

    Node * left_lca = LCAUtil(root->left, key1, key2, first_node, sec_node);
    Node * right_lca = LCAUtil(root->right, key1, key2, first_node, sec_node);

    if(left_lca != NULL && right_lca != NULL)
        return root;

    return (left_lca != NULL)? left_lca: right_lca;
}

bool findNode(Node *root, int key)
{
    if(root == NULL)
        return false;

    return (key == root->key || findNode(root->left, key) || findNode(root->right, key));
}

Node *LCA(Node *root, int key1, int key2)
{
    if(root == NULL) return NULL;
    bool first_node=false, sec_node=false;

    Node *lca = LCAUtil(root, key1, key2, first_node, sec_node);

 /*   if(lca != NULL && first_node == true && sec_node == true)
        return lca;*/

    if(lca != NULL && (first_node == true || findNode(lca, key1)) && (sec_node == true || findNode(lca, key2)))
        return lca;

    return NULL;
}
int findLevel(Node * root, int key, int level)
{
    if(root == NULL)
        return 0;

    if(key == root->key)
        return level;

    int left_level = findLevel(root->left, key, level+1);
    int right_level = findLevel(root->right, key, level+1);

    return max(left_level, right_level);
}

int findDistance(Node * root, int key1, int key2)
{
    if(root == NULL)
        return 0;

    Node * lca = LCA(root, key1, key2);
    if(lca == NULL)
        return 0;

    int key1_level = findLevel(lca, key1, 0);
    int key2_level = findLevel(lca, key2, 0);

    return key1_level + key2_level;
}
Node * GetNode(Node *root, int key)
{
    if(root == NULL)
        return NULL;

    if(key == root->key)
        return root;
    Node * left = GetNode(root->left, key);
    Node *right = GetNode(root->right, key);

    return (left != NULL)?left:right;
}
void PrintKthNode(Node *root, int level, int k)
{
    if(root == NULL)
        return;

    if(level == k)
    {
        cout<<root->key<<" ";
        return;
    }

    PrintKthNode(root->left, level+1,k);
    PrintKthNode(root->right, level+1,k);

    return;
}

int PrintKDistanceNodesUtil(Node *root, Node *refNode, int k)
{
    if(root == NULL)
        return -1;

    if(root == refNode)
    {
        PrintKthNode(root, 0, k);
        return k-1;
    }

    int left_k = PrintKDistanceNodesUtil(root->left, refNode, k);
    int right_k = PrintKDistanceNodesUtil(root->right, refNode, k);

    if(left_k >= 0)
    {
        if(left_k == 0)
            cout<<root->key<<" ";
        PrintKthNode(root->right, 0, left_k-1);
        return left_k-1;
    }
    else if(right_k >= 0)
    {
        if(right_k == 0)
            cout<<root->key<<" ";

        PrintKthNode(root->left, 0, right_k-1);
        return right_k-1;
    }

    return -1;
}

bool PrintKDistanceNodes(Node *root, int key, int k)
{
    if(root == NULL)
        return false;

    Node * refNode = GetNode(root, key);
    if(refNode == NULL)
        return false;

    return PrintKDistanceNodesUtil(root, refNode, k);
}

int main()
{
    Node *root=new Node(10);

    root->left = new Node(5);
    root->right = new Node(15);

    root->left->left = new Node(4);
    root->left->right = new Node(8);

    root->right->left = new Node(12);
    root->right->right = new Node(20);


    //root = TreeToDLL(root);

    //cout<<LCA(root, 5,5)->key<<endl;

    //cout<<findDistance(root, 5, 155);
    
    PrintKDistanceNodes(root, 12, 4);

}
