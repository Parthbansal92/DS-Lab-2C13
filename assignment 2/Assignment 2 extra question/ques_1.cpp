// Find two numbers in an array whose difference equals K. Given an array arr[] and a
// positive integer k, the task is to count all pairs (i, j) such that i < j and absolute value of
// (arr[i] - arr[j]) is equal to k.
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    for(int a=0;a<n;a++) cin >> v[a];

    sort(v.begin(), v.end());

    int p=0,q=1,res=0;
    while(q<n) {
        if(p==q) q++;
        else if(v[q]-v[p]==k) {
            res++;
            p++;
            q++;
        }
        else if(v[q]-v[p]<k) q++;
        else p++;
    }
    cout << res;
    return 0;
}

