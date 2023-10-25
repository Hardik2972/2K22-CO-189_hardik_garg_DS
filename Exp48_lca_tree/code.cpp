#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) return nullptr;
    
    // If either p or q is found at the current node, return the current node.
    if (root == p || root == q) {
        return root;
    }

    // Recursively search for p and q in the left and right subtrees.
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    // If both p and q are found in the left and right subtrees, the current node is the LCA.
    if (left && right) {
        return root;
    }

    // If only one of p or q is found, return that node.
    if (left) {
        return left;
    }

    if (right) {
        return right;
    }

    // If neither p nor q is found, return nullptr.
    return nullptr;
}

int main() {
    // Construct a simple binary tree for testing
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* p = root->left;
    TreeNode* q = root->right;

    TreeNode* lca = lowestCommonAncestor(root, p, q);

    if (lca) {
        std::cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " << lca->val << std::endl;
    } else {
        std::cout << "Lowest Common Ancestor not found." << std::endl;
    }

    return 0;
}
