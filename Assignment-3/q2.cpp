#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    stack<char> s;

    // Push each character into the stack
    for (int i = 0; i < str.length(); i++)
        s.push(str[i]);

    // Pop characters to form reversed string
    string reversed = "";
    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }

    cout << "Reversed string: " << reversed << endl;

    return 0;
}
