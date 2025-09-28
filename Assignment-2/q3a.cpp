#include <iostream>
using namespace std;

int findMissingLinear(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1) {
            return i + 1;  // missing number found
        }
    }
    return n;  // if no mismatch, last number missing
}

int main() {
    int arr[] = {1, 2, 3, 5, 6};  // Example (missing 4)
    int n = 6; // should be 1 to 6 (but only 5 elements given)

    cout << "Missing number (Linear): " << findMissingLinear(arr, n) << endl;

    return 0;
}
