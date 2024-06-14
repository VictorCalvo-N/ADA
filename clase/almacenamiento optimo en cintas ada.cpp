

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void almacenarcintas(vector<int>& valores) {
    sort(valores.begin(), valores.end());

    int n = valores.size();
    double TMR = 0.0;
    int acumuladortam = 0;

    for (int i = 0; i < n; i++) {
        acumuladortam += valores[i];
        TMR += acumuladortam;
    }

    TMR /= n;

    cout << "el TMR minimo es: " << TMR << endl;
    cout << "los archivos estan en orden: ";
    for (int i = 0; i < n; i++) {
        cout << valores[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> valores = { 5,10,3 };

    almacenarcintas(valores);

    return 0;
}
