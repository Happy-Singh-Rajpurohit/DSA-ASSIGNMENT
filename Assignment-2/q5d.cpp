#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of upper triangular matrix: ";
    cin >> n;

    int arr[n*(n+1)/2];

    cout << "Enter elements (row-wise, only upper triangular):\n";
    for(int i=0; i<n; i++)
        for(int j=i; j<n; j++)
            cin >> arr[j*(j+1)/2 + i];

    cout << "Matrix:\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i<=j) cout<<arr[j*(j+1)/2 + i]<<" ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
    return 0;
}
