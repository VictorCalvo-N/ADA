//Problema de las monedas
#include <iostream>
#include <vector>

using namespace std;

//valores de las monedas
vector<int> monedas = { 200, 100, 50, 20, 10, 5, 2 };

void cambioMonedas(int cantidad) {
    vector<int> solucion(monedas.size(), 0); // si es que inicia con ceros
    int k = 0; // opuntero para seleccionar monedas

    while (cantidad > 0 && k < monedas.size()) {
        if (monedas[k] <= cantidad) {
            // en caso e que la moneda es menor o igual a la cantidad, la utilizamos
            solucion[k]++;
            cantidad -= monedas[k];
        }
        else {
            // caso contrario pasamos a la siguiente moneda
            k++;
        }
    }

    cout << "Cambio para " << cantidad << " euros: ";
    for (int i = 0; i < monedas.size(); i++) {
        if (solucion[i] > 0) {
            cout << solucion[i] << " moneda(s) de " << monedas[i] / 100.0 << " euros ";
        }
    }
    cout << endl;
}

int main() {
    int cantidad = 350; // la cantidad a cambiar en céntimos 
    cambioMonedas(cantidad);
    return 0;
}
