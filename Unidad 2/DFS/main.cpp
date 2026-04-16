#include <bits/stdc++.h>
using namespace std;

struct punto {
    int x, y;
};

int n, m;
punto inicio, fin;
vector<vector<int>> mapa;
vector<vector<bool>> visitado;
vector<punto> camino;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool dfs(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return false;
    if (mapa[x][y] == 1 || visitado[x][y]) return false;

    visitado[x][y] = true;
    camino.push_back({x, y});

    if (x == fin.x && y == fin.y) return true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (dfs(nx, ny)) return true; 
    }

    camino.pop_back();
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    if (freopen("a.txt", "r", stdin) == NULL) {
        cerr << "Error: No se encontro el archivo a.txt" << endl;
        return 1;
    }
    
    if (!(cin >> n >> m)) return 0;
    
    mapa.assign(n, vector<int>(m));
    visitado.assign(n, vector<bool>(m, false));
    
    cin >> inicio.x >> inicio.y;
    cin >> fin.x >> fin.y;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mapa[i][j];
        }
    }

    cout << "--- Buscando salida con DFS ---" << endl;
    if (dfs(inicio.x, inicio.y)) {
        cout << "Ruta seguida (Coordenadas):" << endl;
        for (punto p : camino) {
            cout << "(" << p.x << ", " << p.y << ") -> ";
        }
        cout << "FIN" << endl;
    } else {
        cout << "No existe un camino para salir del laberinto." << endl;
    }

    return 0;
}