#include <iostream>
#include <stack>
using namespace std;

string reverseString(string str) {
    stack<char> s;
    for (int i=0;i<str.size();i++){
        s.push(str[i]);
    }
    int i=0;
    while (!s.empty()) {
       str[i]=s.top();
        i++;
       s.pop();
    }
    return str;
}

int main() {
    string str = "DataStructure";
    cout << "Original string: " << str << endl;
    cout << "Reversed string: " << reverseString(str) << endl;
    return 0;

}
