#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Definir el tipo de par para almacenar el índice de la licencia y su incremento de precio
typedef pair<int, double> licencia;

// Función para comparar dos licencias
bool comparar(licencia a, licencia b) {
    return a.second > b.second;
}

double costoTotal(vector<double> incrementos) {
    int n = incrementos.size();
    vector<licencia> licencias(n);

    // Crear la lista de licencias
    for (int i = 0; i < n; i++) {
        licencias[i] = make_pair(i, incrementos[i]);
    }

    // Ordenar la lista de licencias
    sort(licencias.begin(), licencias.end(), comparar);

    // Calcular el costo total
    double costo = 0;
    for (int k = 0; k < n; k++) {
        costo += 100 * pow(1 + licencias[k].second, k);
    }

    return costo;
}

int main() {
    // Crear un vector con los incrementos de precios
    vector<double> incrementos = {0.05, 0.1, 0.02, 0.03, 0.07};

    // Calcular el costo total
    double costo = costoTotal(incrementos);

    // Imprimir el costo total
    cout << "El costo total es: " << costo << std::endl;

    return 0;
}