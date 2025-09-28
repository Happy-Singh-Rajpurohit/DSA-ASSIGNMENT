#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    int top;
    int arr[MAX];

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << x << endl;
            return;
        }
        arr[++top] = x;
        cout << x << " pushed into stack." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Nothing to pop." << endl;
            return;
        }
        cout << arr[top--] << " popped from stack." << endl;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Top element: " << arr[top] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n----- STACK MENU -----\n";
        cout << "1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                if(s.isEmpty()) cout << "Stack is empty.\n";
                else cout << "Stack is not empty.\n";
                break;
            case 4:
                if(s.isFull()) cout << "Stack is full.\n";
                else cout << "Stack is not full.\n";
                break;
            case 5:
                s.display();
                break;
            case 6:
                s.peek();
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
