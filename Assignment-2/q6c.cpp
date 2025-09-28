#include <iostream>
#include <vector>
using namespace std;

struct Element {
    int row, col, value;
};

int main() {
    int r1, c1, t1, r2, c2, t2;
    cout << "Enter rows, cols, non-zero of first matrix: ";
    cin >> r1 >> c1 >> t1;
    Element A[t1];
    cout << "Enter row, col, value for first matrix:\n";
    for(int i=0;i<t1;i++) cin >> A[i].row >> A[i].col >> A[i].value;

    cout << "Enter rows, cols, non-zero of second matrix: ";
    cin >> r2 >> c2 >> t2;
    if(c1 != r2){
        cout << "Multiplication not possible!\n";
        return 0;
    }
    Element B[t2];
    cout << "Enter row, col, value for second matrix:\n";
    for(int i=0;i<t2;i++) cin >> B[i].row >> B[i].col >> B[i].value;

    vector<Element> C; // result matrix
    for(int i=0;i<t1;i++){
        for(int j=0;j<t2;j++){
            if(A[i].col == B[j].row){
                // check if element already exists in C
                bool found=false;
                for(int k=0;k<C.size();k++){
                    if(C[k].row==A[i].row && C[k].col==B[j].col){
                        C[k].value += A[i].value*B[j].value;
                        found=true;
                        break;
                    }
                }
                if(!found){
                    Element temp;
                    temp.row = A[i].row;
                    temp.col = B[j].col;
                    temp.value = A[i].value*B[j].value;
                    C.push_back(temp);
                }
            }
        }
    }

    cout << "Product of Sparse Matrices (triplet form):\n";
    cout << "Row Col Value\n";
    for(int i=0;i<C.size();i++)
        cout << C[i].row << "   " << C[i].col << "   " << C[i].value << endl;

    return 0;
}
