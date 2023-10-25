#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() : head(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node{value, nullptr, nullptr};
        if (!head) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void deleteNode(int value) {
        if (!head) {
            cout << "Doubly Linked List is empty. Nothing to delete." << endl;
            return;
        }

        Node* current = head;
        while (current) {
            if (current->data == value) {
                if (current->prev) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }
                if (current->next) {
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
        cout << "Value not found. Nothing to delete." << endl;
    }

    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dlist;

    dlist.insert(1);
    dlist.insert(2);
    dlist.insert(3);
    dlist.insert(4);

    cout << "Doubly Linked List: ";
    dlist.display();

    dlist.deleteNode(2);
    cout << "After deleting 2: ";
    dlist.display();

    dlist.deleteNode(5); // Value not found, no deletion.
    cout << "After trying to delete 5: ";
    dlist.display();

    return 0;
}