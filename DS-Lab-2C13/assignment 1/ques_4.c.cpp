//c. Find the Transpose of a Matrix


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

    cout << "Transpose of the matrix:\n";
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            cout << mat[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}
