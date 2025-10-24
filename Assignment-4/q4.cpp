#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void firstNonRepeating(string str) {
    queue<char> q;
    unordered_map<char, int> freq;

    for (char ch : str) {
        // Step 1: push char into queue
        q.push(ch);
        // Step 2: increase frequency
        freq[ch]++;

        // Step 3: remove repeating chars from front
        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        // Step 4: print answer
        if (!q.empty()) {
            cout << q.front() << " ";
        } else {
            cout << -1 << " ";
        }
    }
    cout << endl;
}

int main() {
    string input = "aabc";
    cout << "Input: " << input << endl;
    cout << "Output: ";
    firstNonRepeating(input);
    return 0;
}
