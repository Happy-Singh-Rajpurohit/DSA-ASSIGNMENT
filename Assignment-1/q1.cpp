#include <iostream>
using namespace std;

#define MAX 100   // Maximum size of array

int arr[MAX];    // Array declaration
int n = 0;       // Current size of array

// Function to create array
void create() {
    cout << "Enter number of elements: ";
    cin >> n;
    if (n > MAX) {
        cout << "Size too large! Max is " << MAX << endl;
        n = 0;
        return;
    }
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Array created successfully!\n";
}

// Function to display array
void display() {
    if (n == 0) {
        cout << "Array is empty!\n";
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to insert element
void insert() {
    if (n == MAX) {
        cout << "Array is full, cannot insert!\n";
        return;
    }
    int pos, value;
    cout << "Enter position (1 to " << n+1 << "): ";
    cin >> pos;
    cout << "Enter value: ";
    cin >> value;

    if (pos < 1 || pos > n+1) {
        cout << "Invalid position!\n";
        return;
    }

    // Shift elements to the right
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i-1];
    }
    arr[pos-1] = value;
    n++;
    cout << "Element inserted successfully!\n";
}

// Function to delete element
void remove() {
    if (n == 0) {
        cout << "Array is empty, nothing to delete!\n";
        return;
    }
    int pos;
    cout << "Enter position (1 to " << n << "): ";
    cin >> pos;

    if (pos < 1 || pos > n) {
        cout << "Invalid position!\n";
        return;
    }

    // Shift elements to the left
    for (int i = pos-1; i < n-1; i++) {
        arr[i] = arr[i+1];
    }
    n--;
    cout << "Element deleted successfully!\n";
}

// Function for linear search
void linearSearch() {
    if (n == 0) {
        cout << "Array is empty!\n";
        return;
    }
    int key, found = -1;
    cout << "Enter value to search: ";
    cin >> key;

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            found = i;
            break;
        }
    }

    if (found != -1)
        cout << "Element found at position " << found+1 << endl;
    else
        cout << "Element not found!\n";
}

// Main function
int main() {
    int choice;

    do {
        cout << "\n---- MENU ----\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: remove(); break;
            case 5: linearSearch(); break;
            case 6: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while(choice != 6);

    return 0;
}
