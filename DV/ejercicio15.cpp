#include <iostream>
#include <vector>
#include <algorithm>

// Función para contar las inversiones y mezclar los subarreglos
int mergeAndCount(std::vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    std::vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    std::vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);

    int i = 0, j = 0, k = l, swaps = 0;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
            swaps += (n1 - i);
        }
    }

    while (i < n1) {
        arr[k++] = left[i++];
    }
    while (j < n2) {
        arr[k++] = right[j++];
    }

    return swaps;
}

// Función recursiva para dividir el array y contar las inversiones
int mergeSortAndCount(std::vector<int>& arr, int l, int r) {
    int count = 0;
    if (l < r) {
        int m = l + (r - l) / 2;

        count += mergeSortAndCount(arr, l, m);
        count += mergeSortAndCount(arr, m + 1, r);
        count += mergeAndCount(arr, l, m, r);
    }
    return count;
}

// Función para calcular las inversiones entre dos rankings
int countInversions(std::vector<int>& rankA, std::vector<int>& rankB) {
    int n = rankA.size();
    std::vector<int> rankIndexA(n);
    std::vector<int> rankIndexB(n);

    for (int i = 0; i < n; i++) {
        rankIndexA[rankA[i] - 1] = i;
    }

    for (int i = 0; i < n; i++) {
        rankB[i] = rankIndexA[rankB[i] - 1];
    }

    return mergeSortAndCount(rankB, 0, n - 1);
}

int main() {
    std::vector<int> rankA = {1, 3, 2, 4};
    std::vector<int> rankB = {3, 1, 2, 4};

    std::cout << "Number of inversions: " << countInversions(rankA, rankB) << std::endl;

    return 0;
}