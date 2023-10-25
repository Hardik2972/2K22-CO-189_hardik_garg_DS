#include <iostream>

using namespace std;

const int MAX_SIZE = 100; // Define the maximum size of the array.

int main() {
    int arr[MAX_SIZE];
    int n, choice, element, position, size = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        size++;
    }

    cin >> choice;

    if (choice == 1) {
        cin >> position >> element;
        if (size < MAX_SIZE && position >= 0 && position <= size) {
            for (int i = size; i > position; i--) {
                arr[i] = arr[i - 1];
            }
            arr[position] = element;
            size++;
        } else {
            cout << "Overflow condition or invalid position: Array is full or position is invalid, cannot insert." << endl;
        }
    } else if (choice == 2) {
        cin >> position;
        if (position >= 0 && position < size) {
            for (int i = position; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            size--;
        } else {
            cout << "Invalid position: Position is out of bounds, cannot delete." << endl;
        }
    }

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}