/*
Modifique el algoritmo "divide y vencerás" para la multiplicación de grandes enteros de forma que permita multiplicar números en binario. Ilustre el funcionamiento del algoritmo a la hora de multiplicar los siguientes enteros: 
A=10011011 y B=10111010
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string addBinary(string a, string b) {
    string result = "";
    int s = 0;          
    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || s == 1) {
        s += ((i >= 0)? a[i] - '0': 0);
        s += ((j >= 0)? b[j] - '0': 0);
        result = char(s % 2 + '0') + result;
        s /= 2;
        i--; j--;
    }
    return result;
}

string multiplySingleBit(string a, string b) { 
    return (a == "0" || b == "0") ? "0" : "1"; 
}

string multiply(string X, string Y) {
    int n = X.size();
    if (n == 0 || Y.size() == 0) return "0";
    if (n == 1) return multiplySingleBit(X, Y);
    int fh = n/2;   
    int sh = (n - fh); 
    string Xl = X.substr(0, fh);
    string Xr = X.substr(fh, sh);
    string Yl = Y.substr(0, fh);
    string Yr = Y.substr(fh, sh);
    string P1 = multiply(Xl, Yl);
    string P2 = multiply(addBinary(Xl, Xr), addBinary(Yl, Yr));
    string P3 = multiply(Xr, Yr);
    for (int i=0; i<2*sh; i++) P1 += "0";
    for (int i=0; i<sh; i++) P2 += "0";
    return addBinary(addBinary(P1, P3), P2);
}

int main() {
    string A = "10011011";
    string B = "10111010";
    cout << "Resultado: " << multiply(A, B) << endl;
    return 0;
}