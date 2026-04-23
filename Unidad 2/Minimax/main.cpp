#include <bits/stdc++.h>

using namespace std;

const char IA = 'X';    
const char HUMANO = 'O'; 

void imprimirTablero(const vector<vector<char>>& b) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << b[i][j] << " ";
            if (j < 2) cout << "|";
        }
        cout << "\n";
        if (i < 2) cout << "-----------" << "\n";
    }
    cout << "\n";
}

bool hayMovimientos(const vector<vector<char>>& b) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (b[i][j] == ' ') return true;
    return false;
}

int evaluar(const vector<vector<char>>& b) {
    for (int i = 0; i < 3; i++) {
        if (b[i][0] == b[i][1] && b[i][1] == b[i][2]) {
            if (b[i][0] == IA) return +10;
            else if (b[i][0] == HUMANO) return -10;
        }
        if (b[0][i] == b[1][i] && b[1][i] == b[2][i]) {
            if (b[0][i] == IA) return +10;
            else if (b[0][i] == HUMANO) return -10;
        }
    }

    if (b[0][0] == b[1][1] && b[1][1] == b[2][2]) {
        if (b[0][0] == IA) return +10;
        else if (b[0][0] == HUMANO) return -10;
    }
    if (b[0][2] == b[1][1] && b[1][1] == b[2][0]) {
        if (b[0][2] == IA) return +10;
        else if (b[0][2] == HUMANO) return -10;
    }
    return 0;
}


int minimax(vector<vector<char>>& b, int profundidad, bool esMax) {
    int puntaje = evaluar(b);

    if (puntaje == 10) return puntaje - profundidad;
    if (puntaje == -10) return puntaje + profundidad;
    if (!hayMovimientos(b)) return 0;

    if (esMax) {
        int mejor = -1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (b[i][j] == ' ') {
                    b[i][j] = IA;
                    mejor = max(mejor, minimax(b, profundidad + 1, !esMax));
                    b[i][j] = ' '; 
                }
            }
        }
        return mejor;
    } else {
        int mejor = 1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (b[i][j] == ' ') {
                    b[i][j] = HUMANO;
                    mejor = min(mejor, minimax(b, profundidad + 1, !esMax));
                    b[i][j] = ' '; 
                }
            }
        }
        return mejor;
    }
}

pair<int, int> buscarMejorMovimiento(vector<vector<char>>& b) {
    int mejorVal = -1000;
    pair<int, int> mejorMov = {-1, -1};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (b[i][j] == ' ') {
                b[i][j] = IA;
                int movVal = minimax(b, 0, false);
                b[i][j] = ' ';
                if (movVal > mejorVal) {
                    mejorMov = {i, j};
                    mejorVal = movVal;
                }
            }
        }
    }
    return mejorMov;
}

int main() {
    vector<vector<char>> tablero(3, vector<char>(3, ' '));
    cout << "--- Juego del gato utilizando MINIMAX ---" << "\n";

    while (hayMovimientos(tablero) && evaluar(tablero) == 0) {
        imprimirTablero(tablero);
        int f, c;
        cout << "Tu turno (fila y col 0-2): ";
        cin >> f >> c;

        if (f < 0 || f > 2 || c < 0 || c > 2 || tablero[f][c] != ' ') {
            cout << "Movimiento invalido, intenta de nuevo." << "\n";
            continue;
        }

        tablero[f][c] = HUMANO;

        if (!hayMovimientos(tablero) || evaluar(tablero) != 0) break;

        cout << "Turno del adversario" << "\n";
        pair<int, int> mejor = buscarMejorMovimiento(tablero);
        tablero[mejor.first][mejor.second] = IA;
    }

    imprimirTablero(tablero);
    int resultado = evaluar(tablero);
    if (resultado == 10) cout << "Gana el adversario" << "\n";
    else if (resultado == -10) cout << "Ganaste (Esto no deberia pasar si el Minimax es correcto)" << "\n";
    else cout << "Empate" << "\n";

    return 0;
}