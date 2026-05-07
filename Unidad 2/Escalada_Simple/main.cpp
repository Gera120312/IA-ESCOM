#include <bits/stdc++.h>
using namespace std;

struct Punto {
    int x, y;
    bool operator==(const Punto& otro) const { return x == otro.x && y == otro.y; }
};

int n, m;
Punto inicio, fin;
vector<vector<int>> mapa;

// Heurística: Distancia Manhattan
int heuristica(Punto p) {
    return abs(p.x - fin.x) + abs(p.y - fin.y);
}

void escaladaSimple() {
    Punto actual = inicio;
    vector<Punto> camino;
    camino.push_back(actual);

    cout << "--- Ejecutando Escalada Simple ---" << endl;

    while (!(actual == fin)) {
        Punto mejorVecino = {-1, -1};
        int mejorH = heuristica(actual);
        bool encontroMejor = false;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            Punto vecino = {actual.x + dx[i], actual.y + dy[i]};

            if (vecino.x >= 0 && vecino.x < n && vecino.y >= 0 && vecino.y < m && mapa[vecino.x][vecino.y] == 0) {
                int hVecino = heuristica(vecino);
                
                if (hVecino < mejorH) {
                    mejorH = hVecino;
                    mejorVecino = vecino;
                    encontroMejor = true;
                }
            }
        }

        if (!encontroMejor) {
            cout << "Atrapado en un maximo local o meta inalcanzable en: (" << actual.x << "," << actual.y << ")" << endl;
            break;
        }

        actual = mejorVecino;
        camino.push_back(actual);
    }

    if (actual == fin) {
        cout << "Meta encontrada" << endl;
    }

    cout << "Ruta seguida: ";
    for (auto p : camino) cout << "(" << p.x << "," << p.y << ") ";
    cout << endl;
}

int main() {
    if (freopen("a.txt", "r", stdin) == NULL) return 1;

    cin >> n >> m;
    cin >> inicio.x >> inicio.y >> fin.x >> fin.y;
    mapa.assign(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> mapa[i][j];

    escaladaSimple();
    return 0;
}