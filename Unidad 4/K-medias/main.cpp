#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

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

    srand(time(0));

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

    cout << "--- Algoritmo de Agrupamiento: K-Medias (K-Means) ---\n\n";

    vector<Cluster> clusters(K);
    for (int i = 0; i < K; i++) {
        clusters[i].id = i;
        int indiceAleatorio = rand() % numRegistros;
        clusters[i].centroide = dataset[indiceAleatorio].valores;
    }

    bool huboCambios = true;
    int iteracion = 1;

    while (huboCambios) {
        huboCambios = false;
        cout << "Iteracion " << iteracion++ << "...\n";

        for (int i = 0; i < K; i++) {
            clusters[i].puntosTotales.clear();
        }


        for (int i = 0; i < numRegistros; i++) {
            double distanciaMinima = -1.0;
            int clusterMasCercano = -1;

            for (int j = 0; j < K; j++) {
                double distancia = calcularDistanciaEuclidiana(dataset[i].valores, clusters[j].centroide);
                if (distanciaMinima == -1.0 || distancia < distanciaMinima) {
                    distanciaMinima = distancia;
                    clusterMasCercano = j;
                }
            }


            if (dataset[i].idCluster != clusterMasCercano) {
                dataset[i].idCluster = clusterMasCercano;
                huboCambios = true;
            }

            clusters[clusterMasCercano].puntosTotales.push_back(i);
        }

        for (int i = 0; i < K; i++) {
            int numPuntos = clusters[i].puntosTotales.size();
            if (numPuntos == 0) continue; 

            vector<double> nuevoCentroide(numDimensiones, 0.0);
            for (int idPunto : clusters[i].puntosTotales) {
                for (int d = 0; d < numDimensiones; d++) {
                    nuevoCentroide[d] += dataset[idPunto].valores[d];
                }
            }

            for (int d = 0; d < numDimensiones; d++) {
                clusters[i].centroide[d] = nuevoCentroide[d] / numPuntos;
            }
        }
    }

    cout << "\n--- CONVERGENCIA ALCANZADA ---\n\n";
    for (int i = 0; i < K; i++) {
        cout << "GRUPO " << i + 1 << " | Centroide Final: (";
        for (int d = 0; d < numDimensiones; d++) {
            cout << fixed << setprecision(2) << clusters[i].centroide[d];
            if (d < numDimensiones - 1) cout << ", ";
        }
        cout << ")\n";
        
        cout << "Puntos asignados (" << clusters[i].puntosTotales.size() << "): \n";
        for (int idPunto : clusters[i].puntosTotales) {
            cout << "  -> [";
            for (int d = 0; d < numDimensiones; d++) {
                cout << dataset[idPunto].valores[d];
                if (d < numDimensiones - 1) cout << ", ";
            }
            cout << "]\n";
        }
        cout << "----------------------------------------\n";
    }

    return 0;
}