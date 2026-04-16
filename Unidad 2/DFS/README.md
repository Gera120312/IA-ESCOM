# Servicio Social: Inteligencia Artificial - ESCOM IPN

---

## Descripción del ejercicio
Consiste en la implementación de algoritmos de búsqueda. Como primera etapa, se ha desarrollado un buscador de rutas en laberintos utilizando el algoritmo de Búsqueda en Profundidad (DFS) con una técnica de Backtracking.

El objetivo es que el programa encuentre una ruta válida desde un punto de inicio hasta una meta dentro de una matriz con obstáculos (paredes).

## Algoritmo Implementado: DFS (Depth-First Search)
La búsqueda en profundidad explora cada rama lo más posible antes de retroceder. En este ejercicio, la DFS se utiliza para navegar una matriz donde:
* **0:** Representa un espacio libre.
* **1:** Representa un obstáculo o pared.

### Características técnicas:
- **Recursividad:** Se utiliza la pila de llamadas del sistema para la exploración.
- **Backtracking:** Si el programa llega a un callejón sin salida, el algoritmo "retrocede" eliminando la posición actual de la ruta final para intentar un nuevo camino.
- **Control de ciclos:** Se utiliza una matriz de visitados para evitar que el programa entre en bucles infinitos.

---

## Estructura del Repositorio

.
├── main.cpp        # Código fuente principal (C++)
├── a.txt           # Archivo de entrada con el laberinto
├── Makefile        # Automatización de compilación
└── README.md       # Documentación del proyecto

## Compilación y Ejecución
Para compilar el proyecto en Ubuntu, asegúrate de tener instalado `g++` y `make`. Sigue estos comandos en la terminal:

# 1. Compilar el código usando el Makefile
make
# 2. Ejecutar el buscador de laberintos
./dfs_laberinto
# 3. Limpiar los archivos ejecutables (opcional)
make clean

