/*
Igual que antes, tenemos un problema de asignación de recursos en el que una tarea i requiere t_i unidades de tiempo y ha de terminar, como muy tarde, en el instante de tiempo d. Ahora bien, podemos escoger la hora de inicio de la tarea s_i de tal forma que f_i = s_i + t_i. Diseñe un algoritmo greedy que minimice el retraso máximo con el que se completa la tarea (esto es, max{0, f_i-d_i}).
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Tarea {
    int tiempo;
    int deadline;
};

bool compararTareas(Tarea a, Tarea b) {
    return a.deadline < b.deadline;
}

vector<int> asignarTareas(vector<Tarea> tareas) {
    sort(tareas.begin(), tareas.end(), compararTareas);

    vector<int> inicio(tareas.size());
    int tiempoActual = 0;
    for (int i = 0; i < tareas.size(); i++) {
        inicio[i] = tiempoActual;
        tiempoActual += tareas[i].tiempo;
    }
    return inicio;
}

int main() {
    vector<Tarea> tareas = {{2, 9}, {1, 8}, {3, 10}};
    vector<int> inicio = asignarTareas(tareas);
    for (int i = 0; i < inicio.size(); i++) {
        cout << "Tarea " << i + 1 << " inicia en el instante " << inicio[i] << endl;
    }
    return 0;
}