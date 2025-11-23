#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int> &a) {
    if (a.empty()) return;
    int mx = *max_element(a.begin(), a.end());
    vector<int> c(mx + 1, 0);
    for (int x : a) c[x]++;
    int idx = 0;
    for (int i = 0; i <= mx; i++)
        while (c[i]--) a[idx++] = i;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    countingSort(a);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}
