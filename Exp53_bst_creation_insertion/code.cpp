#include <iostream>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    BinarySearchTree() : root(nullptr) {}

    // Function to insert a value into the BST
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // Function to insert a value recursively
    Node* insertRecursive(Node* current, int value) {
        if (current == nullptr) {
            return new Node(value);
        }

        if (value < current->data) {
            current->left = insertRecursive(current->left, value);
        } else if (value > current->data) {
            current->right = insertRecursive(current->right, value);
        }

        return current;
    }

    // Function to perform an in-order traversal of the BST
    void inOrderTraversal(Node* node) {
        if (node == nullptr) {
            return;
        }

        inOrderTraversal(node->left);
        std::cout << node->data << " ";
        inOrderTraversal(node->right);
    }

    // Function to print the in-order traversal of the BST
    void printInOrder() {
        inOrderTraversal(root);
    }

private:
    Node* root;
};

int main() {
    BinarySearchTree bst;

    // Insert values into the BST
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(12);
    bst.insert(18);

    // Perform an in-order traversal to print the BST
    std::cout << "In-order traversal of the BST: ";
    bst.printInOrder();
    std::cout << std::endl;

    return 0;
}
