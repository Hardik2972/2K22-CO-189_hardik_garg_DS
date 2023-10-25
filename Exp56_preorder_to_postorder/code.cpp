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

void constructBSTFromPreorder(TreeNode*& root, int val) {
    if (!root) {
        root = new TreeNode(val);
    } else if (val < root->val) {
        constructBSTFromPreorder(root->left, val);
    } else {
        constructBSTFromPreorder(root->right, val);
    }
}

void postorderTraversal(TreeNode* root, vector<int>& postorder) {
    if (root) {
        postorderTraversal(root->left, postorder);
        postorderTraversal(root->right, postorder);
        postorder.push_back(root->val);
    }
}

vector<int> preorderToPostorder(vector<int>& preorder) {
    TreeNode* root = nullptr;
    for (int val : preorder) {
        constructBSTFromPreorder(root, val);
    }

    vector<int> postorder;
    postorderTraversal(root, postorder);

    return postorder;
}

int main() {
    vector<int> preorder = {8, 5, 1, 7, 10, 9, 12};
    vector<int> postorder = preorderToPostorder(preorder);

    cout << "Preorder: ";
    for (int val : preorder) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Postorder: ";
    for (int val : postorder) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
