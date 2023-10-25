#include <iostream>
#include <algorithm>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int d(TreeNode* root, int& diameter) {
    if (root == nullptr) return 0;
    
    int lheight = d(root->left, diameter);
    int rheight = d(root->right, diameter);

    diameter = std::max(diameter, lheight + rheight);

    return std::max(lheight, rheight) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    d(root, diameter);
    return diameter;
}

int main() {
    // Construct a sample binary tree for testing
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int treeDiameter = diameterOfBinaryTree(root);

    std::cout << "Diameter of the binary tree is: " << treeDiameter << std::endl;

    return 0;
}
