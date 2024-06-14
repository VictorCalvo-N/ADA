

//Encontrar la mediana de un vector
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double findMedian(vector<int>& nums) {
    int n = nums.size();
    if (n % 2 == 1) {
        // Tamaño impar va a devolver el valor del pivote
        return nums[n / 2];
    }
    else {
        // Tamaño par va a devolver el promedio de los dos valores cercanos al pivote
        return (nums[n / 2 - 1] + nums[n / 2]) / 2;
    }
}

int main() {
    int n;
    cout << "Ingrese el tamaño del vector: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Ingrese los elementos del vector: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    // Ordena el vector para encontrar la mediana
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; ++i) {
        cout << nums[i] << " ";
    }

    int median = findMedian(nums);
    if (median % 2) {
        cout << "La mediana más cercana del vector es: " << median << endl;
    }
    else {
        cout << "La mediana del vector es: " << median << endl;
    }


    return 0;
}
