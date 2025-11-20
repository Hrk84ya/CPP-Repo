//Preorder, Postorder and Inorder iteratively in Binary Tree
#include <iostream>
#include <stack>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};

node *newNode(int data)
{
    node *temp = new node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void preorder(node *root)
{
    stack<node *> s;
    s.push(root);
    while (!s.empty())
    {
        node *temp = s.top();
        s.pop();
        cout << temp->data << " ";
        if (temp->right)
            s.push(temp->right);
        if (temp->left)
            s.push(temp->left);
    }
}

void inorder(node *root)
{
    stack<node *> s;
    node *temp = root;
    while (temp != NULL || !s.empty())
    {
        while (temp != NULL)
        {
            s.push(temp);
            temp = temp->left;
        }
        temp = s.top();
        s.pop();
        cout << temp->data << " ";
        temp = temp->right;
    }
}

void postorder(node *root)
{
    stack<node *> s1, s2;
    s1.push(root);
    while (!s1.empty())
    {
        node *temp = s1.top();
        s1.pop();
        s2.push(temp);
        if (temp->left)
            s1.push(temp->left);
        if (temp->right)
            s1.push(temp->right);
    }
    while (!s2.empty())
    {
        node *temp = s2.top();
        s2.pop();
        cout << temp->data << " ";
    }
}

int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout << "Preorder: ";
    preorder(root);
    cout << "\nInorder: ";
    inorder(root);
    cout << "\nPostorder: ";
    postorder(root);
    return 0;
}
