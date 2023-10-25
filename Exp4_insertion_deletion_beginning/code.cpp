#include <iostream>

using namespace std;

const int MAX_SIZE = 100; // Define the maximum size of the array.

int main() {
    int arr[MAX_SIZE];
    int n, choice, element, size = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        size++;
    }

    cin >> choice;

    if (choice == 1) {
        cin >> element;
        if (size < MAX_SIZE) {
            for (int i = size; i > 0; i--) {
                arr[i] = arr[i - 1];
            }
            arr[0] = element;
            size++;
        } else {
            cout << "Overflow condition: Array is full, cannot insert." << endl;
        }
    } else if (choice == 2) {
        if (size > 0) {
            for (int i = 0; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            size--;
        } else {
            cout << "Underflow condition: Array is empty, cannot delete." << endl;
        }
    }

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}