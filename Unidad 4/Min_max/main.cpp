#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <limits>

using namespace std;

struct Punto {
    int id;
    vector<double> valores;
    int idCluster = -1;
};

struct Cluster {
    int id;
    vector<double> centroide;
    vector<int> puntosTotales;
};

double calcularDistanciaEuclidiana(const vector<double>& p1, const vector<double>& p2) {
    double suma = 0.0;
    for (size_t i = 0; i < p1.size(); i++) {
        suma += pow(p1[i] - p2[i], 2);
    }
    return sqrt(suma);
}

int main() {
    ifstream archivo("a.txt");
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir a.txt\n";
        return 1;
    }

    int numRegistros, numDimensiones, K;
    archivo >> numRegistros >> numDimensiones >> K;

    vector<Punto> dataset(numRegistros);
    for (int i = 0; i < numRegistros; i++) {
        dataset[i].id = i;
        dataset[i].valores.resize(numDimensiones);
        for (int j = 0; j < numDimensiones; j++) {
            archivo >> dataset[i].valores[j];
        }
    }
    archivo.close();

    cout << "--- Algoritmo de Agrupamiento: Min-Max (Max-Min) ---\n\n";

    vector<Cluster> clusters(K);
    vector<bool> esCentroide(numRegistros, false);

    clusters[0].id = 0;
    clusters[0].centroide = dataset[0].valores;
    esCentroide[0] = true;
    cout << "Centroide 1 asignado al punto ID 0.\n";

    if (K > 1) {
        double maxDistancia = -1.0;
        int idMasLejano = -1;

        for (int i = 0; i < numRegistros; i++) {
            if (esCentroide[i]) continue;
            double distancia = calcularDistanciaEuclidiana(dataset[i].valores, clusters[0].centroide);
            if (distancia > maxDistancia) {
                maxDistancia = distancia;
                idMasLejano = i;
            }
        }
        clusters[1].id = 1;
        clusters[1].centroide = dataset[idMasLejano].valores;
        esCentroide[idMasLejano] = true;
        cout << "Centroide 2 asignado al punto ID " << idMasLejano << " (Maxima distancia al C1).\n";
    }

    for (int c = 2; c < K; c++) {
        double maxDeLasMinimas = -1.0;
        int idNuevoCentroide = -1;

        for (int i = 0; i < numRegistros; i++) {
            if (esCentroide[i]) continue;

            double distanciaMinima = numeric_limits<double>::max();
            for (int j = 0; j < c; j++) {
                double distancia = calcularDistanciaEuclidiana(dataset[i].valores, clusters[j].centroide);
                if (distancia < distanciaMinima) {
                    distanciaMinima = distancia;
                }
            }

            if (distanciaMinima > maxDeLasMinimas) {
                maxDeLasMinimas = distanciaMinima;
                idNuevoCentroide = i;
            }
        }

        clusters[c].id = c;
        clusters[c].centroide = dataset[idNuevoCentroide].valores;
        esCentroide[idNuevoCentroide] = true;
        cout << "Centroide " << c + 1 << " asignado al punto ID " << idNuevoCentroide << " (Criterio Max-Min).\n";
    }

    cout << "\n--- ASIGNACION DE PUNTOS ---\n";

    for (int i = 0; i < numRegistros; i++) {
        double distanciaMinima = numeric_limits<double>::max();
        int clusterMasCercano = -1;

        for (int j = 0; j < K; j++) {
            double distancia = calcularDistanciaEuclidiana(dataset[i].valores, clusters[j].centroide);
            if (distancia < distanciaMinima) {
                distanciaMinima = distancia;
                clusterMasCercano = j;
            }
        }
        dataset[i].idCluster = clusterMasCercano;
        clusters[clusterMasCercano].puntosTotales.push_back(i);
    }


    for (int i = 0; i < K; i++) {
        cout << "\nGRUPO " << i + 1 << " | Centroide Final: (";
        for (size_t d = 0; d < clusters[i].centroide.size(); d++) {
            cout << fixed << setprecision(2) << clusters[i].centroide[d];
            if (d < clusters[i].centroide.size() - 1) cout << ", ";
        }
        cout << ")\n";
        
        cout << "Puntos asignados (" << clusters[i].puntosTotales.size() << "): \n";
        for (int idPunto : clusters[i].puntosTotales) {
            cout << "  -> [";
            for (size_t d = 0; d < dataset[idPunto].valores.size(); d++) {
                cout << dataset[idPunto].valores[d];
                if (d < dataset[idPunto].valores.size() - 1) cout << ", ";
            }
            cout << "]\n";
        }
    }

    return 0;
}