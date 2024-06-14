/*
Diseñe un algoritmo "divide y vencerás" que permita calcular k-ésimos menos elemento de un vector.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int>& nums, int low, int high) {
    int pivot = nums[high];
    int i = low;
    for (int j = low; j < high; j++) {
        if (nums[j] < pivot) {
            swap(nums[i], nums[j]);
            i++;
        }
    }
    swap(nums[i], nums[high]);
    return i;
}

int quickSelect(vector<int>& nums, int low, int high, int k) {
    if (low == high) return nums[low];
    int pivot_index = partition(nums, low, high);
    if (k == pivot_index)
        return nums[k];
    else if (k < pivot_index)
        return quickSelect(nums, low, pivot_index - 1, k);
    else
        return quickSelect(nums, pivot_index + 1, high, k);
}

int findKthSmallest(vector<int>& nums, int k) {
    return quickSelect(nums, 0, nums.size() - 1, k - 1);
}

int main() {
    vector<int> nums = {7, 10, 4, 3, 20, 15};
    int k = 3;
    cout << "El " << k << "-esimo elemento mas pequeno es " << findKthSmallest(nums, k) << endl;
    return 0;
}