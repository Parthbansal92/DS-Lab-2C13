#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string expr) {
    stack<char> s;
    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[')
            s.push(ch);
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) return false;
            char top = s.top();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '['))
                return false;
            s.pop();
        }
    }
    return s.empty();
}

int main() {
    string expr = "{[()]}";
    if (isBalanced(expr))
        cout << "Balanced expression\n";
    else
        cout << "Unbalanced expression\n";
    return 0;
}