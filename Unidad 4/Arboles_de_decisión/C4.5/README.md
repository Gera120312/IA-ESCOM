# Servicio Social: Inteligencia Artificial - ESCOM IPN

---

## Descripción del Módulo
Implementación del algoritmo **C4.5** para la generación de Árboles de Decisión (Tema 4.3.2). Este modelo supera las limitaciones matemáticas del ID3 al incorporar la métrica de **Proporción de Ganancia (Gain Ratio)**, la cual penaliza atributos con una alta ramificación para evitar el sobreajuste del modelo.

## Evolución sobre ID3
* **Gain Ratio vs Information Gain:** En lugar de seleccionar simplemente el atributo que reduce más la entropía, el algoritmo divide esa ganancia entre el valor de `SplitInfo`, equilibrando la toma de decisiones y evitando sesgos hacia atributos con múltiples valores únicos.

## Estructura del Repositorio

.
├── main.cpp        # Código fuente del árbol de decisión C4.5 (C++)
├── a.txt           # Base de datos histórica
├── Makefile        # Automatización de compilación
└── README.md       # Documentación técnica

---

## Compilación y Ejecución (Entorno Linux)
El proyecto incluye un Makefile configurado para el compilador `g++` en distribuciones Linux.

```bash
# 1. Compilar el código
make

# 2. Ejecutar el clasificador
./arbol_c45

# 3. Limpiar ejecutables
make clean