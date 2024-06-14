#include <iostream>
#include <vector>

using namespace std;

int particion(vector<int>& nums, int izq, int dere) {
    int pivotIndex = izq + (rand() % (dere - izq + 1));
    int pivot = nums[pivotIndex];
    swap(nums[pivotIndex], nums[dere]);
    int i = izq - 1;
    for (int j = izq; j < dere; j++) {
        if (nums[j] <= pivot) {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[dere]);
    return i + 1;
}

int quicjSelect(vector<int>& nums, int izq, int dere, int j) {
    if (izq == dere) {
        return nums[izq];
    }

    int pivotIndex = particion(nums, izq, dere);

    if (j == pivotIndex) {
        return nums[j];
    }
    else if (j < pivotIndex) {
        return quicjSelect(nums, izq, pivotIndex - 1, j);
    }
    else {
        return quicjSelect(nums, pivotIndex + 1, dere, j);
    }
}

double mediana(vector<int>& nums) {
    int n = nums.size();
    if (n % 2 == 1) {
        return quicjSelect(nums, 0, n - 1, n / 2);
    }
    else {
        return 0.5 * (quicjSelect(nums, 0, n - 1, n / 2 - 1) + quicjSelect(nums, 0, n - 1, n / 2));
    }
}

int main() {
    vector<int> nums = { 3, 2, 1, 5, 6, 4 };
    cout << "La mediana es: " << mediana(nums) << endl;
    return 0;
}