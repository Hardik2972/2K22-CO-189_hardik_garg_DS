#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    string value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(string val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to create a binary expression tree from a postfix expression.
TreeNode* buildExpressionTree(string postfix) {
    stack<TreeNode*> s;
    for (char c : postfix) {
        if (isalnum(c)) {
            string operand = "";
            operand += c;
            s.push(new TreeNode(operand));
        } else {
            TreeNode* operand2 = s.top();
            s.pop();
            TreeNode* operand1 = s.top();
            s.pop();
            s.push(new TreeNode(string(1, c)));
            s.top()->left = operand1;
            s.top()->right = operand2;
        }
    }
    return s.top();
}

// Function to evaluate a binary expression tree.
int evaluateExpressionTree(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return stoi(root->value);
    }
    int left = evaluateExpressionTree(root->left);
    int right = evaluateExpressionTree(root->right);
    if (root->value == "+") {
        return left + right;
    } else if (root->value == "-") {
        return left - right;
    } else if (root->value == "*") {
        return left * right;
    } else if (root->value == "/") {
        return left / right;
    } else {
        return 0;
    }
}

int main() {
    string postfixExpression = "34*2+";
    TreeNode* root = buildExpressionTree(postfixExpression);

    cout << "Postfix Expression: " << postfixExpression << endl;
    cout << "Infix Expression: " << root->value << endl;

    int result = evaluateExpressionTree(root);
    cout << "Result of the expression: " << result << endl;

    return 0;
}