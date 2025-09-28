#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str1[100], str2[50];

    cout << "Enter first string: ";
    cin.getline(str1, 100);
    cout << "Enter second string: ";
    cin.getline(str2, 50);

    strcat(str1, str2); // concatenate str2 to str1

    cout << "Concatenated String: " << str1 << endl;
    return 0;
}
