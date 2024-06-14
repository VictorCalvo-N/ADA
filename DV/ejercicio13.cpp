#include <iostream>
#include <algorithm>
#include <vector>

struct Rectangulo {
    int x1, y1, x2, y2;
};

bool comparar(const Rectangulo& a, const Rectangulo& b) {
    return a.x1 < b.x1;
}

std::vector<Rectangulo> resolver(std::vector<Rectangulo> rectangulos) {
    if (rectangulos.size() <= 1) {
        return rectangulos;
    }

    std::sort(rectangulos.begin(), rectangulos.end(), comparar);

    std::vector<Rectangulo> izquierda(rectangulos.begin(), rectangulos.begin() + rectangulos.size() / 2);
    std::vector<Rectangulo> derecha(rectangulos.begin() + rectangulos.size() / 2, rectangulos.end());

    izquierda = resolver(izquierda);
    derecha = resolver(derecha);

    // Combinar las soluciones
    std::vector<Rectangulo> resultado;
    size_t i = 0, j = 0;
    while (i < izquierda.size() && j < derecha.size()) {
        if (izquierda[i].x2 < derecha[j].x1) {
            resultado.push_back(izquierda[i]);
            i++;
        } else if (derecha[j].x2 < izquierda[i].x1) {
            resultado.push_back(derecha[j]);
            j++;
        } else {
            if (izquierda[i].y1 < derecha[j].y1) {
                resultado.push_back(izquierda[i]);
                i++;
            } else {
                resultado.push_back(derecha[j]);
                j++;
            }
        }
    }

    while (i < izquierda.size()) {
        resultado.push_back(izquierda[i]);
        i++;
    }

    while (j < derecha.size()) {
        resultado.push_back(derecha[j]);
        j++;
    }

    return resultado;
}

int main() {
    std::vector<Rectangulo> rectangulos = {
        {0, 0, 1, 1},
        {1, 0, 2, 1},
        {0, 1, 1, 2},
        {1, 1, 2, 2}
    };

    std::vector<Rectangulo> resultado = resolver(rectangulos);

    for (const Rectangulo& rectangulo : resultado) {
        std::cout << rectangulo.x1 << " " << rectangulo.y1 << " "
                  << rectangulo.x2 << " " << rectangulo.y2 << "\n";
    }

    return 0;
}