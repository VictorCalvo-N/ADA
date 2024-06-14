/*
Nuestra empresa desarrolla software para terminales de puntos de venta [TPV] y desea que le añadamos la siguiente funcionalidad a nuestro sistema:
a. En su versión para máquinas expendedoras, se pretende minimizar el número de monedas empleado para darle el cambio al cliente. Diseñe un algoritmo greedy que devuelva un número mínimo de monedas (de 0.01, 0.02, 0.05, 0.10, 0.20, 0.50 y 1 euro).
b. Nuestra empresa también distribuye máquinas expendedoras de sellos de correos (de 0.54, 0.32, 0.17, 0.01 euros) y decidimos reutilizar nuestro algoritmo greedy para decidir qué sellos no proporciona necesariamente una solución óptima, aun disponiendo de un suministro inagotable de sellos de cada valor.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> cambioMinimo(double total, vector<double> monedas) {
    vector<int> resultado(monedas.size(), 0);
    for (int i = monedas.size() - 1; i >= 0; i--) {
        while (total >= monedas[i]) {
            total -= monedas[i];
            resultado[i]++;
        }
    }
    return resultado;
}

int main() {
    vector<double> monedas = {0.01, 0.02, 0.05, 0.10, 0.20, 0.50, 1.00};
    double total = 1.87;
    vector<int> resultado = cambioMinimo(total, monedas);
    for (int i = 0; i < resultado.size(); i++) {
        cout << "Monedas de " << monedas[i] << ": " << resultado[i] << endl;
    }
    return 0;
}

/*
b. El algoritmo voraz no siempre proporcionará una solución óptima. Por ejemplo, si necesitas dar un cambio de 0.34 euros y usas el algoritmo voraz con los sellos disponible,
primero seleccionarías un sello de 0.32 euros y luego dos sellos de 0.01 euros, para un total de tres sellos. Sin embargo, la solución óptima sería usar dos sellos de 0.17 euros, para un total de solo dos sellos. Esto demuestra que el algoritmo voraz no siempre proporciona una solución óptima cuando los valores de los sellos o monedas no son múltiplos unos de otros.
*/