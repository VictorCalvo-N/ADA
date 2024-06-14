#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct caracteristica {
    double x, y;
};

double distance(caracteristica a, caracteristica b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

vector<caracteristica> kMeans(vector<caracteristica>& clientes, int K) {
    vector<caracteristica> grupos(K);

    // Inicializar los centroides con puntos aleatorios
    for (int i = 0; i < K; i++)
        grupos[i] = clientes[rand() % clientes.size()];

    while (true) {
        vector<vector<caracteristica>> clusters(K);

        // Asignar cada punto al centroide más cercano
        for (caracteristica p : clientes) {
            int closest = 0;
            for (int i = 1; i < K; i++)
                if (distance(p, grupos[i]) < distance(p, grupos[closest]))
                    closest = i;
            clusters[closest].push_back(p);
        }

        // Calcular los nuevos grupos
        vector<caracteristica> newgrupos(K);
        for (int i = 0; i < K; i++) {
            double sumX = 0, sumY = 0;
            for (caracteristica p : clusters[i]) {
                sumX += p.x;
                sumY += p.y;
            }
            newgrupos[i] = { sumX / clusters[i].size(), sumY / clusters[i].size() };
        }

        // Si los grupos no han cambiado significativamente, terminar
        double maxShift = 0;
        for (int i = 0; i < K; i++)
            maxShift = max(maxShift, distance(grupos[i], newgrupos[i]));
        if (maxShift < 1e-5)
            break;

        grupos = newgrupos;
    }

    return grupos;
}

int main() {
    vector<caracteristica> clientes = { {1, 2}, {1, 4}, {1, 0}, {4, 2}, {4, 4}, {4, 0} };
    int k = 2;

    vector<caracteristica> grupos = kMeans(clientes, k);

    for (caracteristica c : grupos)
        cout << "(" << c.x << ", " << c.y << ")" << endl;

    return 0;
}