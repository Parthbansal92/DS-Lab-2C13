// (b) One Queue

#include <iostream>
#include <queue>
using namespace std;

class StackUsingOneQueue {
    queue<int> q;

public:
    void push(int x) {
        int size = q.size();
        q.push(x);

        // Rotate the queue to move the new element to the front
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }

        cout << x << " pushed\n";
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << q.front() << " popped\n";
        q.pop();
    }

    void top() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Top element: " << q.front() << "\n";
    }

    bool isEmpty() {
        return q.empty();
    }
};

int main() {
    StackUsingOneQueue s;
    int choice, val;

    while (true) {
        cout << "\nMenu:\n1. Push\n2. Pop\n3. Top\n4. IsEmpty\n5. Exit\n";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                s.push(val);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.top();
                break;
            case 4:
                cout << (s.isEmpty() ? "Stack is empty\n" : "Stack is not empty\n");
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
}