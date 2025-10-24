#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int>& q) {
    int n = q.size();

    // Check for even number of elements
    if (n % 2 != 0) {
        cout << "Queue must have even number of elements!" << endl;
        return;
    }

    int half = n / 2;
    queue<int> firstHalf;

    // Step 1: Move first half elements into another queue
    for (int i = 0; i < half; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    // Step 2: Interleave both halves
    while (!firstHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();

        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;

    // Sample Input: 4 7 11 20 5 9
    q.push(4);
    q.push(7);
    q.push(11);
    q.push(20);
    q.push(5);
    q.push(9);

    cout << "Original Queue: ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
