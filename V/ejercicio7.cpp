#include <iostream>
#include <vector>
using namespace std;

void repostarGasolineras(std::vector<int>& gasolineras, int tamtanque) {
    int paradas = 0;
    int distanciaRecorrida = 0;
    int tanque = tamtanque;

    for (int i = 0; i < gasolineras.size() - 1; ++i) {
        cout << "Tanque restante: " << tanque  << "\n";
        if (gasolineras[i+1] > distanciaRecorrida + tanque) {
            // Si no puede llegar a la gasolinera, se para a reposar
            std::cout << "Llenar tanque en la gasolinera del km " << gasolineras[i] << "\n" "\n";
            paradas++;
            distanciaRecorrida = gasolineras[i];
            tanque = tamtanque;
        }
        tanque = tanque - (gasolineras[i] - distanciaRecorrida);
        distanciaRecorrida = gasolineras[i];
    }
    cout << "Llegaste al destino" << "\n";
    std::cout << "Numero total de paradas: " << paradas << std::endl;
}

int main() {
    std::vector<int> gasolineras = {50,70,80,120,200,210,240,270,300,380,400}; // EL ultimo valor es el destino
    int tamtanque = 80;
    //s. Diseñe un algoritmo greedy que determine en qué gasolineras tiene que repostar y demuestre que su algoritmo encuentra siempre la solución óptima.
    //El algoritmo es greedy por que se toma deciciones en cada parada sin pensar en un impacto global, 
    //y siempre encuentra la solución óptima por que no se detiene si es que no lo necesita osea que llega a su objetivo con el menor numero de paradas. 
    repostarGasolineras(gasolineras, tamtanque);

    return 0;
}
