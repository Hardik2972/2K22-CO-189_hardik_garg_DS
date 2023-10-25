#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    int height;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr), height(1) {}
};

int getHeight(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

int getBalanceFactor(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

void updateHeight(TreeNode* node) {
    if (node != nullptr) {
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }
}

TreeNode* rightRotate(TreeNode* y) {
    TreeNode* x = y->left;
    TreeNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

TreeNode* leftRotate(TreeNode* x) {
    TreeNode* y = x->right;
    TreeNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

TreeNode* balance(TreeNode* node, int value) {
    int balanceFactor = getBalanceFactor(node);

    if (balanceFactor > 1 && value < node->left->val) {
        return rightRotate(node);
    }
    if (balanceFactor < -1 && value > node->right->val) {
        return leftRotate(node);
    }
    if (balanceFactor > 1 && value > node->left->val) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balanceFactor < -1 && value < node->right->val) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }

    if (value < root->val) {
        root->left = insert(root->left, value);
    } else if (value > root->val) {
        root->right = insert(root->right, value);
    } else {
        return root;
    }

    updateHeight(root);

    return balance(root, value);
}

void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    TreeNode* root = nullptr;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    inorderTraversal(root);
    cout << endl;

    return 0;
}