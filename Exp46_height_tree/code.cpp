#include <iostream>
#include <algorithm>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;

    int lheight = 1 + maxDepth(root->left);
    int rheight = 1 + maxDepth(root->right);

    return std::max(lheight, rheight);
}

int main() {
    // Construct a sample binary tree for testing
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int treeDepth = maxDepth(root);

    std::cout << "Maximum depth of the binary tree is: " << treeDepth << std::endl;

    return 0;
}
