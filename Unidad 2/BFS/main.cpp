#include <iostream>
#include <queue>
#include <stdexcept>
#include <vector>

using namespace std;

vector<int> bfsTraversal(const vector<vector<int>>& graph, int start) {
    const int n = static_cast<int>(graph.size());
    if (start < 0 || start >= n) {
        throw invalid_argument("El nodo inicial esta fuera de rango.");
    }

    vector<bool> visited(n, false);
    queue<int> q;
    vector<int> order;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        order.push_back(current);

        for (int neighbor : graph[current]) {
            if (neighbor < 0 || neighbor >= n) {
                throw invalid_argument("Se detecto un vecino fuera de rango en la lista de adyacencia.");
            }
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return order;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    int m = 0;

    cout << "BFS en grafo dirigido/no dirigido (lista de aristas)\n";
    cout << "Ingresa numero de nodos y aristas: ";
    if (!(cin >> n >> m) || n <= 0 || m < 0) {
        cerr << "Entrada invalida para nodos/aristas.\n";
        return 1;
    }

    vector<vector<int>> graph(n);

    cout << "Ingresa " << m << " aristas en formato: u v\n";
    cout << "(nodos en rango 0 a " << (n - 1) << ")\n";

    for (int i = 0; i < m; ++i) {
        int u = 0;
        int v = 0;
        if (!(cin >> u >> v)) {
            cerr << "No se pudo leer la arista " << i + 1 << ".\n";
            return 1;
        }
        if (u < 0 || u >= n || v < 0 || v >= n) {
            cerr << "Arista fuera de rango en la entrada.\n";
            return 1;
        }

        graph[u].push_back(v);
        graph[v].push_back(u);  // Comentario esta linea si tu grafo es dirigido.
    }

    int start = 0;
    cout << "Ingresa nodo inicial para BFS: ";
    if (!(cin >> start)) {
        cerr << "Nodo inicial invalido.\n";
        return 1;
    }

    try {
        vector<int> order = bfsTraversal(graph, start);

        cout << "\nRecorrido BFS: ";
        for (size_t i = 0; i < order.size(); ++i) {
            cout << order[i] << (i + 1 < order.size() ? " " : "\n");
        }
    } catch (const exception& ex) {
        cerr << "Error: " << ex.what() << "\n";
        return 1;
    }

    return 0;
}
