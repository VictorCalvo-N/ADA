/*
Un array se dice que tiene un elemento mayoritario si más de la mitad de sus
elementos tienen el mismo valor. Dado un array A, nos proponen que diseñemos
un algoritmo eficiente que nos permita determinar sin un array tiene un elemento
mayoritario y, en caso afirmativo, identifique dicho elemento. Ahora bien, los
elementos del array no tienen porqué pertener a un dominio ordenado como el
de los números enteros y, por tanto, NO se pueden realizar comparaciones del
tipo A[i] > A[j]. En cualquier caso, sí que se pueden realizar comprobaciones del
tipo A[i] == A[j]. 
*/

#include <iostream>
#include <vector>

using namespace std;

int findCandidate(vector<int>& nums) {
    int majorityIndex = 0;
    int count = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[majorityIndex] == nums[i])
            count++;
        else
            count--;
        if (count == 0) {
            majorityIndex = i;
            count = 1;
        }
    }
    return nums[majorityIndex];
}

bool isMajority(vector<int>& nums, int candidate) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
        if (nums[i] == candidate)
            count++;
    return count > nums.size() / 2;
}

int main() {
    vector<int> nums = {2, 2, 2, 2, 5, 5, 2, 3, 3};
    int candidate = findCandidate(nums);
    if (isMajority(nums, candidate))
        cout << "El elemento mayoritario es " << candidate << endl;
    else
        cout << "No hay elemento mayoritario" << endl;
    return 0;
}