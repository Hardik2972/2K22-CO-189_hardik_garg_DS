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

    void insert(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void reverse() {
        Node* current = head;
        Node* prev = nullptr;
        Node* nextNode = nullptr;

        while (current != nullptr) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        head = prev;
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

    myList.insert(5);
    myList.insert(10);
    myList.insert(15);

    cout << "Original Linked List: ";
    myList.display();

    myList.reverse();
    cout << "Reversed Linked List: ";
    myList.display();

    return 0;
}