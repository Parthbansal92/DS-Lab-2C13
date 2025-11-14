#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int evaluatePostfix(string exp) {
    stack<int> s;

    for (char ch : exp) {
        if (isdigit(ch)) {
            s.push(ch - '0');
        } else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            switch (ch) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
            }
        }
    }

    return s.top();
}

int main() {
    string postfix = "231*+9-";  
    cout << "Postfix: " << postfix << endl;
    cout << "Evaluated result: " << evaluatePostfix(postfix) << endl;
    return 0;
}