#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

bool isPalindrome(ListNode* head) {
    if (!head || !head->next) {
        return true; // Empty or single-node list is a palindrome.
    }

    // Find the middle of the linked list.
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the linked list.
    ListNode* secondHalf = slow->next;
    slow->next = nullptr;

    // Compare the first and reversed second halves.
    ListNode* reversedSecondHalf = nullptr;
    while (secondHalf) {
        ListNode* temp = secondHalf->next;
        secondHalf->next = reversedSecondHalf;
        reversedSecondHalf = secondHalf;
        secondHalf = temp;
    }

    while (reversedSecondHalf) {
        if (head->val != reversedSecondHalf->val) {
            return false;
        }
        head = head->next;
        reversedSecondHalf = reversedSecondHalf->next;
    }

    return true;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    if (isPalindrome(head)) {
        cout << "Linked list is a palindrome." << endl;
    } else {
        cout << "Linked list is not a palindrome." << endl;
    }

    // Clean up memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}