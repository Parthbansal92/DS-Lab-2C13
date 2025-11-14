// Write a program to find first non-repeating character in a string using Queue. Sample I/P: a a
// b c Sample O/P: a -1 b b

#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void firstNonRepeatingChar(string s) {
    unordered_map<char, int> freq;
    queue<char> q;

    for (char ch : s) {
        freq[ch]++;
        q.push(ch);

        // Remove characters from the front of the queue while
        // they have frequency more than 1
        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        if (!q.empty())
            cout << q.front() << " ";
        else
            cout << -1 << " ";
    }
    cout << "\n";
}

int main() {
    string s;
    cout << "Enter string (space separated chars or continuous): ";
    getline(cin, s);

    firstNonRepeatingChar(s);

    return 0;
}