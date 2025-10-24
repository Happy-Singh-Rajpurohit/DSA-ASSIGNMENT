#include <iostream>
using namespace std;

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

    // Insert at end
    void insertAtEnd(int val) {
        Node* newNode = new Node();
        newNode->data = val;

        if (head == nullptr) {
            head = newNode;
            newNode->next = head; // circular
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Display with head repeated at the end
    void displayWithHeadRepeat() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "Output: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data; // repeat head node
        cout << endl;
    }
};

int main() {
    CircularLinkedList cll;

    // Input: 20 → 100 → 40 → 80 → 60
    cll.insertAtEnd(20);
    cll.insertAtEnd(100);
    cll.insertAtEnd(40);
    cll.insertAtEnd(80);
    cll.insertAtEnd(60);

    // Output: 20 100 40 80 60 20
    cll.displayWithHeadRepeat();

    return 0;
}
