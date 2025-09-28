#include <iostream>
#include <stack>
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char ch) {
    return (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^');
}

string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for(char ch : infix) {
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            // Operand → append to postfix
            postfix += ch;
        } 
        else if(ch == '(') {
            s.push(ch);
        } 
        else if(ch == ')') {
            while(!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // pop '('
        } 
        else if(isOperator(ch)) {
            while(!s.empty() && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    // Pop remaining operators
    while(!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
