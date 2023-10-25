#include <iostream>

using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode(int x) : data(x), next(nullptr) {}
};

ListNode* detectCycle(ListNode* head) {
    if (!head) {
        return nullptr; // No cycle in an empty list.
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return slow; // Cycle detected, return the meeting point.
        }
    }

    return nullptr; // No cycle detected.
}

void removeCycle(ListNode* head, ListNode* cycleNode) {
    if (!head || !cycleNode) {
        return;
    }

    ListNode* ptr1 = head;
    ListNode* ptr2 = cycleNode;

    while (ptr1->next != ptr2->next) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    // Remove the cycle
    ptr2->next = nullptr;
}

void displayList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Create a cycle by connecting the last node to the second node
    head->next->next->next->next->next = head->next;

    ListNode* cycleNode = detectCycle(head);

    if (cycleNode) {
        cout << "Cycle detected at node with value " << cycleNode->data << endl;
        removeCycle(head, cycleNode);
        cout << "Cycle removed." << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    cout << "Linked List after removing the cycle:" << endl;
    displayList(head);

    // Clean up memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}