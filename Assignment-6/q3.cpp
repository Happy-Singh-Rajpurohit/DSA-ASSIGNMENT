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

    // Function to find size of circular linked list
    int getSize() {
        if (head == nullptr) return 0;
        int count = 0;
        Node* temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
        return count;
    }
};

int main() {
    CircularLinkedList cll;

    // Insert elements: 10, 20, 30, 40
    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cll.insertAtEnd(40);

    cout << "Size of circular linked list = " << cll.getSize() << endl;

    return 0;
}
