#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Contenedor {
    int peso;
    int indice;
};

bool compararPorPeso(const Contenedor& c1, const Contenedor& c2) {
    return c1.peso < c2.peso;
}

void cargarContenedores(int capacidadBuque, vector<Contenedor>& contenedores) {
    int contenedoresCargados = 0;
    int pesoCargado = 0;

    // Ordenar los contenedores por peso
    sort(contenedores.begin(), contenedores.end(), compararPorPeso);

    for (const Contenedor& contenedor : contenedores) {
        if (pesoCargado + contenedor.peso <= capacidadBuque) {
            pesoCargado += contenedor.peso;
            contenedoresCargados++;
            cout << "Contenedor " << contenedor.indice << " cargado." << endl;
        }
        else {
            break;
        }
    }

    cout << "Total de contenedores cargados: " << contenedoresCargados << endl;
}

int main() {
    int capacidadBuque = 10; // Cambia el valor de acuerdo a tu problema
    vector<Contenedor> contenedores = { {7, 1}, {3, 2}, {4, 3}, {2, 4}, {5, 5} };

    cargarContenedores(capacidadBuque, contenedores);

    return 0;
}
