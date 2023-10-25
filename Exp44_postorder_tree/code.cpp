#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

void inorderTraversal(TreeNode* root) {
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    
    inorderTraversal(root->right);
    std::cout << root->data << " ";
}

int main() {
    // Construct a sample binary tree for testing
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::cout << "Postorder Traversal: ";
    inorderTraversal(root);
    std::cout << std::endl;

    return 0;
}
