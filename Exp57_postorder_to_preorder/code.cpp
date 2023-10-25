#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void constructBSTFromPostorder(TreeNode*& root, int val) {
    if (!root) {
        root = new TreeNode(val);
    } else if (val > root->val) {
        constructBSTFromPostorder(root->right, val);
    } else {
        constructBSTFromPostorder(root->left, val);
    }
}

void preorderTraversal(TreeNode* root, vector<int>& preorder) {
    if (root) {
        preorder.push_back(root->val);
        preorderTraversal(root->left, preorder);
        preorderTraversal(root->right, preorder);
    }
}

vector<int> postorderToPreorder(vector<int>& postorder) {
    TreeNode* root = nullptr;
    for (int i = postorder.size() - 1; i >= 0; i--) {
        constructBSTFromPostorder(root, postorder[i]);
    }

    vector<int> preorder;
    preorderTraversal(root, preorder);

    return preorder;
}

int main() {
    vector<int> postorder = {1, 7, 5, 9, 12, 10, 8};
    vector<int> preorder = postorderToPreorder(postorder);

    cout << "Postorder: ";
    for (int val : postorder) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Preorder: ";
    for (int val : preorder) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
