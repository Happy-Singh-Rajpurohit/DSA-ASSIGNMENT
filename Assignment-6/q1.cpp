#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* head;
public:
    CircularLinkedList() {
        head = nullptr;
    }

    // Insert at beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node();
        newNode->data = val;

        if (head == nullptr) {
            head = newNode;
            head->next = head; // circular
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
        cout << val << " inserted at beginning.\n";
    }

    // Insert at end
    void insertAtEnd(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        cout << val << " inserted at end.\n";
    }

    // Insert after a node
    void insertAfter(int key, int val) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        do {
            if (temp->data == key) {
                Node* newNode = new Node();
                newNode->data = val;
                newNode->next = temp->next;
                temp->next = newNode;
                cout << val << " inserted after " << key << ".\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node " << key << " not found.\n";
    }

    // Insert before a node
    void insertBefore(int key, int val) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (head->data == key) { // special case
            insertAtBeginning(val);
            return;
        }
        Node* prev = nullptr;
        Node* temp = head;
        do {
            if (temp->data == key) {
                Node* newNode = new Node();
                newNode->data = val;
                newNode->next = temp;
                prev->next = newNode;
                cout << val << " inserted before " << key << ".\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);
        cout << "Node " << key << " not found.\n";
    }

    // Delete specific node
    void deleteNode(int key) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        // case 1: only one node
        if (head->data == key && head->next == head) {
            delete head;
            head = nullptr;
            cout << key << " deleted.\n";
            return;
        }

        // case 2: head node deletion
        if (head->data == key) {
            Node* last = head;
            while (last->next != head) last = last->next;
            last->next = head->next;
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            cout << key << " deleted.\n";
            return;
        }

        // case 3: node in between or last
        do {
            if (temp->data == key) {
                prev->next = temp->next;
                delete temp;
                cout << key << " deleted.\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);

        cout << "Node " << key << " not found.\n";
    }

    // Search node
    void search(int key) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        int pos = 1;
        do {
            if (temp->data == key) {
                cout << key << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
        cout << key << " not found in list.\n";
    }

    // Display list
    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)\n";
    }
};

// Menu-driven program
int main() {
    CircularLinkedList cll;
    int choice, val, key;

    do {
        cout << "\n--- Circular Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Node\n";
        cout << "4. Insert Before a Node\n";
        cout << "5. Delete a Node\n";
        cout << "6. Search a Node\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            cll.insertAtBeginning(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            cll.insertAtEnd(val);
            break;
        case 3:
            cout << "Enter key after which to insert: ";
            cin >> key;
            cout << "Enter value: ";
            cin >> val;
            cll.insertAfter(key, val);
            break;
        case 4:
            cout << "Enter key before which to insert: ";
            cin >> key;
            cout << "Enter value: ";
            cin >> val;
            cll.insertBefore(key, val);
            break;
        case 5:
            cout << "Enter value to delete: ";
            cin >> key;
            cll.deleteNode(key);
            break;
        case 6:
            cout << "Enter value to search: ";
            cin >> key;
            cll.search(key);
            break;
        case 7:
            cll.display();
            break;
        case 8:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 8);

    return 0;
}
