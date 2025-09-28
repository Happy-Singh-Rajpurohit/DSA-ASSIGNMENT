#include <iostream>
using namespace std;

struct Element {
    int row, col, value;
};

int main() {
    int m, n, t1, t2;
    cout << "Enter rows and cols of matrices: ";
    cin >> m >> n;

    cout << "Enter number of non-zero elements of first matrix: ";
    cin >> t1;
    Element A[t1];
    cout << "Enter row, col, value for first matrix:\n";
    for(int i=0;i<t1;i++)
        cin >> A[i].row >> A[i].col >> A[i].value;

    cout << "Enter number of non-zero elements of second matrix: ";
    cin >> t2;
    Element B[t2];
    cout << "Enter row, col, value for second matrix:\n";
    for(int i=0;i<t2;i++)
        cin >> B[i].row >> B[i].col >> B[i].value;

    // Addition
    Element C[t1+t2];
    int i=0, j=0, k=0;
    while(i<t1 && j<t2){
        if(A[i].row < B[j].row || (A[i].row==B[j].row && A[i].col < B[j].col))
            C[k++] = A[i++];
        else if(B[j].row < A[i].row || (B[j].row==A[i].row && B[j].col < A[i].col))
            C[k++] = B[j++];
        else {
            C[k] = A[i];
            C[k++].value = A[i++].value + B[j++].value;
        }
    }
    while(i<t1) C[k++] = A[i++];
    while(j<t2) C[k++] = B[j++];

    cout << "Sum of Sparse Matrices (triplet form):\n";
    cout << "Row Col Value\n";
    for(int x=0;x<k;x++)
        cout << C[x].row << "   " << C[x].col << "   " << C[x].value << endl;

    return 0;
}
