#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter elements:\n";
    for(int i=0; i<n; i++)
        cin >> arr[i];

    int count = 0;

    for(int i=0; i<n; i++){
        bool isDistinct = true;
        // Check if arr[i] appeared before
        for(int j=0; j<i; j++){
            if(arr[i] == arr[j]){
                isDistinct = false;
                break;
            }
        }
        if(isDistinct)
            count++;
    }

    cout << "Total number of distinct elements: " << count << endl;

    return 0;
}
