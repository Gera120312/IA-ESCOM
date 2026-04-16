#include <bits/stdc++.h>
using namespace std;

struct Punto {
    int x, y;
    bool operator==(const Punto& otro) const { return x == otro.x && y == otro.y; }
};

struct Nodo {
    Punto p;
    int g, h, f;
    bool operator>(const Nodo& otro) const {
        return f > otro.f;
    }
};

int n, m;
Punto inicio, fin;
vector<vector<int>> mapa;

int calcular_h(Punto p) {
    return abs(p.x - fin.x) + abs(p.y - fin.y);
}

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void resolver_a_estrella() {
    priority_queue<Nodo, vector<Nodo>, greater<Nodo>> open_set;
    vector<vector<int>> g_score(n, vector<int>(m, INT_MAX));
    vector<vector<Punto>> parent(n, vector<Punto>(m, {-1, -1}));

    g_score[inicio.x][inicio.y] = 0;
    int h_ini = calcular_h(inicio);
    open_set.push({inicio, 0, h_ini, h_ini});

    while (!open_set.empty()) {
        Nodo actual = open_set.top();
        open_set.pop();

        if (actual.p == fin) {
            cout << "Camino encontrado con A*" << endl;

            vector<Punto> camino;
            Punto temp = fin;
            while (!(temp == Punto{-1, -1})) {
                camino.push_back(temp);
                temp = parent[temp.x][temp.y];
            }
            reverse(camino.begin(), camino.end());
            
            for (auto p : camino) cout << "(" << p.x << "," << p.y << ") ";
            cout << endl << "Costo total: " << g_score[fin.x][fin.y] << endl;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = actual.p.x + dx[i];
            int ny = actual.p.y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && mapa[nx][ny] == 0) {
                int nuevo_g = g_score[actual.p.x][actual.p.y] + 1;

                if (nuevo_g < g_score[nx][ny]) {
                    parent[nx][ny] = actual.p;
                    g_score[nx][ny] = nuevo_g;
                    int h = calcular_h({nx, ny});
                    open_set.push({{nx, ny}, nuevo_g, h, nuevo_g + h});
                }
            }
        }
    }
    cout << "No se encontró solución." << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if (freopen("a.txt", "r", stdin) == NULL) return 1;

    if (!(cin >> n >> m)) return 0;
    cin >> inicio.x >> inicio.y >> fin.x >> fin.y;

    mapa.assign(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> mapa[i][j];

    resolver_a_estrella();

    return 0;
}