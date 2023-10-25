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

    void insertAtBeginning(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
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

    myList.insertAtBeginning(5);
    myList.insertAtBeginning(10);
    myList.insertAtBeginning(15);

    cout << "Linked List after insertions: ";
    myList.display();

    myList.deleteFromBeginning();
    cout << "Linked List after deleting from the beginning: ";
    myList.display();

    return 0;
}