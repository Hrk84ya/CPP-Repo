#include <iostream>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

unordered_map<TreeNode*, int> dp;
int rob(TreeNode* root) {
    if (root == NULL) return 0;
    if (dp.find(root) != dp.end()) return dp[root];
    int val = 0;
    if (root->left != NULL) {
        val += rob(root->left->left) + rob(root->left->right);
    }
    if (root->right != NULL) {
        val += rob(root->right->left) + rob(root->right->right);
    }
    dp[root] = max(val + root->val, rob(root->left) + rob(root->right));
    return dp[root];
}

int main() {
    TreeNode* root = new TreeNode(3);
    //Example-1:
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->left->right = new TreeNode(3);
    // root->right->right = new TreeNode(1);

    //Example-2:
    root->left=new TreeNode(4);
    root->right=new TreeNode(5);
    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(3);
    root->right->right=new TreeNode(1);
    cout <<"Maximum amount is: "<< rob(root) << endl;
    return 0;
}
