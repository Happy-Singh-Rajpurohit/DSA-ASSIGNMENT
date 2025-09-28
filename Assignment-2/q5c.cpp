#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of lower triangular matrix: ";
    cin >> n;

    int arr[n*(n+1)/2];

    cout << "Enter elements (row-wise, only lower triangular):\n";
    for(int i=0; i<n; i++)
        for(int j=0; j<=i; j++)
            cin >> arr[i*(i+1)/2 + j];

    cout << "Matrix:\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(j<=i) cout<<arr[i*(i+1)/2 + j]<<" ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
    return 0;
}
