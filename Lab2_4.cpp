/*Зашифрувати рядок символів циклічним зсувом вліво його бітів на вказану величину.*/
#include <iostream>
#include <string>

using namespace std;

string LeftShift(string str, int n) {
    string encrypted = str;
    int length = encrypted.length();
    for (int i = 0; i < length; i++) {
        char c = encrypted[i];
        encrypted[i] = c << n;
    }

    return encrypted;
}

int main() {

    string str;
    int n;
    cout << "Enter string: ";
    getline(cin, str);
    cout << "Enter number of bytes for shifting: ";
    cin >> n;
    string encrypted = LeftShift(str, n);
    cout << "Encrypted string: " << encrypted << endl;

    return 0;
}




