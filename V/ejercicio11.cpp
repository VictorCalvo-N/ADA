#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct clase {
    int inicio, final;
};

bool compare(clase a, clase b) {
    return a.final < b.final;
}

int cuartosaulas(vector<clase>& aulas) {
    sort(aulas.begin(), aulas.end(), compare);

    int cuartos = 0;
    vector<int> horafinalcuarto;

    for (clase c : aulas) {
        bool asignado = false;

        for (int i = 0; i < cuartos; i++) {
            if (horafinalcuarto[i] <= c.inicio) {
                horafinalcuarto[i] = c.final;
                asignado = true;
                break;
            }
        }

        if (!asignado) {
            cuartos++;
            horafinalcuarto.push_back(c.final);
        }
    }

    return cuartos;
}

int main() {
    vector<clase> aulas = { {1, 4}, {2, 3}, {3, 5}, {5, 7}, {4, 6} };

    cout << cuartosaulas(aulas) << endl;

    return 0;
}