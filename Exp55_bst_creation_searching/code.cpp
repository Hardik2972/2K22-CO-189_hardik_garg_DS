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

    // Function to search for a value in the BST
    bool search(int value) {
        return searchRecursive(root, value);
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

    // Function to search for a value recursively
    bool searchRecursive(Node* current, int value) {
        if (current == nullptr) {
            return false;
        }

        if (value == current->data) {
            return true;
        } else if (value < current->data) {
            return searchRecursive(current->left, value);
        } else {
            return searchRecursive(current->right, value);
        }
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

    std::cout << "BST: ";
    bst.printInOrder();
    std::cout << std::endl;

    // Search for a value in the BST
    int searchValue = 12;
    if (bst.search(searchValue)) {
        std::cout << "Value " << searchValue << " found in the BST." << std::endl;
    } else {
        std::cout << "Value " << searchValue << " not found in the BST." << std::endl;
    }

    return 0;
}
