#include <iostream>
using namespace std;

#define SIZE 5   // maximum size of queue

class CircularQueue {
private:
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Check if queue is full
    bool isFull() {
        return ((rear + 1) % SIZE == front);
    }

    // Enqueue (insert element)
    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is FULL! Cannot insert " << val << ".\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }
        arr[rear] = val;
        cout << val << " enqueued into queue.\n";
    }

    // Dequeue (remove element)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY! Cannot dequeue.\n";
            return;
        }
        cout << arr[front] << " dequeued from queue.\n";
        if (front == rear) {
            // Only one element was there
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }

    // Peek (front element)
    void peek() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!\n";
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }

    // Display all elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!\n";
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, val;

    do {
        cout << "\n----- CIRCULAR QUEUE MENU -----\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek (front element)\n";
        cout << "4. Check if Empty\n";
        cout << "5. Check if Full\n";
        cout << "6. Display Queue\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> val;
                q.enqueue(val);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                cout << (q.isEmpty() ? "Queue is EMPTY\n" : "Queue is NOT empty\n");
                break;
            case 5:
                cout << (q.isFull() ? "Queue is FULL\n" : "Queue is NOT full\n");
                break;
            case 6:
                q.display();
                break;
            case 7:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while(choice != 7);

    return 0;
}
