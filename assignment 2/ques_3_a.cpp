// Design the Logic to Find a Missing Number in a Sorted Array. Given an array of n-1
// distinct integers in the range of 1 to n, find the missing number in it in a Sorted Array
// (a) Linear time
// (b) Using binary search.

#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    int arr[n-1];
    int sum = 0;
    for (int i = 0; i < n-1; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    int total = n * (n + 1) / 2;
    cout << "Missing: " << total - sum;
}
