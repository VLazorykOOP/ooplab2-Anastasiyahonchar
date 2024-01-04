/*Реалізувати завдання 2 з використанням структур з бітовими полями та об’єднаннями.*/

#include <iostream>
#include <bitset>
#include <fstream>

using namespace std;

struct EncodedChar {
    unsigned short parity : 1;
    unsigned short ascii_code : 8;
    unsigned short position : 7;
};

union CharUnion {
    char c;
    EncodedChar binary;
};

int main() {
    CharUnion a;
    char S[128];
    char decodedString[128];
    char encodedString[128];
    cout << "Enter string: ";
    cin.get(S, 128);

    // Encryption
    ofstream outFile("encrypted.txt", ios::out | ios::binary);
    for (int i = 0; i < 128; i++) {
        a.c = S[i];
        a.binary.position = i;
        if (i % 2 == 0) a.binary.parity = 1; else a.binary.parity = 0;
        a.binary.ascii_code = S[i];
        outFile.write(reinterpret_cast<char*>(&a), sizeof(CharUnion));

        cout << bitset<1>(a.binary.parity);
        cout << bitset<8>(a.binary.ascii_code);
        cout << bitset<7>(a.binary.position) << endl;
    }
    outFile.close();

    // Decryption
    ifstream inFile("encrypted.txt", ios::in | ios::binary);
    if (!inFile) {
        cerr << "Could not open the input file." << endl;
        return 1;
    }

    for (int i = 0; i < 128; i++) {
        inFile.read(reinterpret_cast<char*>(&a), sizeof(CharUnion));

        decodedString[a.binary.position] = static_cast<char>(a.binary.ascii_code);
    }
    inFile.close();

    cout << "Decoded string: " << decodedString << endl;

    return 0;
}






