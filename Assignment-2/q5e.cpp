#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of symmetric matrix: ";
    cin >> n;

    int arr[n*(n+1)/2];

    cout << "Enter elements (only lower triangular):\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<=i;j++)
            cin >> arr[i*(i+1)/2 + j];

    cout << "Matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j<=i)
                cout << arr[i*(i+1)/2 + j] << " ";
            else
                cout << arr[j*(j+1)/2 + i] << " ";
        }
        cout<<endl;
    }
    return 0;
}
