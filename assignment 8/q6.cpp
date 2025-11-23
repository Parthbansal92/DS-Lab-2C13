#include <bits/stdc++.h>
using namespace std;

struct Heap {
    vector<int> h;
    void up(int i) {
        while (i > 0) {
            int p = (i-1)/2;
            if (h[p] >= h[i]) break;
            swap(h[p], h[i]);
            i = p;
        }
    }
    void down(int i) {
        int n = h.size();
        while (true) {
            int l = 2*i+1, r = 2*i+2, big = i;
            if (l < n && h[l] > h[big]) big = l;
            if (r < n && h[r] > h[big]) big = r;
            if (big == i) break;
            swap(h[i], h[big]);
            i = big;
        }
    }
    void push(int x) {
        h.push_back(x);
        up(h.size()-1);
    }
    bool empty() {
        return h.empty();
    }
    int top() {
        if (h.empty()) return -1;
        return h[0];
    }
    void pop() {
        if (h.empty()) return;
        h[0] = h.back();
        h.pop_back();
        if (!h.empty()) down(0);
    }
};

int main() {
    Heap pq;
    int ch;
    while (cin >> ch) {
        if (ch == 1) {
            int x; cin >> x;
            pq.push(x);
        } else if (ch == 2) {
            if (!pq.empty()) {
                cout << pq.top() << endl;
                pq.pop();
            }
        } else if (ch == 3) {
            if (!pq.empty()) cout << pq.top() << endl;
            else cout << "Empty" << endl;
        } else if (ch == 0) {
            break;
        }
    }
    return 0;
}
