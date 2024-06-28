//diameter of binary tree
#include <iostream>
#include <algorithm>
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

int height(Node* root, int& ans){
    if(root==nullptr){
        return 0;
    }
    int left_height = height(root->left, ans);
    int right_height = height(root->right, ans);
    ans = max(ans, 1+left_height+right_height);
    return 1+max(left_height, right_height);
    }

int diameter(Node* root){
    if(root==nullptr){
        return 0;
    }
    int ans = INT_MIN;
    int height_of_tree = height(root, ans);
    return ans;
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
    cout<<"Diameter of the tree is: "<<diameter(root);
    return 0;
}

