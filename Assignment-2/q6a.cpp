#include <iostream>
using namespace std;

struct Element {
    int row, col, value;
};

int main() {
    int m, n, t; // rows, cols, non-zero elements
    cout << "Enter rows, cols, and number of non-zero elements: ";
    cin >> m >> n >> t;

    Element A[t], AT[t];
    cout << "Enter row, col, value for each non-zero element:\n";
    for(int i=0;i<t;i++)
        cin >> A[i].row >> A[i].col >> A[i].value;

    // Transpose: swap row and column
    for(int i=0;i<t;i++){
        AT[i].row = A[i].col;
        AT[i].col = A[i].row;
        AT[i].value = A[i].value;
    }

    cout << "Transposed Sparse Matrix (triplet form):\n";
    cout << "Row Col Value\n";
    for(int i=0;i<t;i++)
        cout << AT[i].row << "   " << AT[i].col << "   " << AT[i].value << endl;

    return 0;
}
