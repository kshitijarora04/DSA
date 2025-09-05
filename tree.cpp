#include <iostream>
using namespace std;

class node
{
public:
    int value;
    node *left;
    node *right;

    node(int v)
    {
        value = v;
        left = NULL;
        right = NULL;
    }
};

void preorder(node *root)
{
    if (root != NULL)
    {
        cout << root->value << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    node *root = new node(10);
    root->left = new node(2);
    root->right = new node(10);
    root->right->left = new node(50);
    preorder(root);
    return 0;
}