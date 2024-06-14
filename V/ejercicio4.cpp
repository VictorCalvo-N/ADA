#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

//PARTE A
struct Nodo {
    int id;
    int grado;
};

struct Arista {
    int nodo1;
    int nodo2;
};

set<int> recubrimientoGreedy(vector<Nodo>& nodos, vector<Arista>& aristas) {
    set<int> U;
    while (!aristas.empty()) {
        // Ordenar los nodos por grado de incidencia en orden descendente
        sort(nodos.begin(), nodos.end(), [](const Nodo& a, const Nodo& b) {
            return a.grado > b.grado;
            });

        // Agregar el nodo con mayor grado a U
        U.insert(nodos[0].id);

        // Eliminar las aristas que inciden en el nodo seleccionado
        aristas.erase(remove_if(aristas.begin(), aristas.end(), [&](const Arista& a) {
            return a.nodo1 == nodos[0].id || a.nodo2 == nodos[0].id;
            }), aristas.end());

        // Actualizar los grados de los nodos
        for (Nodo& nodo : nodos) {
            nodo.grado = std::count_if(aristas.begin(), aristas.end(), [&](const Arista& a) {
                return a.nodo1 == nodo.id || a.nodo2 == nodo.id;
                });
        }
    }
    return U;
}

int main() {
    // Crear un grafo
    vector<Nodo> nodos = { {1, 2}, {2, 2}, {3, 2}, {4, 1} };
    vector<Arista> aristas = { {1, 2}, {2, 3}, {3, 4} };

    // Obtener el recubrimiento del grafo
    set<int> U = recubrimientoGreedy(nodos, aristas);

    // Imprimir el recubrimiento
    cout << "Recubrimiento: ";
    for (int id : U) {
        cout << id << " ";
    }
    cout << endl;

    return 0;
}

//PARTE B
/*
b. El algoritmo greedy no siempre devuelve un recubrimiento minimal para cualquier grafo. La razón es que el algoritmo greedy toma decisiones locales óptimas en cada paso
(seleccionando el nodo con el mayor grado de incidencia) sin considerar el impacto global de estas decisiones. En algunos casos, estas decisiones locales óptimas pueden llevar a un
recubrimiento que no es minimal.
*/