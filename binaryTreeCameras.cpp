#include<iostream>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int res = 0;
    int minCameraCover(TreeNode* root) {
        return (dfs(root) < 1? 1 : 0) + res;
    }

    int dfs(TreeNode* root) {
        if (!root) return 2;
        int left = dfs(root->left), right = dfs(root->right);
        if (left == 0 || right == 0) {
            res++;
            return 1;
        }
        return left == 1 || right == 1? 2 : 0;
    }
};

int main() {
    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(0);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(0);
    root->left->right->left = new TreeNode(0);    
    root->left->right->right = new TreeNode(0);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(0);
    root->right->right->right = new TreeNode(0);
    root->right->right->right->left = new TreeNode(0);

    Solution sol;
    cout << "Cameras required: "<<sol.minCameraCover(root) << endl;
    return 0;
}