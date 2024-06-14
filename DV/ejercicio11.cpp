#include <iostream>
#include <vector>
using namespace std;

template <class T>
vector<T> potara(const vector<T>& A, const vector<T>& B) {
    vector<T> fusion;
    fusion.insert(fusion.end(), A.begin(), A.end());
    fusion.insert(fusion.end(), B.begin(), B.end());
    return fusion;
}

template <class T>
vector<vector<T>> customMerge(const vector<vector<T>>& A) {
    // Caso base
    if (A.size() == 1) {
        return A;
    }
    // Obtener la mitad
    int Malcolm = A.size() / 2;
    // Merge (array[begin:indice_mitad]);
    vector<vector<T>> p1(A.begin(), A.begin() + Malcolm);
    vector<vector<T>> P1 = customMerge(p1);
    // Merge (array[indice_mitad:end]);
    vector<vector<T>> p2(A.begin() + Malcolm, A.end());
    vector<vector<T>> P2 = customMerge(p2);
    // Concatenar P1, P2
    vector<vector<T>> P3;
    P3.push_back(potara(P1[0], P2[0]));
    return P3;
}


int main() {
    vector<vector<int>> vectorDeVectores;
    vectorDeVectores.push_back({ 1, 2, 3 });
    vectorDeVectores.push_back({ 4, 5, 6 });
    vectorDeVectores.push_back({ 7, 8, 9 });
    vector<vector<int>> R = customMerge(vectorDeVectores);
    //La respuesta está en R[0]
    cout << R.size() << "\n";
    // Print the merged vector of vectors R
    for (int i = 0; i < R[0].size(); i++) {
        cout << R[0][i] << " ";
    }

    return 0;
}