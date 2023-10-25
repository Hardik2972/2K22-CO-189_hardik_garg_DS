#include <iostream>

using namespace std;

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
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
    cout << "1. Linear Search" << endl;
    cin >> choice;

    switch (choice) {
        case 1:
            position = linearSearch(arr, n, key);
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