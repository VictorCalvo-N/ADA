/*
Sea A un array bidimensional de tamaño nxn, parcialmente ordenado. El criterio de ordenación es el siguiente: Los elementos en cada fila y columna se encuentran en orden ascendente. Esto es:
A[i, j] ≤ A[i, j + 1] con i = {1..n} y j = {1..n-1}
A[i, j] ≤ A[i + 1, j] con i = {1..n-1} y j = {1..n}
El siguiente algoritmo nos permite determinar si un determinado elemento x se encuentra o no en el array:
int inArray (int x, int **A, int n)
{
 int f,c;
 f = 1;
 c = n-1;
 while ( (f<=n-1) && (c>=0) ) {
 if ( x < A[f][c] )
 c = c-1;
 else if ( x > A[f][c] )
 f = f+1;
 else
 return 1;
 }
 return 0;
} 
a. Calcule el tiempo de ejecución del algoritmo inArray.
b. Resuelva el problema anterior usando la técnia "divide y vencerás". Calcule la eficiencia del algoritmo "divide y vencerás" que diseñe y compárelo, en términos de eficiencia, con el algoritmo in Array.
*/

#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;
    int left = 0, right = matrix.size() * matrix[0].size() - 1, mid, value;
    while (left <= right) {
        mid = left + (right - left) / 2;
        value = matrix[mid / matrix[0].size()][mid % matrix[0].size()];
        if (value < target)
            left = mid + 1;
        else if (value > target)
            right = mid - 1;
        else
            return true;
    }
    return false;
}

int main() {
    vector<vector<int>> A = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    int x = 25;
    cout << (searchMatrix(A, x) ? "Elemento encontrado" : "Elemento no encontrado") << endl;
    return 0;
}

/*
a. El tiempo de ejecución del algoritmo inArray es O(n), donde n es el tamaño del array bidimensional. Esto se debe a que en el peor de los casos, el algoritmo recorrerá una fila y una columna del array, lo que da un total de 2n-1 iteraciones.

b. Este algoritmo tiene un tiempo de ejecución de 0(log(n)), ya que en cada iteración se divide el problema a la mitad. Por lo tanto, el algoritmo "divide y vencerás es más eficiente que el algoritmo inArray para grandes valores de n.
*/