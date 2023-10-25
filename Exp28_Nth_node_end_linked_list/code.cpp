#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* findNthFromEnd(ListNode* head, int n) {
    if (!head || n <= 0) {
        return nullptr;
    }

    ListNode* first = head;
    ListNode* second = head;

    // Move the first pointer 'n' nodes ahead.
    for (int i = 0; i < n; i++) {
        if (first) {
            first = first->next;
        } else {
            // The list is shorter than 'n' nodes.
            return nullptr;
        }
    }

    // Move both pointers until the first one reaches the end.
    while (first) {
        first = first->next;
        second = second->next;
    }

    return second;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2; // Find the 2nd node from the end.

    ListNode* nthNode = findNthFromEnd(head, n);

    if (nthNode) {
        cout << "The " << n << "th node from the end is: " << nthNode->val << endl;
    } else {
        cout << "Invalid input or the node doesn't exist." << endl;
    }

    // Clean up memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
