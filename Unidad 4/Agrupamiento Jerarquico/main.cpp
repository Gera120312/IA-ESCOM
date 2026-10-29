#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <limits>
#include <algorithm>

using namespace std;

struct Punto {
    int id;
    vector<double> valores;
};

struct Cluster {
    int id;
    vector<Punto> puntos;
};

double calcularDistanciaEuclidiana(const vector<double>& p1, const vector<double>& p2) {
    double suma = 0.0;
    for (size_t i = 0; i < p1.size(); i++) {
        suma += pow(p1[i] - p2[i], 2);
    }
    return sqrt(suma);
}

double distanciaEntreClusters(const Cluster& c1, const Cluster& c2) {
    double distanciaMinima = numeric_limits<double>::max();
    for (const auto& p1 : c1.puntos) {
        for (const auto& p2 : c2.puntos) {
            double dist = calcularDistanciaEuclidiana(p1.valores, p2.valores);
            if (dist < distanciaMinima) {
                distanciaMinima = dist;
            }
        }
    }
    return distanciaMinima;
}

int main() {
    ifstream archivo("a.txt");
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir a.txt\n";
        return 1;
    }

    int numRegistros, numDimensiones, K;
    archivo >> numRegistros >> numDimensiones >> K;

    vector<Cluster> clusters;
    for (int i = 0; i < numRegistros; i++) {
        Punto p;
        p.id = i;
        p.valores.resize(numDimensiones);
        for (int j = 0; j < numDimensiones; j++) {
            archivo >> p.valores[j];
        }
        Cluster c;
        c.id = i; 
        c.puntos.push_back(p);
        clusters.push_back(c);
    }
    archivo.close();

    cout << "--- Agrupamiento Jerarquico (Aglomerativo - Single Linkage) ---\n\n";
    cout << "Estado inicial: " << clusters.size() << " clusters independientes.\n\n";

    int paso = 1;
    
    while (clusters.size() > 1) {
        double min_dist = numeric_limits<double>::max();
        int idx1 = -1, idx2 = -1;


        for (size_t i = 0; i < clusters.size(); i++) {
            for (size_t j = i + 1; j < clusters.size(); j++) {
                double dist = distanciaEntreClusters(clusters[i], clusters[j]);
                if (dist < min_dist) {
                    min_dist = dist;
                    idx1 = i;
                    idx2 = j;
                }
            }
        }

        cout << "Paso " << paso++ << ": Fusionando Cluster " << clusters[idx1].id 
            << " y Cluster " << clusters[idx2].id 
            << " (Distancia: " << fixed << setprecision(4) << min_dist << ")\n";

        for (const auto& p : clusters[idx2].puntos) {
            clusters[idx1].puntos.push_back(p);
        }
        
        
        clusters[idx1].id = min(clusters[idx1].id, clusters[idx2].id);

        
        clusters.erase(clusters.begin() + idx2);

        // if (clusters.size() == (size_t)K) {
        //     cout << "\nSe alcanzo el numero objetivo de " << K << " clusters.\n";
        //     break;
        // }
    }

    cout << "\n--- RESULTADO FINAL ---\n";
    for (size_t i = 0; i < clusters.size(); i++) {
        cout << "\nGRUPO " << i + 1 << " | Puntos totales: " << clusters[i].puntos.size() << "\n";
        for (const auto& p : clusters[i].puntos) {
            cout << "  -> Punto ID " << p.id << " [";
            for (size_t d = 0; d < p.valores.size(); d++) {
                cout << p.valores[d];
                if (d < p.valores.size() - 1) cout << ", ";
            }
            cout << "]\n";
        }
    }

    return 0;
}