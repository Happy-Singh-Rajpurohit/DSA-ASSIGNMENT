#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string expr) {
    stack<char> s;

    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);  // push opening bracket
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) return false;  // no matching opening bracket

            char top = s.top();
            s.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '['))
                return false;  // mismatched pair
        }
    }

    return s.empty();  // if stack empty → balanced
}

int main() {
    string expr;
    cout << "Enter an expression: ";
    getline(cin, expr);

    if (isBalanced(expr))
        cout << "Expression is balanced.\n";
    else
        cout << "Expression is NOT balanced.\n";

    return 0;
}
