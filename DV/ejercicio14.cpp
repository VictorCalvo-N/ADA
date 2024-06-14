/*
Diseñe y analice la eficiencia de un algoritmo "divide y vencerás" para encontrar el par de puntos más cercano dentro de un conjunto de puntos en el plano. Se podría diseñar un algoritmo "específico" para este problema calculando las distancias entre todos los pares de puntos O(n2), pero la técnica "divide y vencerás" nos permite obtener una solución más eficiente de la siguiente forma:
a. Dividir: Se encuentra una línea vertical l que divide el conjunto P en dos
conjuntos P_I y P_D de forma que cada uno contiene la mitad de los puntos
en P. Todos los puntos en P_I están a la izquierda de la línea l y todos los
puntos en P_D se encuentran a la derecha. El vector X se divide en dos subvectores X_I y X_D que contienen los puntos en P_I y P_D ordenados según el valor de su coordenada x. De igual forma, el vector Y se divide en dos arrays Y_I e Y_D que contienen los puntos de P_I y P_D, ordenados según su coordenada y.
b. Resolver: Una vez divididos los vectores, se hacen las llamadas recursivas para encontrar los puntos más cercanos en P_I y P_D. La primera de ellas toma como argumentos los puntos P_I y los vectores X_I e Y_I. La segunda considera los puntos P_D y los vectores X_D e Y_D. Sean δ_I y δ_D las distancias más pequeñas en P_I y P_D.
c. Combinar: Los puntos más cercanos son aquéllos que se encontraron a menor distancia en las llamadas recursivas (δ = min{δ_I, δ_D}) o bien es un par con un punto en P_I y otro en P_D. El algoritmo, por tanto, debe encontrar si existe un par a una distancia menor que δ. La clave está en saber que estos puntos, de existir, se encuentran dentro de una ventana con 2δ de ancho y δ de alto centrada alrededor de la línea l.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <float.h>

using namespace std;

struct Point {
    int x, y;
};

bool compareX(Point a, Point b) { return a.x < b.x; }
bool compareY(Point a, Point b) { return a.y < b.y; }

double dist(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double bruteForce(vector<Point>& P, int n) {
    double min = DBL_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}

double stripClosest(vector<Point>& strip, int size, double d) {
    double min = d;
    sort(strip.begin(), strip.end(), compareY);
    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i], strip[j]) < min)
                min = dist(strip[i], strip[j]);
    return min;
}

double closestUtil(vector<Point>& Px, vector<Point>& Py, int n) {
    if (n <= 3)
        return bruteForce(Px, n);
    int mid = n / 2;
    Point midPoint = Px[mid];
    vector<Point> Pyl, Pyr;
    for (int i = 0; i < n; i++) {
        if (Py[i].x <= midPoint.x)
            Pyl.push_back(Py[i]);
        else
            Pyr.push_back(Py[i]);
    }
    vector<Point> leftPx(Px.begin(), Px.begin() + mid);
    vector<Point> rightPx(Px.begin() + mid, Px.end());
    double dl = closestUtil(leftPx, Pyl, mid);
    double dr = closestUtil(rightPx, Pyr, n - mid);
    double d = min(dl, dr);
    vector<Point> strip;
    for (int i = 0; i < n; i++)
        if (abs(Py[i].x - midPoint.x) < d)
            strip.push_back(Py[i]);
    return min(d, stripClosest(strip, strip.size(), d));
}

double closest(vector<Point>& P, int n) {
    vector<Point> Px = P, Py = P;
    sort(Px.begin(), Px.end(), compareX);
    sort(Py.begin(), Py.end(), compareY);
    return closestUtil(Px, Py, n);
}

int main() {
    vector<Point> P = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = P.size();
    cout << "La menor distancia es " << closest(P, n) << endl;
    return 0;
}