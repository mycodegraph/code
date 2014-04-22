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

void CreateZigZagTree(Node *root)
{
    if(root == NULL) return;

    stack<Node *> Stack1,Stack2;
    Node *dummy=new Node('\0');
    Node *tail = dummy,*curr;

    Stack1.push(root);

    while(!Stack1.empty() || !Stack2.empty())
    {
        while(!Stack1.empty())
        {
            curr = Stack1.top();
            Stack1.pop();
            tail->next = curr;
            tail = tail->next;

            if(curr->left != NULL)
                Stack2.push(curr->left);

            if(curr->right != NULL)
                Stack2.push(curr->right);
        }

        while(!Stack2.empty())
        {
            curr = Stack2.top();
            Stack2.pop();
            tail->next = curr;
            tail = tail->next;

            if(curr->right != NULL)
                Stack1.push(curr->right);

            if(curr->left != NULL)
                Stack1.push(curr->left);
        }
    }
    delete(dummy);
}

void PrintZigZagTree(Node *root)
{
    if(root == NULL) return;

    Node * curr = root;
    while(curr != NULL)
    {
        cout<<curr->key<<" ";
        curr=curr->next;
    }
}


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

int main()
{
    Node *root=new Node(10);

    root->left = new Node(5);
    root->right = new Node(15);

    root->left->left = new Node(4);
    root->left->right = new Node(8);

    root->right->left = new Node(12);
    root->right->right = new Node(20);

    CreateZigZagTree(root);
    root = TreeToDLL(root);

    PrintZigZagTree(root);

}
