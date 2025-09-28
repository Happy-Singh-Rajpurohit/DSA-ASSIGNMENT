#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of tri-diagonal matrix: ";
    cin >> n;

    int tri[3][n] = {0}; // 3 rows for 3 diagonals

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        if(i != 0) cin >> tri[0][i]; // lower diagonal
        cin >> tri[1][i];             // main diagonal
        if(i != n-1) cin >> tri[2][i]; // upper diagonal
    }

    cout << "Matrix:\n";
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i-j==1) cout<<tri[0][i]<<" ";
            else if(i==j) cout<<tri[1][i]<<" ";
            else if(j-i==1) cout<<tri[2][i]<<" ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
    return 0;
}
