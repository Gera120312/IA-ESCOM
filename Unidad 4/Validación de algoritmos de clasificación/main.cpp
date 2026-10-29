#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <random>
#include <map>

using namespace std;

struct Instancia {
    vector<double> caracteristicas;
    string claseReal;
};


double distanciaEuclidiana(const vector<double>& a, const vector<double>& b) {
    double suma = 0.0;
    for (size_t i = 0; i < a.size(); i++) {
        suma += pow(a[i] - b[i], 2);
    }
    return sqrt(suma);
}


string predecirKNN(const vector<Instancia>& entrenamiento, const vector<double>& prueba, int K) {
    vector<pair<double, string>> distancias;
    for (const auto& inst : entrenamiento) {
        double dist = distanciaEuclidiana(inst.caracteristicas, prueba);
        distancias.push_back({dist, inst.claseReal});
    }
    
    sort(distancias.begin(), distancias.end());
    
    map<string, int> votos;
    for (int i = 0; i < K; i++) {
        votos[distancias[i].second]++;
    }
    
    string mejorClase = "";
    int maxVotos = -1;
    for (const auto& voto : votos) {
        if (voto.second > maxVotos) {
            maxVotos = voto.second;
            mejorClase = voto.first;
        }
    }
    return mejorClase;
}


void evaluarMatrizConfusión(const vector<string>& reales, const vector<string>& predicciones) {
    int VP = 0, VN = 0, FP = 0, FN = 0;
    string clasePositiva = "Pesado"; // Clase objetivo
    
    for (size_t i = 0; i < reales.size(); i++) {
        if (reales[i] == clasePositiva && predicciones[i] == clasePositiva) VP++;
        else if (reales[i] != clasePositiva && predicciones[i] != clasePositiva) VN++;
        else if (reales[i] != clasePositiva && predicciones[i] == clasePositiva) FP++;
        else if (reales[i] == clasePositiva && predicciones[i] != clasePositiva) FN++;
    }
    
    double exactitud = (double)(VP + VN) / reales.size();
    
    cout << "\n--- MATRIZ DE CONFUSION ---\n";
    cout << "                    Prediccion: Pesado   Prediccion: Ligero\n";
    cout << "Real: Pesado        [VP: " << VP << "]               [FN: " << FN << "]\n";
    cout << "Real: Ligero        [FP: " << FP << "]               [VN: " << VN << "]\n";
    cout << "\nMetricas de Rendimiento:\n";
    cout << "- Exactitud (Accuracy): " << fixed << setprecision(2) << exactitud * 100 << "%\n";
}

int main() {
    ifstream archivo("a.txt");
    if (!archivo.is_open()) {
        cerr << "Error al abrir a.txt\n";
        return 1;
    }
    
    int totalRegistros, numCaracteristicas;
    archivo >> totalRegistros >> numCaracteristicas;
    
    vector<Instancia> dataset(totalRegistros);
    for (int i = 0; i < totalRegistros; i++) {
        dataset[i].caracteristicas.resize(numCaracteristicas);
        for (int j = 0; j < numCaracteristicas; j++) {
            archivo >> dataset[i].caracteristicas[j];
        }
        archivo >> dataset[i].claseReal;
    }
    archivo.close();


    random_device rd;
    mt19937 g(rd());
    shuffle(dataset.begin(), dataset.end(), g);

    cout << "============= METODOS DE VALIDACION =============\n";

    int limite = totalRegistros * 0.8;
    vector<Instancia> entrenamiento(dataset.begin(), dataset.begin() + limite);
    vector<Instancia> prueba(dataset.begin() + limite, dataset.end());
    
    vector<string> realesHoldOut;
    vector<string> prediccionesHoldOut;
    
    for (const auto& inst : prueba) {
        realesHoldOut.push_back(inst.claseReal);
        prediccionesHoldOut.push_back(predecirKNN(entrenamiento, inst.caracteristicas, 3));
    }
    
    cout << "\n1. METODO HOLD-OUT (Particion 80/20)\n";
    evaluarMatrizConfusión(realesHoldOut, prediccionesHoldOut);

    int numPliegues = 5;
    int tamPliegue = totalRegistros / numPliegues;
    double exactitudAcumulada = 0.0;
    
    cout << "\n-------------------------------------------------\n";
    cout << "2. METODO K-FOLD CROSS VALIDATION (5 Pliegues)\n";
    
    for (int k = 0; k < numPliegues; k++) {
        vector<Instancia> trainFold, testFold;
        
        int inicioTest = k * tamPliegue;
        int finTest = inicioTest + tamPliegue;
        
        for (int i = 0; i < totalRegistros; i++) {
            if (i >= inicioTest && i < finTest) testFold.push_back(dataset[i]);
            else trainFold.push_back(dataset[i]);
        }
        
        int aciertos = 0;
        for (const auto& inst : testFold) {
            string pred = predecirKNN(trainFold, inst.caracteristicas, 3);
            if (pred == inst.claseReal) aciertos++;
        }
        
        double exactitudFold = (double)aciertos / testFold.size();
        exactitudAcumulada += exactitudFold;
        cout << "Pliegue " << k + 1 << " -> Exactitud: " << exactitudFold * 100 << "%\n";
    }
    
    cout << "\n=> Exactitud Promedio (K-Fold): " << (exactitudAcumulada / numPliegues) * 100 << "%\n";
    cout << "=================================================\n";

    return 0;
}