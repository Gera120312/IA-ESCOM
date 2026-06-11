#include <bits/stdc++.h>

using namespace std;

struct Centroide {
    double sumaEstatura = 0.0;
    double sumaPeso = 0.0;
    int cantidad = 0;
    
    double promEstatura = 0.0;
    double promPeso = 0.0;
};


double distancia(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    cout << "--- Algoritmo Clasificador de Minima Distancia ---\n";
    
    double estaturaNueva, pesoNuevo;
    cout << "Ingrese la estatura a predecir (cm): ";
    cin >> estaturaNueva;
    cout << "Ingrese el peso a predecir (kg): ";
    cin >> pesoNuevo;

    ifstream archivo("a.txt");
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo a.txt. Asegurate de que exista.\n";
        return 1;
    }

    int n;
    archivo >> n;

    map<string, Centroide> grupos;

    for (int i = 0; i < n; i++) {
        double est, peso;
        string talla;
        archivo >> est >> peso >> talla;
        grupos[talla].sumaEstatura += est;
        grupos[talla].sumaPeso += peso;
        grupos[talla].cantidad++;
    }
    
    archivo.close();

    cout << "\n[1] Calculando Centroides (Individuos Promedio) de cada talla:\n";
    cout << "------------------------------------------------------------\n";
    
    for (auto& par : grupos) {
        par.second.promEstatura = par.second.sumaEstatura / par.second.cantidad;
        par.second.promPeso = par.second.sumaPeso / par.second.cantidad;
        
        cout << "Talla " << par.first << " -> Estatura promedio: " << fixed << setprecision(2) << par.second.promEstatura 
            << " cm | Peso promedio: " << par.second.promPeso << " kg (Basado en " << par.second.cantidad << " registros)\n";
    }

    cout << "\n[2] Calculando distancia hacia los Centroides:\n";
    cout << "------------------------------------------------------------\n";

    double distanciaMinima = numeric_limits<double>::max(); 
    string tallaPredicha = "";

    for (auto const& par : grupos) {
        double dist = distancia(estaturaNueva, pesoNuevo, par.second.promEstatura, par.second.promPeso);
        
        cout << "Distancia al Centroide Talla " << par.first << ": " << dist << "\n";

        if (dist < distanciaMinima) {
            distanciaMinima = dist;
            tallaPredicha = par.first;
        }
    }
    
    cout << "\nRESULTADO FINAL:\n";
    cout << "------------------------------------------------------------\n";
    cout << "La talla de zapato predicha es: " << tallaPredicha << "\n";
    cout << "(El punto ingresado es el mas cercano al centroide de esta clase)\n";
    cout << "------------------------------------------------------------\n";

    return 0;
}