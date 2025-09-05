#include <iostream>
#include <queue>
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

void levelOrder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    q.push(nullptr); // marker for level change

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == nullptr)
        {
            cout << "NULL" << " ";
            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            cout << temp->value << " ";
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    node *root = new node(1);
    root->left = new node(4);
    root->right = new node(3);
    root->left->left = new node(6);
    root->left->right = new node(8);
    root->left->right->left = new node(11);
    root->right->left = new node(5);
    root->right->right = new node(2);
    root->right->left->right = new node(14);
    levelOrder(root);
    return 0;
}