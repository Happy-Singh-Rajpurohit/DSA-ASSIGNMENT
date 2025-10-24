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

    // (a) Insert at beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = head;
        head = newNode;
        cout << val << " inserted at the beginning.\n";
    }

    // (b) Insert at end
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
        cout << val << " inserted at the end.\n";
    }

    // (c) Insert before or after a specific node
    void insertAfter(int target, int val) {
        Node* temp = head;
        while (temp != nullptr && temp->data != target)
            temp = temp->next;

        if (temp == nullptr) {
            cout << "Node " << target << " not found.\n";
            return;
        }

        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = temp->next;
        temp->next = newNode;
        cout << val << " inserted after " << target << ".\n";
    }

    void insertBefore(int target, int val) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        if (head->data == target) {
            insertAtBeginning(val);
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != target)
            temp = temp->next;

        if (temp->next == nullptr) {
            cout << "Node " << target << " not found.\n";
            return;
        }

        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = temp->next;
        temp->next = newNode;
        cout << val << " inserted before " << target << ".\n";
    }

    // (d) Delete from beginning
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << temp->data << " deleted from beginning.\n";
        delete temp;
    }

    // (e) Delete from end
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (head->next == nullptr) {
            cout << head->data << " deleted from end.\n";
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr)
            temp = temp->next;

        cout << temp->next->data << " deleted from end.\n";
        delete temp->next;
        temp->next = nullptr;
    }

    // (f) Delete specific node
    void deleteNode(int target) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (head->data == target) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != target)
            temp = temp->next;

        if (temp->next == nullptr) {
            cout << "Node " << target << " not found.\n";
            return;
        }

        Node* delNode = temp->next;
        temp->next = temp->next->next;
        cout << delNode->data << " deleted from list.\n";
        delete delNode;
    }

    // (g) Search for a node and display position
    void searchNode(int val) {
        Node* temp = head;
        int pos = 1;
        while (temp != nullptr) {
            if (temp->data == val) {
                cout << val << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << val << " not found in the list.\n";
    }

    // (h) Display all node values
    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        cout << "Linked List: ";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList list;
    int choice, val, target;

    do {
        cout << "\n----- SINGLY LINKED LIST MENU -----\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert after a node\n";
        cout << "4. Insert before a node\n";
        cout << "5. Delete from beginning\n";
        cout << "6. Delete from end\n";
        cout << "7. Delete a specific node\n";
        cout << "8. Search for a node\n";
        cout << "9. Display list\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: "; cin >> val;
                list.insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value: "; cin >> val;
                list.insertAtEnd(val);
                break;
            case 3:
                cout << "Enter target node: "; cin >> target;
                cout << "Enter value to insert: "; cin >> val;
                list.insertAfter(target, val);
                break;
            case 4:
                cout << "Enter target node: "; cin >> target;
                cout << "Enter value to insert: "; cin >> val;
                list.insertBefore(target, val);
                break;
            case 5:
                list.deleteFromBeginning();
                break;
            case 6:
                list.deleteFromEnd();
                break;
            case 7:
                cout << "Enter node to delete: "; cin >> target;
                list.deleteNode(target);
                break;
            case 8:
                cout << "Enter node to search: "; cin >> target;
                list.searchNode(target);
                break;
            case 9:
                list.display();
                break;
            case 10:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while(choice != 10);

    return 0;
}
