#include <iostream>
using namespace std;

int findMissingBinary(int arr[], int n) {
    int low = 0, high = n - 2;  // since array size = n-1

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == mid + 1) {
            // left half correct → search right half
            low = mid + 1;
        } else {
            // mismatch found → search left half
            high = mid - 1;
        }
    }
    return low + 1;  // missing number
}

int main() {
    int arr[] = {1, 2, 3, 5, 6};  // Example (missing 4)
    int n = 6; // numbers from 1 to 6

    cout << "Missing number (Binary Search): " << findMissingBinary(arr, n) << endl;

    return 0;
}
