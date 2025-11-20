//Lowest Common ancestor code 

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data){
    Node* node = new Node();
    node->data = data;
    node->left=nullptr;
    node->right=nullptr;
    return node;
}

Node* LCA(Node* root, int n1, int n2){
    if(root==nullptr){
        return nullptr;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }
    Node* left = LCA(root->left, n1, n2);
    Node* right = LCA(root->right, n1, n2);
    if(left!=nullptr && right!=nullptr){
        return root;
    }
    if(left==nullptr && right==nullptr){
        return nullptr;
    }
    return left!=nullptr?left:right;
}

int main(){
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(6);
    root->right->right= newNode(7);
    root->right->right->right= newNode(8);
    root->right->right->right->left= newNode(9);
    root->right->right->right->right= newNode(10);
    root->right->right->right->right->right= newNode(11);
    Node* lca = LCA(root, 6, 11);
    cout<<"Lowest Common Ancestor is: "<<lca->data;
    return 0;
}