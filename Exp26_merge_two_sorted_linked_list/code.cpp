#include <iostream>

using namespace std;

// Definition of the ListNode class
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to merge two sorted linked lists
ListNode* merge(ListNode*& head1, ListNode*& head2) {
    ListNode* temp = head1;
    ListNode* curr1 = temp->next;
    ListNode* curr2 = head2;
    ListNode* store = NULL;
    if (curr1 == NULL) {
        temp->next = head2;
        return head1;
    }
    while (curr1 != NULL && curr2 != NULL) {
        if (temp->val <= curr2->val && curr2->val <= curr1->val) {
            store = curr2->next;
            curr2->next = curr1;
            temp->next = curr2;
            curr2 = store;
            temp = temp->next;
        } else {
            temp = temp->next;
            curr1 = curr1->next;
        }
    }

    if (curr1 == NULL && curr2 != NULL) {
        temp->next = curr2;
    }
    return head1;
}

// Function to merge two sorted linked lists and return the result
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == NULL && list2 == NULL) return NULL;
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    if (list1->val <= list2->val) {
        return merge(list1, list2);
    }
    return merge(list2, list1);
}

// Function to display the linked list
void displayList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    cout << "List 1: ";
    displayList(list1);

    cout << "List 2: ";
    displayList(list2);

    ListNode* mergedList = mergeTwoLists(list1, list2);

    cout << "Merged Sorted List: ";
    displayList(mergedList);

    // Clean up memory
    while (list1) {
        ListNode* temp = list1;
        list1 = list1->next;
        delete temp;
    }
    while (list2) {
        ListNode* temp = list2;
        list2 = list2->next;
        delete temp;
    }
    while (mergedList) {
        ListNode* temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }

    return 0;
}