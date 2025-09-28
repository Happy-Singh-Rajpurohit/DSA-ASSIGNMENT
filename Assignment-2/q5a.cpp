#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of diagonal matrix: ";
    cin >> n;

    int diag[n];  // store only diagonal elements

    cout << "Enter diagonal elements:\n";
    for (int i = 0; i < n; i++)
        cin >> diag[i];

    cout << "Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                cout << diag[i] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}
