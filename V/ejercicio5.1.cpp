#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct cliente {
    int time;
};

bool comparar(cliente c1, cliente c2) {
    return c1.time < c2.time;
}

double propinamax(vector<cliente>& clientes) {
    sort(clientes.begin(), clientes.end(), comparar);

    double espera = 0;
    double propina = 0;

    for (cliente cliente : clientes) {
        espera += cliente.time;
        propina += 1 / espera;
    }

    return propina;
}

int main() {
    vector<cliente> clientes = { {5}, {3}, {1}, {4}, {2} };

    cout << propinamax(clientes) << endl;

    return 0;
}