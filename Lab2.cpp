/*Задано цілі числа a, b, c та d. Обчислити вираз без використання операцій множення та 
ділення(замінивши на їх операцій зсувів).
33*b+(d*15+12*a)/512-65*c+d*14*/
#include <iostream>

using namespace std;

int main(){
    int a, b, c, d;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter c: ";
    cin >> c;
    cout << "Enter d: ";
    cin >> d;
    float x;
    x = b + (b << 5) + (((d << 4) - d + (a << 3) + (a << 2)) >> 9) - (c << 6) - c + (d << 4) - (d << 1);
    cout << "Result: " << x;

    return 0;
}