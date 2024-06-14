#include <iostream>
#include <list>
#include <unordered_map>//para usar unordered_map
#include <vector>

using namespace std;

class LRUCache {//LRU significa Least Recently Used, es decir, el elemento que se ha accedido menos recientemente.
    list<int> dq;
	unordered_map<int, list<int>::iterator> ma;//unordered_map es un contenedor asociativo que almacena elementos formados por una combinación de un valor clave y un valor asociado, siguiendo un orden específico.
    int csize;

public:
    LRUCache(int n) {
        csize = n;
    }

    void referencias(int x) {
        if (ma.find(x) == ma.end()) {
            if (dq.size() == csize) {
                int ultim = dq.back();
                dq.pop_back();
                ma.erase(ultim);
            }
        }
        else
            dq.erase(ma[x]);

        dq.push_front(x);
        ma[x] = dq.begin();
    }

    void elementos() {
        for (auto it = dq.begin(); it != dq.end(); it++)
            cout << (*it) << " ";
        cout << endl;
    }
};

int main() {
    LRUCache ca(4);

    vector<int> cache = { 1, 2, 3, 1, 4, 5 };

    for (int r : cache) {
        ca.referencias(r);
        ca.elementos();
    }

    return 0;
}