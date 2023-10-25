#include <iostream>

using namespace std;

int binarySearch(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Return -1 if the element is not found.
}

int main() {
    int arr[100];
    int n, key, position;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> key;

    int choice;
    cout << "1. Binary Search" << endl;
    cin >> choice;

    switch (choice) {
        case 1:
            position = binarySearch(arr, n, key);
            if (position != -1) {
                cout << "Element found at index: " << position << endl;
            } else {
                cout << "Element not found in the array." << endl;
            }
            break;
        default:
            cout << "Invalid choice." << endl;
    }

    return 0;
}