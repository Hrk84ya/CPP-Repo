#include <iostream>
#include <queue>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    TreeNode* root;
    
    TreeNode* insert(TreeNode* node, int value) {
        if (!node) return new TreeNode(value);
        
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }
        return node;
    }
    
    TreeNode* search(TreeNode* node, int value) {
        if (!node || node->data == value) return node;
        
        if (value < node->data) {
            return search(node->left, value);
        }
        return search(node->right, value);
    }
    
    TreeNode* findMin(TreeNode* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }
    
    TreeNode* deleteNode(TreeNode* node, int value) {
        if (!node) return node;
        
        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        } else {
            if (!node->left) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            
            TreeNode* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }
    
    void inorder(TreeNode* node) {
        if (node) {
            inorder(node->left);
            std::cout << node->data << " ";
            inorder(node->right);
        }
    }
    
    void preorder(TreeNode* node) {
        if (node) {
            std::cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }
    
    void postorder(TreeNode* node) {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            std::cout << node->data << " ";
        }
    }
    
public:
    BST() : root(nullptr) {}
    
    void insert(int value) {
        root = insert(root, value);
    }
    
    bool search(int value) {
        return search(root, value) != nullptr;
    }
    
    void remove(int value) {
        root = deleteNode(root, value);
    }
    
    void printInorder() {
        std::cout << "Inorder: ";
        inorder(root);
        std::cout << "\n";
    }
    
    void printPreorder() {
        std::cout << "Preorder: ";
        preorder(root);
        std::cout << "\n";
    }
    
    void printPostorder() {
        std::cout << "Postorder: ";
        postorder(root);
        std::cout << "\n";
    }
    
    void printLevelOrder() {
        if (!root) return;
        
        std::queue<TreeNode*> q;
        q.push(root);
        
        std::cout << "Level order: ";
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            
            std::cout << current->data << " ";
            
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
        std::cout << "\n";
    }
};

int main() {
    BST bst;
    
    // Insert values
    std::cout << "Inserting: 50, 30, 70, 20, 40, 60, 80\n";
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    
    // Print traversals
    bst.printInorder();
    bst.printPreorder();
    bst.printPostorder();
    bst.printLevelOrder();
    
    // Search operations
    std::cout << "\nSearch 40: " << (bst.search(40) ? "Found" : "Not found") << "\n";
    std::cout << "Search 25: " << (bst.search(25) ? "Found" : "Not found") << "\n";
    
    // Delete operations
    std::cout << "\nDeleting 20 (leaf node):\n";
    bst.remove(20);
    bst.printInorder();
    
    std::cout << "\nDeleting 30 (node with two children):\n";
    bst.remove(30);
    bst.printInorder();
    
    std::cout << "\nDeleting 50 (root node):\n";
    bst.remove(50);
    bst.printInorder();
    
    return 0;
}