// Given a fixed-length integer array arr, duplicate each occurrence of two (2), shifting the
// remaining elements to the right.
// Note that elements beyond the length of the original array are not written. Do the above
// modifications to the input array in place and do not return anything.
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];

    for(int i=0;i<n;i++) {
        if(arr[i]==2) {
            arr.insert(arr.begin()+i,2);
            arr.pop_back();
            i++;
        }
    }
    for(int i=0;i<n;i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

