#include <iostream>
#include <vector>

using namespace std;

// para mezclar dos sublistas ordenadas
vector<int> merge(const vector<int>& izq, const vector<int>& dere) {
    vector<int> result;
    size_t i = 0, j = 0;

    while (i < izq.size() && j < dere.size()) {
        if (izq[i] >= dere[j]) {  // Cambio aquí
            result.push_back(izq[i]);
            ++i;
        }
        else {
            result.push_back(dere[j]);
            ++j;
        }
    }

    while (i < izq.size()) {
        result.push_back(izq[i]);
        ++i;
    }

    while (j < dere.size()) {
        result.push_back(dere[j]);
        ++j;
    }

    return result;
}

// para ordenar por la mezcla
vector<int> mergeSort(const vector<int>& i) {
    if (i.size() <= 1) {
        return i;
    }

    size_t mid = i.size() / 2;
    vector<int> izq(i.begin(), i.begin() + mid);
    vector<int> dere(i.begin() + mid, i.end());

    izq = mergeSort(izq);
    dere = mergeSort(dere);

    if (izq.back() >= dere.front()) {  // Cambio aquí
        izq.insert(izq.end(), dere.begin(), dere.end());
        return izq;
    }

    return merge(izq, dere);
}

int main() {
    vector<int> nums = { 9, 1, 3, 5, 0, 4, 2, 6, 8, 7 };
    vector<int> orderNUms = mergeSort(nums);

    cout << "Vector ordenado: ";
    for (int num : orderNUms) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}