#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtPosition(int value, int position) {
        if (position < 0) {
            cout << "Invalid position. Cannot insert." << endl;
            return;
        }

        Node* newNode = new Node;
        newNode->data = value;

        if (position == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            int currentPosition = 0;

            while (currentPosition < position - 1 && current != nullptr) {
                current = current->next;
                currentPosition++;
            }

            if (current == nullptr) {
                cout << "Invalid position. Cannot insert." << endl;
                delete newNode;
                return;
            }

            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void deleteAtPosition(int position) {
        if (position < 0 || head == nullptr) {
            cout << "Invalid position or list is empty. Nothing to delete." << endl;
            return;
        }

        if (position == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* current = head;
            int currentPosition = 0;

            while (currentPosition < position - 1 && current->next != nullptr) {
                current = current->next;
                currentPosition++;
            }

            if (current->next == nullptr) {
                cout << "Invalid position. Cannot delete." << endl;
                return;
            }

            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

private:
    Node* head;
};

int main() {
    LinkedList myList;

    myList.insertAtPosition(5, 0);
    myList.insertAtPosition(10, 1);
    myList.insertAtPosition(15, 1);

    cout << "Linked List after insertions: ";
    myList.display();

    myList.deleteAtPosition(1);
    cout << "Linked List after deleting at position 1: ";
    myList.display();

    return 0;
}