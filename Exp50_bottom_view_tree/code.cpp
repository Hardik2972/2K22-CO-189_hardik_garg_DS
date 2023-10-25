#include <iostream>
#include <map>
#include <queue>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        root = insertRecursive(root, value);
    }

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

    // Function to print the bottom view of the binary tree
    void bottomView() {
        if (root == nullptr)
            return;

        std::map<int, int> bottomViewMap;
        std::queue<std::pair<Node*, int>> q;

        q.push({root, 0});

        while (!q.empty()) {
            Node* current = q.front().first;
            int hd = q.front().second;
            q.pop();

            bottomViewMap[hd] = current->data;

            if (current->left) {
                q.push({current->left, hd - 1});
            }
            if (current->right) {
                q.push({current->right, hd + 1});
            }
        }

        for (const auto& pair : bottomViewMap) {
            std::cout << pair.second << " ";
        }
        std::cout << std::endl;
    }

private:
    Node* root;
};

int main() {
    BinaryTree tree;

    // Insert some values into the binary tree
    tree.insert(20);
    tree.insert(8);
    tree.insert(22);
    tree.insert(5);
    tree.insert(3);
    tree.insert(25);
    tree.insert(10);
    tree.insert(14);

    // Print the bottom view of the binary tree
    tree.bottomView();

    return 0;
}
