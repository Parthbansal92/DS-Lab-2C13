#include <bits/stdc++.h>
using namespace std;

void improvedSelection(vector<int> &a) {
    int l = 0, r = (int)a.size() - 1;
    while (l < r) {
        int minIdx = l, maxIdx = r;
        if (a[minIdx] > a[maxIdx]) swap(minIdx, maxIdx);
        for (int i = l; i <= r; i++) {
            if (a[i] < a[minIdx]) minIdx = i;
            if (a[i] > a[maxIdx]) maxIdx = i;
        }
        swap(a[l], a[minIdx]);
        if (maxIdx == l) maxIdx = minIdx;
        swap(a[r], a[maxIdx]);
        l++;
        r--;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    improvedSelection(a);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}
