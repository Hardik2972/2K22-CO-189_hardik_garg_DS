#include <iostream>
#include <vector>

using namespace std;

int findFloor(const vector<int>& arr, int target) {
    int left = -1;
    int right = arr.size() - 1;
    int floorValue = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return arr[mid];
        } else if (arr[mid] < target) {
            floorValue = arr[mid];
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return floorValue;
}

int findCeil(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size();
    int ceilValue = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return arr[mid];
        } else if (arr[mid] > target) {
            ceilValue = arr[mid];
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ceilValue;
}

int findPeak(const vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > arr[mid + 1]) {
            return arr[mid];
        }

        if (arr[mid] < arr[mid + 1]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return arr[left];
}

int findMinInRotatedSortedArray(const vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > arr[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return arr[left];
}

int main() {
    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int target = 5;

    int floorValue = findFloor(arr, target);
    int ceilValue = findCeil(arr, target);
    int peakValue = findPeak(arr);
    int minInRotatedArray = findMinInRotatedSortedArray(arr);

    cout << "Floor value of " << target << " is: " << floorValue << endl;
    cout << "Ceil value of " << target << " is: " << ceilValue << endl;
    cout << "Peak value in the rotated sorted array is: " << peakValue << endl;
    cout << "Minimum value in the rotated sorted array is: " << minInRotatedArray << endl;

    return 0;
}