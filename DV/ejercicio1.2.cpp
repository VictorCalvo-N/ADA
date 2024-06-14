#include <iostream>

using namespace std;

void intercambio(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int particion(int nums[], int min, int mayor) {
    int pivot = nums[mayor];
    int i = (min - 1);

    for (int j = min; j <= mayor - 1; j++) {
        if (nums[j] < pivot) {
            i++;
            intercambio(&nums[i], &nums[j]);
        }
    }
    intercambio(&nums[i + 1], &nums[mayor]);
    return (i + 1);
}

void quickSort(int nums[], int min, int mayor) {
    if (min < mayor) {
        int pi = particion(nums, min, mayor);
        quickSort(nums, min, pi - 1);
        quickSort(nums, pi + 1, mayor);
    }
}

void imprimirnums(int nums[], int tam) {
    for (int i = 0; i < tam; i++)
        cout << nums[i] << " ";
    cout << endl;
}

int main() {
    int nums[] = { 9, 1, 3, 5, 0, 4, 2, 6, 8, 7 };
    int n = sizeof(nums) / sizeof(nums[0]);
    quickSort(nums, 0, n - 1);
    cout << "Numeros ordenados: \n";
    imprimirnums(nums, n);
    return 0;
}
