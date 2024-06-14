#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct tarea {
    int plazolimt;
    int beneficio;
};

bool compara(tarea t1, tarea t2) {
    if (t1.beneficio == t2.beneficio) {
        return t1.plazolimt < t2.plazolimt;
    }
    return t1.beneficio > t2.beneficio;
}

vector<tarea> selecttareas(vector<tarea>& tareas) {
    sort(tareas.begin(), tareas.end(), compara);

    vector<tarea> seleccionartareas;
    vector<bool> slot(tareas.size(), false);

    for (tarea tarea : tareas) {
        for (int j = min((int)tareas.size(), tarea.plazolimt) - 1; j >= 0; j--) {
            if (slot[j] == false) {
                slot[j] = true;
                seleccionartareas.push_back(tarea);
                break;
            }
        }
    }

    return seleccionartareas;
}

int main() {
    vector<tarea> tareas = { {2, 100}, {1, 19}, {2, 27}, {1, 25}, {3, 15} };

    vector<tarea> seleccionartareas = selecttareas(tareas);

    for (tarea tarea : seleccionartareas) {
        cout << "plazo limite: " << tarea.plazolimt << ", beneficio: " << tarea.beneficio << endl;
    }

    return 0;
}