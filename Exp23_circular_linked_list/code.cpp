#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() : head(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node{value, nullptr};
        if (!head) {
            head = newNode;
            head->next = head; // Create a circular structure.
        } else {
            newNode->next = head;
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void deleteNode(int value) {
        if (!head) {
            cout << "Circular Linked List is empty. Nothing to delete." << endl;
            return;
        }

        Node* current = head;
        Node* prev = nullptr;
        do {
            if (current->data == value) {
                if (current == head) {
                    head = head->next;
                }
                prev->next = current->next;
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        } while (current != head);
        cout << "Value not found. Nothing to delete." << endl;
    }

    void display() {
        Node* current = head;
        if (!current) {
            cout << "Circular Linked List is empty." << endl;
            return;
        }
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList clist;

    clist.insert(1);
    clist.insert(2);
    clist.insert(3);
    clist.insert(4);

    cout << "Circular Linked List: ";
    clist.display();

    clist.deleteNode(2);
    cout << "After deleting 2: ";
    clist.display();

    clist.deleteNode(5); // Value not found, no deletion.
    cout << "After trying to delete 5: ";
    clist.display();

    return 0;
}