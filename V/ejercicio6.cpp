/*
Supongamos que disponemos de n trabajadores y n tareas. Sea c_y > 0 el coste de asignarle el trabajo j al trabajador i. Una asignación válida es aquella en la que a cada trabajador le corresponde una tarea y cada tarea la realiza un trabajador diferente. Dada una asignación válida, definimos el coste de dicha asignación como la suma total de los costes individuales. 
a. Diseñe distintas estrategias greedy para asignar tareas.
b. Encuentre contrajemplos que demuestren que ninguna de ellas no permite encontrar la solución óptima con un algoritmo greedy.
*/

#include <iostream>
#include <vector>

using namespace std;

//estrategia de menor coste individual
vector<int> asignarTareasMenorCoste(vector<vector<int>> costes) {
    int n = costes.size();
    vector<int> asignacion(n, -1);
    vector<bool> tareaAsignada(n, false);

    for (int i = 0; i < n; i++) {
        int minCoste = INT_MAX, tareaSeleccionada = -1;
        for (int j = 0; j < n; j++) {
            if (!tareaAsignada[j] && costes[i][j] < minCoste) {
                minCoste = costes[i][j];
                tareaSeleccionada = j;
            }
        }
        asignacion[i] = tareaSeleccionada;
        tareaAsignada[tareaSeleccionada] = true;
    }
    return asignacion;
}

//estrategia de menor coste total
vector<int> asignarTareasMenorCosteTotal(vector<vector<int>> costes) {
    int n = costes.size();
    vector<int> asignacion(n, -1);
    vector<bool> tareaAsignada(n, false);

    for (int i = 0; i < n; i++) {
        int minCosteTotal = INT_MAX, tareaSeleccionada = -1;
        for (int j = 0; j < n; j++) {
            if (!tareaAsignada[j]) {
                int costeTotal = 0;
                for (int k = 0; k <= i; k++)
                    costeTotal += costes[k][j];
                if (costeTotal < minCosteTotal) {
                    minCosteTotal = costeTotal;
                    tareaSeleccionada = j;
                }
            }
        }
        asignacion[i] = tareaSeleccionada;
        tareaAsignada[tareaSeleccionada] = true;
    }
    return asignacion;
}

int main() {
    vector<vector<int>> costes = {{1, 2, 3}, {2, 3, 1}, {3, 1, 2}};
    vector<int> asignacion = asignarTareasMenorCoste(costes);
    vector<int> asignacion2 = asignarTareasMenorCosteTotal(costes);

    for (int i = 0; i < asignacion.size(); i++) {
        cout << "Trabajador " << i+1 << " asignado a la tarea " << asignacion[i]+1 << endl;
    }

    cout << endl;

    for (int i = 0; i < (int)asignacion2.size(); i++) {
        cout << "Trabajador " << i+1 << " asignado a la tarea " << asignacion2[i]+1 << endl;
    }

    return 0;
}

/*
b. Contraejemplos para las estrategia greedy:
1. Estrategia de menor coste individual: Supongamos que tenemos 2 trabajdores y 2 tareas con los siguientes costes: c_11 = 1, c_12 = 2, c_21 = 2, c_22 = 1. La estrategia asignaría la tarea 1 al trabajador 1 y la tarea 2 al trabajador 2, con un coste total de 2. Sin embargo, la asignación óptima sería asignar la tarea 2 al trabajador 1 y la tarea 1 al trabajador 2, con un coste total de 3.

2. Estrategia de menor coste total: Supongamos que tenemos 3 trabajadores y 3 tareas con los siguientes costos: c_11 = 1, c_12 = 2, c_13 = 3, c_21 = 2, c_22 = 3, c_23 = 1, c_31 = 3, c_32 = 1, c_33 = 2. La estrategia asignaría la tarea 1 al trabajador 1, la tarea 2 al trabajador 2 y la tarea 3 al trabajador 3, con un coste total de 6. Sin embargo, la asignación óptima sería asignar la tarea 3 al trabajador 1, la tarea 1 al trabajador 2 y la tarea 2 al trabajador 3, con un coste total de 5.
*/
