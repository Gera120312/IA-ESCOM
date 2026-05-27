#include <bits/stdc++.h>

using namespace std;

struct Persona {
    double estatura;
    double peso;
    string talla;
};

struct Vecino {
    double distancia;
    string talla;
};


double distancia(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    cout << "--- Algoritmo K-Vecinos Mas Cercanos (KNN) ---\n";
    
    int K;
    cout << "Ingrese el número de consultas a realizar: ";
    cin >> K;

    double estaturaNueva, pesoNuevo;
    cout << "Ingrese la estatura (cm): ";
    cin >> estaturaNueva;
    cout << "Ingrese el peso (kg): ";
    cin >> pesoNuevo;

    ifstream archivo("a.txt");
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo a.txt. Asegurate de que exista en la carpeta.\n" ;
        return 1;
    }

    int n;
    archivo >> n;

    vector<Persona> dataset(n);
    for (int i = 0; i < n; i++) {
        archivo >> dataset[i].estatura >> dataset[i].peso >> dataset[i].talla;
    }
    
    archivo.close();

    vector<Vecino> distancias;

    for (int i = 0; i < n; i++) {
        double dist = distancia(estaturaNueva, pesoNuevo, dataset[i].estatura, dataset[i].peso);
        distancias.push_back({dist, dataset[i].talla});
    }

    sort(distancias.begin(), distancias.end(), [](const Vecino& a, const Vecino& b) {
        return a.distancia < b.distancia;
    });

    map<string, int> votos;
    for (int i = 0; i < K; i++) {
        cout << "Vecino " << i + 1 << " -> Talla: " << distancias[i].talla 
            << " | Distancia: " << distancias[i].distancia << "\n";
        votos[distancias[i].talla]++;
    }

    string tallaPredicha = "";
    int maxVotos = -1;
    bool hayEmpate = false;

    for (auto const& par : votos) {
        if (par.second > maxVotos) {
            maxVotos = par.second;
            tallaPredicha = par.first;
            hayEmpate = false; 
        } else if (par.second == maxVotos) {
            hayEmpate = true; 
        }
    }


    if (hayEmpate) {
        cout << "\n Empate detectado en la votacion.\n";
        cout << "Aplicando regla de desempate (Reduccion a K=1)...\n";
        tallaPredicha = distancias[0].talla; 
    }

    cout << "\nRESULTADO FINAL:\n";
    cout << "La talla de zapato predicha es: " << tallaPredicha << "\n";
    cout << "--------------------------------------------------\n";

    return 0;
}