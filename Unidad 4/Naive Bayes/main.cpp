#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    ifstream archivo("a.txt");
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir a.txt\n";
        return 1;
    }
    
    int numRegistros, numColumnas;
    archivo >> numRegistros >> numColumnas;
    
    vector<string> nombresAtributos(numColumnas);
    for (int i = 0; i < numColumnas; i++) archivo >> nombresAtributos[i];
    
    vector<vector<string>> dataset(numRegistros, vector<string>(numColumnas));
    map<string, int> conteoClases;
    map<string, map<int, map<string, int>>> conteoCaracteristicas; 
    vector<map<string, int>> valoresUnicos(numColumnas - 1); 

    for (int i = 0; i < numRegistros; i++) {
        for (int j = 0; j < numColumnas; j++) {
            archivo >> dataset[i][j];
        }
        string claseActual = dataset[i].back();
        conteoClases[claseActual]++;
        
        for (int j = 0; j < numColumnas - 1; j++) {
            conteoCaracteristicas[claseActual][j][dataset[i][j]]++;
            valoresUnicos[j][dataset[i][j]]++;
        }
    }
    archivo.close();

    cout << "--- Clasificador Naive Bayes ---\n\n";
    cout << "Ingrese los datos para predecir (Respetar mayusculas/minusculas):\n";
    
    vector<string> nuevaInstancia(numColumnas - 1);
    for (int i = 0; i < numColumnas - 1; i++) {
        cout << nombresAtributos[i] << ": ";
        cin >> nuevaInstancia[i];
    }
    
    cout << "\n--- Calculando Probabilidades Condicionales ---\n";
    
    string mejorClase = "";
    double mayorProbabilidad = -1.0;
    
    for (const auto& parClase : conteoClases) {
        string clase = parClase.first;
        int totalClase = parClase.second;
        
        double probClase = (double)totalClase / numRegistros;
        double probCondicionalAcumulada = 1.0;
        
        cout << "Evaluando Clase [" << clase << "]:\n";
        
        for (int i = 0; i < numColumnas - 1; i++) {
            string valor = nuevaInstancia[i];
            int coincidencias = conteoCaracteristicas[clase][i][valor];
            int totalValoresUnicosAttr = valoresUnicos[i].size();
            
            double probAtributo = (double)(coincidencias + 1) / (totalClase + totalValoresUnicosAttr);
            probCondicionalAcumulada *= probAtributo;
            
            cout << "  P(" << nombresAtributos[i] << "=" << valor << " | " << clase << ") = " 
                << fixed << setprecision(4) << probAtributo << "\n";
        }
        
        double probabilidadFinal = probClase * probCondicionalAcumulada;
        cout << "-> Probabilidad final para [" << clase << "]: " << probabilidadFinal << "\n\n";
        
        if (probabilidadFinal > mayorProbabilidad) {
            mayorProbabilidad = probabilidadFinal;
            mejorClase = clase;
        }
    }
    
    cout << "=================================================\n";
    cout << "PREDICCION FINAL: La clase mas probable es [" << mejorClase << "]\n";
    cout << "=================================================\n";

    return 0;
}