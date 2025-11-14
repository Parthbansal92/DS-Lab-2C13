// Write a program to find sum of every row and every column in a two-dimensional 
//array.  

#include <iostream>
using namespace std;

int main() {
    int r, c;

    cout << "Enter number of rows and columns: ";
    cin >> r >> c;

    int mat[10][10];

    cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> mat[i][j];
        }
    }
    for (int i = 0; i < r; i++) {
        int rowSum = 0;
        for (int j = 0; j < c; j++) {
            rowSum += mat[i][j];
        }
        cout << "Sum of Row " << i + 1 << " = " << rowSum << endl;
    }
    for (int j = 0; j < c; j++) {
        int colSum = 0;
        for (int i = 0; i < r; i++) {
            colSum += mat[i][j];
        }
        cout << "Sum of Column " << j + 1 << " = " << colSum << endl;
    }

    return 0;
}
