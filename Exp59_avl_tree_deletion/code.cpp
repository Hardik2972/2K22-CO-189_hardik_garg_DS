#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    int height;
    TreeNode(int value) : val(value), left(NULL), right(NULL), height(1) {}
};

int getHeight(TreeNode* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

int getBalanceFactor(TreeNode* node) {
    if (node == NULL) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

void updateHeight(TreeNode* node) {
    if (node != NULL) {
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
    if (root == NULL) {
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

TreeNode* getMinValueNode(TreeNode* node) {
    TreeNode* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

TreeNode* deleteNode(TreeNode* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->val) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->val) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL || root->right == NULL) {
            TreeNode* temp = (root->left) ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            delete temp;
        } else {
            TreeNode* temp = getMinValueNode(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
    }

    if (root == NULL) {
        return root;
    }

    updateHeight(root);

    return balance(root, value);
}

void inorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    TreeNode* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Inorder traversal of the AVL tree (Before deletion): ";
    inorderTraversal(root);
    cout << endl;

    int valueToDelete = 30;
    root = deleteNode(root, valueToDelete);

    cout << "Inorder traversal of the AVL tree (After deletion): ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}