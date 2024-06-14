#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct cliente {
    int time;
};

bool comparar(cliente c1, cliente c2) {
    return c1.time > c2.time;
}

double propinamax(vector<cliente>& clientes, int k) {
    sort(clientes.begin(), clientes.end(), comparar);

    vector<double> espera(k, 0.0);
    double propina = 0;

    for (cliente c : clientes) {
        int minIndex = min_element(espera.begin(), espera.end()) - espera.begin();
        espera[minIndex] += c.time;
        propina += 1 / espera[minIndex];
    }

    return propina;
}

int main() {
    vector<cliente> clientes = { {5}, {3}, {1}, {4}, {2} };
    int k = 2;

    cout << propinamax(clientes, k) << endl;

    return 0;
}