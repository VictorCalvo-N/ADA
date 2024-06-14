/*
Dado un vector ordenado de números enteros X, diseñe un algoritmo "divide y vencerás" que permita determinar si existe un índice i tal que X[i] = i.
*/

#include <iostream>
#include <vector>

using namespace std;

int findIndex(vector<int>& nums, int low, int high) {
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if (mid == nums[mid])
            return mid;
        if (mid > nums[mid])
            return findIndex(nums, (mid + 1), high);
        else
            return findIndex(nums, low, (mid -1));
    }
    return -1;
}

int main() {
    vector<int> nums = {-10, -1, 0, 3, 10, 11, 30, 50, 100};
    int index = findIndex(nums, 0, nums.size() - 1);
    if (index != -1)
        cout << "El indice es " << index << endl;
    else
        cout << "No existe tal indice" << endl;
    return 0;
}