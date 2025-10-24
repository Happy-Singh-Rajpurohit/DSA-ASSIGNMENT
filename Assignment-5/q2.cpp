#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Linked list class
class SinglyLinkedList {
private:
    Node* head;
public:
    SinglyLinkedList() {
        head = nullptr;
    }

    // Insert at end (for easy list creation)
    void insertAtEnd(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    // Display list
    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Count occurrences of key
    int countOccurrences(int key) {
        Node* temp = head;
        int count = 0;
        while (temp != nullptr) {
            if (temp->data == key) count++;
            temp = temp->next;
        }
        return count;
    }

    // Delete all occurrences of key
    void deleteAllOccurrences(int key) {
        // Delete nodes from beginning if they match key
        while (head != nullptr && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        Node* current = head;
        while (current != nullptr && current->next != nullptr) {
            if (current->next->data == key) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
            } else {
                current = current->next;
            }
        }

        cout << "All occurrences of " << key << " deleted.\n";
    }
};

int main() {
    SinglyLinkedList list;
    int n, val, key;

    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter " << n << " node values:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        list.insertAtEnd(val);
    }

    list.display();

    cout << "Enter key to count and delete: ";
    cin >> key;

    int count = list.countOccurrences(key);
    cout << "Number of occurrences of " << key << ": " << count << endl;

    list.deleteAllOccurrences(key);
    list.display();

    return 0;
}
