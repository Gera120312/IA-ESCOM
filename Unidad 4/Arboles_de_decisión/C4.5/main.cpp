#include <bits/stdc++.h>
using namespace std;

struct Nodo {
    bool esHoja = false;
    string valorClase = "";
    string nombreAtributo = "";
    int indiceAtributo = -1;
    map<string, Nodo*> ramas;
};

double calcularEntropia(const vector<vector<string>>& datos) {
    if (datos.empty()) return 0.0;
    map<string, int> conteoClases;
    for (const auto& fila : datos) conteoClases[fila.back()]++;
    
    double entropia = 0.0;
    double total = datos.size();
    for (const auto& par : conteoClases) {
        double probabilidad = par.second / total;
        entropia -= probabilidad * log2(probabilidad);
    }
    return entropia;
}

Nodo* construirC45(vector<vector<string>> datos, vector<string> nombresAtributos, vector<int> atributosDisponibles) {
    Nodo* nodo = new Nodo();
    
    double entropiaActual = calcularEntropia(datos);
    if (entropiaActual == 0.0 || atributosDisponibles.empty()) {
        map<string, int> conteo;
        string claseMayoritaria = "";
        int maxVotos = -1;
        for (const auto& fila : datos) {
            conteo[fila.back()]++;
            if (conteo[fila.back()] > maxVotos) {
                maxVotos = conteo[fila.back()];
                claseMayoritaria = fila.back();
            }
        }
        nodo->esHoja = true;
        nodo->valorClase = claseMayoritaria;
        return nodo;
    }
    
    int mejorAtributo = -1;
    double mayorGainRatio = -1.0;
    
    for (int attr : atributosDisponibles) {
        map<string, vector<vector<string>>> subgrupos;
        for (const auto& fila : datos) subgrupos[fila[attr]].push_back(fila);
        
        double entropiaEsperada = 0.0;
        double splitInfo = 0.0; // Métrica exclusiva de C4.5
        
        for (const auto& par : subgrupos) {
            double proporcion = (double)par.second.size() / datos.size();
            entropiaEsperada += proporcion * calcularEntropia(par.second);
            splitInfo -= proporcion * log2(proporcion); // Penalización
        }
        
        double ganancia = entropiaActual - entropiaEsperada;
        
        // Calcular Proporción de Ganancia (Gain Ratio)
        double gainRatio = 0.0;
        if (splitInfo > 0.0) {
            gainRatio = ganancia / splitInfo;
        }
        
        if (gainRatio > mayorGainRatio) {
            mayorGainRatio = gainRatio;
            mejorAtributo = attr;
        }
    }
    
    nodo->indiceAtributo = mejorAtributo;
    nodo->nombreAtributo = nombresAtributos[mejorAtributo];
    
    vector<int> atributosRestantes;
    for (int attr : atributosDisponibles) {
        if (attr != mejorAtributo) atributosRestantes.push_back(attr);
    }
    
    map<string, vector<vector<string>>> divisiones;
    for (const auto& fila : datos) divisiones[fila[mejorAtributo]].push_back(fila);
    
    for (const auto& par : divisiones) {
        nodo->ramas[par.first] = construirC45(par.second, nombresAtributos, atributosRestantes);
    }
    
    return nodo;
}

void imprimirArbol(Nodo* nodo, string indentacion = "") {
    if (nodo->esHoja) {
        cout << " ---> CLASE: [" << nodo->valorClase << "]\n";
        return;
    }
    cout << "\n";
    for (const auto& rama : nodo->ramas) {
        cout << indentacion << "<" << nodo->nombreAtributo << " == " << rama.first << ">";
        imprimirArbol(rama.second, indentacion + "    ");
    }
}

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
    for (int i = 0; i < numRegistros; i++) {
        for (int j = 0; j < numColumnas; j++) {
            archivo >> dataset[i][j];
        }
    }
    archivo.close();
    
    vector<int> atributosDisponibles;
    for (int i = 0; i < numColumnas - 1; i++) atributosDisponibles.push_back(i);
    
    cout << "--- Construyendo Arbol de Decision (C4.5 - Gain Ratio) ---\n";
    Nodo* raiz = construirC45(dataset, nombresAtributos, atributosDisponibles);
    
    cout << "\nEstructura del Arbol Generado:\n";
    imprimirArbol(raiz);
    cout << "\n";
    
    return 0;
}