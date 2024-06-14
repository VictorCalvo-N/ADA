#include <iostream>

using namespace std;

int countLines(int n) {
    if (n <= 1) {
        return 0;
    }
    else {
        return 2 * countLines(n / 2) + 1;
    }
}

int main() {
    int n = 10;  // Cambie este valor para probar con diferentes valores de n
    cout << "El numero de lineas impresas es: " << countLines(n) << endl;
    return 0;
}
//Por lo tanto, el programa imprime 2n - 1 líneas en función de n.