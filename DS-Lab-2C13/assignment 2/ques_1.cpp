//Implement the Binary search algorithm regarded as a fast search algorithm with
// run-time complexity of Ο(log n) in comparison to the Linear Search.

#include <iostream>
using namespace std;
int main() {
    int n, key;
    cout << "Enter size: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements (sorted): ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Enter key: ";
    cin >> key;
    int l = 0, r = n - 1, mid, flag = 0;
    while (l <= r) {
        mid = (l + r) / 2;
        if (arr[mid] == key) {
            flag = 1;
            break;
        } else if (arr[mid] < key) l = mid + 1;
        else r = mid - 1;
    }
    if (flag) cout << "Found";
    else cout << "Not Found";
}
