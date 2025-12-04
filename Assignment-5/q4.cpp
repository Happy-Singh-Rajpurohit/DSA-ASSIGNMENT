#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node* reverseLinkedList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;   // store next node
        current->next = prev;   // reverse current node
        prev = current;         // move prev ahead
        current = next;         // move current ahead
    }

    return prev; // new head
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    // Creating linked list: 1 -> 2 -> 3 -> 4 -> NULL
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "Original List: ";
    printList(head);

    head = reverseLinkedList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}
