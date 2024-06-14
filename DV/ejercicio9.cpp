#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> moverdupiumerge(vector<int>& izq, vector<int>& dere) {
    vector<int> result;
    int i = 0, j = 0;
    while (i < izq.size() && j < dere.size()) {
        if (izq[i] < dere[j]) {
            if (!result.size() || result.back() != izq[i]) {
                result.push_back(izq[i]);
            }
            i++;
        }
        else {
            if (!result.size() || result.back() != dere[j]) {
                result.push_back(dere[j]);
            }
            j++;
        }
    }
    while (i < izq.size()) {
        if (!result.size() || result.back() != izq[i]) {
            result.push_back(izq[i]);
        }
        i++;
    }
    while (j < dere.size()) {
        if (!result.size() || result.back() != dere[j]) {
            result.push_back(dere[j]);
        }
        j++;
    }
    return result;
}

vector<int> eliminarduplicados(vector<int>& nums, int izq, int dere) {
    if (izq == dere) {
        return vector<int>{nums[izq]};
    }
    int mid = izq + (dere - izq) / 2;
    vector<int> izqPart = eliminarduplicados(nums, izq, mid);
    vector<int> derePart = eliminarduplicados(nums, mid + 1, dere);
    return moverdupiumerge(izqPart, derePart);
}

int main() {
    vector<int> nums = { 1, 2, 2, 3, 4, 4, 5, 6, 6, 7 };
    sort(nums.begin(), nums.end());  // Asegurarse de que el vector esté ordenado
    vector<int> result = eliminarduplicados(nums, 0, nums.size() - 1);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}