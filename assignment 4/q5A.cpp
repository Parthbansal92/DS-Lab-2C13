// Write a program to implement a stack using (a) Two queues and .

#include <iostream>
#include <queue>
using namespace std;

class StackUsingTwoQueues {
    queue<int> q1, q2;

public:
    void push(int x) {
        q2.push(x);

        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap names of queues
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;

        cout << x << " pushed\n";
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << q1.front() << " popped\n";
        q1.pop();
    }

    void top() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Top element: " << q1.front() << "\n";
    }

    bool isEmpty() {
        return q1.empty();
    }
};

int main() {
    StackUsingTwoQueues s;
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