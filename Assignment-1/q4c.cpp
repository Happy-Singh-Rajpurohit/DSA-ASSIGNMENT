#include <iostream>
using namespace std;

int main() {
    int A[10][10], T[10][10];
    int r, c;

    cout << "Enter rows and cols of Matrix: ";
    cin >> r >> c;

    cout << "Enter elements of Matrix:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> A[i][j];

    // Transpose
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            T[j][i] = A[i][j];
        }
    }

    cout << "Transpose of Matrix:\n";
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            cout << T[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
