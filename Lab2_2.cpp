/*Задано текст до 128 символів. Доповнити пробілами до 128 символів. Шифрувати тексти 
таким чином, щоб кожний символ тексту записувався у два байта. Два байта мають таку 
структуру: 
0 біт – біт парності (1 біт)
у бітах 1-8 ASCII - код букви (8 біт), 
у бітах 9-15 позиція букви у рядку (7 біти)*/

#include <iostream>
#include <cstring>

using namespace std;

void Shifruvanna(char S[128], unsigned short Rez[128]) {
    for (int i = 0; i < 128; i++) {
        unsigned char c = S[i];;
        unsigned short r = 0, t, b;
        t = c;
        r |= t << 1;
        r |= i << 9; 
        t = 1;
        b = 0;
        for (int j = 0; j < 16; j++) {
            if (r&t) {
            if (b==0) b = 1; else b = 0;
            }
            t <<= 1;
        }
        r |= b; 
        Rez[i] = r;
    }
}

void Deshifruvanna(unsigned short Rez[128], char S[128]) {
    for (int i = 0; i < 128; i++) {
        unsigned short c = Rez[i];
        unsigned short r = 0, t, b;
        t = c;
        r |= t >> 1;
        r |= i >> 9; 
        t = 1;
        b = 0;
        for (int j = 0; j < 16; j++) {
            if (r&t) {
            if (b==0) b = 1; else b = 0;
            }
            t >>= 1;
        }
        r |= b; 
        S[i] = r;
    }
}

int main() {
    char S[128];
    unsigned short Rez[128];
    cout << "Enter text: ";
    cin.get(S, 128);

    int len = strlen(S);
    if (len < 128){
        for (int i = len; i < 128; i++){
            S[i] = ' ';
        }
    }

    Shifruvanna(S, Rez);
    cout << "Encrypted text:" << endl;
    for (int i = 0; i < 128; i++){
        cout << hex << Rez[i] << endl;
    }

    Deshifruvanna(Rez, S);
    cout << "Decrypted text: " << S << endl;

    return 0;
}