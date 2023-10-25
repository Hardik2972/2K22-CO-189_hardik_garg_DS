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

    // Function to delete a value from the BST
    void deleteNode(int value) {
        root = deleteNodeRecursive(root, value);
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

    // Function to delete a value recursively
    Node* deleteNodeRecursive(Node* current, int value) {
        if (current == nullptr) {
            return current;
        }

        if (value < current->data) {
            current->left = deleteNodeRecursive(current->left, value);
        } else if (value > current->data) {
            current->right = deleteNodeRecursive(current->right, value);
        } else {
            // Node with only one child or no child
            if (current->left == nullptr) {
                Node* temp = current->right;
                delete current;
                return temp;
            } else if (current->right == nullptr) {
                Node* temp = current->left;
                delete current;
                return temp;
            }

            // Node with two children: Get the in-order successor (smallest in the right subtree)
            Node* temp = findMin(current->right);

            // Copy the in-order successor's data to this node
            current->data = temp->data;

            // Delete the in-order successor
            current->right = deleteNodeRecursive(current->right, temp->data);
        }

        return current;
    }

    // Function to find the minimum value node in the BST
    Node* findMin(Node* node) {
        Node* current = node;
        while (current->left != nullptr) {
            current = current->left;
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

    std::cout << "BST before deletion: ";
    bst.printInOrder();
    std::cout << std::endl;

    // Delete a node from the BST
    bst.deleteNode(10);

    std::cout << "BST after deletion: ";
    bst.printInOrder();
    std::cout << std::endl;

    return 0;
}
