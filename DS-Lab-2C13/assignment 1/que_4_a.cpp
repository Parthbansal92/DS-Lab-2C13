//a. Reverse the elements of an array

#include <iostream>
using namespace std;

int main() {
    int arr[100], n;

    cout << "Enter the size of the array: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Array in reverse order: ";
    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }

    return 0;
}
