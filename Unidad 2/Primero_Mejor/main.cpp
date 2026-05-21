#include <bits/stdc++.h>
using namespace std;

struct Punto {
    int x, y;
    bool operator==(const Punto& otro) const { return x == otro.x && y == otro.y; }
};

// Estructura para la Cola de Prioridad
struct Nodo {
    Punto p;
    int h; 
    
    bool operator>(const Nodo& otro) const {
        return h > otro.h;
    }
};

int n, m;
Punto inicio, fin;
vector<vector<int>> mapa;
vector<vector<Punto>> padre;

int heuristica(Punto p) {
    return abs(p.x - fin.x) + abs(p.y - fin.y);
}

void bestFirstSearch() {
    priority_queue<Nodo, vector<Nodo>, greater<Nodo>> pq;
    vector<vector<bool>> visitado(n, vector<bool>(m, false));

    pq.push({inicio, heuristica(inicio)});
    visitado[inicio.x][inicio.y] = true;
    padre[inicio.x][inicio.y] = {-1, -1};

    bool encontrado = false;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!pq.empty()) {
        Nodo actual = pq.top();
        pq.pop();

        if (actual.p == fin) {
            encontrado = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = actual.p.x + dx[i];
            int ny = actual.p.y + dy[i];
            Punto vecino = {nx, ny};

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && mapa[nx][ny] == 0 && !visitado[nx][ny]) {
                visitado[nx][ny] = true;
                padre[nx][ny] = actual.p;
                pq.push({vecino, heuristica(vecino)});
            }
        }
    }

    if (encontrado) {
        cout << "¡Meta encontrada con Primero el Mejor (Best-First)!" << endl;
        vector<Punto> camino;
        Punto temp = fin;
        while (!(temp == Punto{-1, -1})) {
            camino.push_back(temp);
            temp = padre[temp.x][temp.y];
        }
        reverse(camino.begin(), camino.end());
        
        cout << "Ruta seguida (Nodos: " << camino.size() << "):" << endl;
        for (auto p : camino) cout << "(" << p.x << "," << p.y << ") ";
        cout << endl;
    } else {
        cout << "No se encontro un camino a la meta." << endl;
    }
}

int main() {
    if (freopen("a.txt", "r", stdin) == NULL) {
        cerr << "Error: No se pudo abrir el archivo a.txt" << endl;
        return 1;
    }

    cin >> n >> m;
    cin >> inicio.x >> inicio.y >> fin.x >> fin.y;
    
    mapa.assign(n, vector<int>(m));
    padre.assign(n, vector<Punto>(m, {-1, -1}));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> mapa[i][j];

    cout << "--- Algoritmo Primero el Mejor ---" << endl;
    
    bestFirstSearch();
    return 0;
}