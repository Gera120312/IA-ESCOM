#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;


string minusculas(string texto) {
    transform(texto.begin(), texto.end(), texto.begin(),
            [](unsigned char c){ return tolower(c); });
    return texto;
}

string respuesta(string entrada) {
    string minEntrada = minusculas(entrada);


    if (minEntrada.find("hola") != string::npos || minEntrada.find("buenos dias") != string::npos) {
        return "Hola. ¿Como te sientes el dia de hoy?";
    }

    else if (minEntrada.find("triste") != string::npos || minEntrada.find("mal") != string::npos) {
        return "Siento mucho escuchar eso. ¿Que crees que te hace sentir asi?";
    }

    else if (minEntrada.find("feliz") != string::npos || minEntrada.find("bien") != string::npos) {
        return "¡Que bueno! ¿Que ha pasado para que te sientas tan bien?";
    }

    else if (minEntrada.find("madre") != string::npos || minEntrada.find("padre") != string::npos || minEntrada.find("familia") != string::npos) {
        return "Cuentame mas sobre tu familia. ¿Como es tu relacion con ellos?";
    }

    else if (minEntrada.find("escuela") != string::npos || minEntrada.find("proyecto") != string::npos || minEntrada.find("escom") != string::npos) {
        return "El ambito academico puede ser estresante. ¿Te sientes presionado por tus entregas?";
    }

    else if (minEntrada.find("computadora") != string::npos || minEntrada.find("ia") != string::npos) {
        return "¿Te preocupan las computadoras o te fascinan?";
    }

    else if (minEntrada.find("adios") != string::npos || minEntrada.find("salir") != string::npos) {
        return "Ha sido un placer platicar contigo. ¡Hasta luego!";
    }

    else {
        return "¿Podrias profundizar un poco mas en eso?";
    }
}

int main() {
    cout << "=========================================================\n";
    cout << "   SISTEMA EXPERTO (Tipo ELIZA) - Psicoterapeuta Virtual\n";
    cout << "=========================================================\n";
    cout << "Hola. Soy tu terapeuta virtual. Escribe 'adios' para salir.\n";
    cout << "---------------------------------------------------------\n\n";

    string entradaUsuario;
    
    while (true) {
        cout << "Tu: ";
        getline(cin, entradaUsuario);
        
        if (entradaUsuario.empty()) continue;

        string res = respuesta(entradaUsuario);
        cout << "ELIZA: " << res << "\n" << endl;

        if (minusculas(entradaUsuario).find("adios") != string::npos || 
            minusculas(entradaUsuario).find("salir") != string::npos) {
            break;
        }
    }

    return 0;
}