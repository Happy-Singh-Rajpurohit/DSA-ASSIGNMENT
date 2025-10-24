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

    // Insert at end
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
        Node* temp = head;
        if (temp == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Find middle
    void findMiddle() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        cout << "Middle element: " << slow->data << endl;
    }
};

int main() {
    SinglyLinkedList list;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter " << n << " node values:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        list.insertAtEnd(val);
    }

    list.display();
    list.findMiddle();

    return 0;
}
