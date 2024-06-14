/*
Supongamos que el coste de tender una red de fibra óptica entre dos ciudades es proporcional a la distancia euclídea entre ellas.
a. Diseñe un algoritmo que permita interconectar un conjunto de ciudades minimizando el coste de la red de interconexión.
b. Busque un ejemplo en el que se demuestre que puede resultar más económico instalar una centralita entre ciudades que utilizar solamente conexiones directas entre ciudades.
*/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct Ciudad {
    int x, y;
};

struct Conexion {
    int ciudad1, ciudad2;
    double coste;
};

vector<int> padre;

int encontrarPadre(int ciudad) {
    if (padre[ciudad] == ciudad) {
        return ciudad;
    }
    return padre[ciudad] = encontrarPadre(padre[ciudad]);
}

bool unir(int ciudad1, int ciudad2) {
    ciudad1 = encontrarPadre(ciudad1);
    ciudad2 = encontrarPadre(ciudad2);
    if (ciudad1 != ciudad2) {
        padre[ciudad2] = ciudad1;
        return true;
    }
    return false;
}

double distancia(Ciudad a, Ciudad b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    vector<Ciudad> ciudades = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    int n = ciudades.size();

    padre.resize(n);
    for (int i = 0; i < n; i++) {
        padre[i] = i;
    }

    vector<Conexion> conexiones;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            conexiones.push_back({i, j, distancia(ciudades[i], ciudades[j])});
        }
    }

    sort(conexiones.begin(), conexiones.end(), [](Conexion a, Conexion b) {
        return a.coste < b.coste;
    });

    double costeTotal = 0;
    for (Conexion conexion : conexiones) {
        if (unir(conexion.ciudad1, conexion.ciudad2)) {
            costeTotal += conexion.coste;
            cout << "Conectando ciudad " << conexion.ciudad1 + 1 << " con ciudad " << conexion.ciudad2 + 1 << " con coste " << conexion.coste << endl;
        }
    }

    cout << "Coste total de la red de interconexi0n: " << costeTotal << endl;

    return 0;
}