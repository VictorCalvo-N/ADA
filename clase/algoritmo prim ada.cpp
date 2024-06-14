#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

vector<int> prim(vector<vector<PII>>& graph, int start) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);
    priority_queue<PII, vector<PII>, greater<PII>> pq;

    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        visited[u] = true;

        for (auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (!visited[v] && dist[v] > weight) {
                dist[v] = weight;
                pq.push({ dist[v], v });
            }
        }
    }

    return dist;
}

int main() {
    vector<vector<PII>> graph = {
        { {1, 2}, {2, 3} },
        { {0, 2}, {2, 1} },
        { {0, 3}, {1, 1} }
    };

    vector<int> result = prim(graph, 0);

    for (int i = 0; i < result.size(); i++) {
        cout << "distancia del 0 al nodo " << i << " es " << result[i] << endl;
    }

    return 0;
}