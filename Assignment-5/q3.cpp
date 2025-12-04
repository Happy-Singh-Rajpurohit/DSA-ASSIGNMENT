#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Singly linked list class
class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    // Insert at end
    void insertAtEnd(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = newNode;
    }

    // Display list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Reverse linked list
    void reverseList() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;    // store next
            current->next = prev;    // reverse pointer
            prev = current;          // move prev forward
            current = next;          // move current forward
        }

        head = prev;  // update head
    }
};

int main() {
    SinglyLinkedList list;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        list.insertAtEnd(val);
    }

    cout << "\nOriginal List: ";
    list.display();

    list.reverseList();

    cout << "Reversed List: ";
    list.display();

    return 0;
}
