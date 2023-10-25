#include<iostream>
using namespace std;
class TreeNode{

    public:
        int data;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int data){
        this->data=data;
        left = NULL;
        right = NULL;
       }
};

TreeNode* buildTree(TreeNode* root){
    int data;
    cin>>data;
    root = new TreeNode(data);
    if(data == -1) return NULL;
    cout<<"Enter the element in the left of the tree ";
    root->left = buildTree(root->left);
    cout<<"Enter the element in the right of the tree ";
    root->right = buildTree(root->right);
    return root;
}

int main(){
    TreeNode* root = NULL;
    root = buildTree(root);
    return 0;
}