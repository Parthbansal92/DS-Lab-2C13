#include <bits/stdc++.h>
using namespace std;

void countSortDigit(vector<int> &a, int exp) {
    int n = a.size();
    vector<int> out(n);
    int c[10] = {0};
    for (int i = 0; i < n; i++) {
        int d = (a[i] / exp) % 10;
        c[d]++;
    }
    for (int i = 1; i < 10; i++) c[i] += c[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        int d = (a[i] / exp) % 10;
        out[c[d] - 1] = a[i];
        c[d]--;
    }
    for (int i = 0; i < n; i++) a[i] = out[i];
}

void radixSort(vector<int> &a) {
    if (a.empty()) return;
    int mx = *max_element(a.begin(), a.end());
    for (int exp = 1; mx / exp > 0; exp *= 10)
        countSortDigit(a, exp);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    radixSort(a);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}
