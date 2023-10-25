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

    bool search(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
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

    cout << "Linked List: ";
    myList.display();

    int searchValue = 10;
    if (myList.search(searchValue)) {
        cout << "Value " << searchValue << " is found in the list." << endl;
    } else {
        cout << "Value " << searchValue << " is not found in the list." << endl;
    }

    return 0;
}