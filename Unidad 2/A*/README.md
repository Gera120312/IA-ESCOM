# Servicio Social: Inteligencia Artificial - ESCOM IPN


## Descripción del ejercicio
Consiste en la implementación de un buscador de rutas óptimas en laberintos utilizando el algoritmo A*. A diferencia de las búsquedas ciegas, este algoritmo utiliza una función de evaluación para encontrar el camino más corto de manera eficiente.

El objetivo es que el programa encuentre la ruta de menor costo desde un punto de inicio hasta una meta dentro de una matriz con obstáculos (paredes).

## Algoritmo Implementado: A* (A-Star Search)
El algoritmo A* selecciona el siguiente nodo a explorar minimizando la función:
**f(n) = g(n) + h(n)**

Donde:
* **g(n):** Es el costo real acumulado desde el inicio hasta el nodo actual.
* **h(n):** Es el costo estimado (heurística) desde el nodo actual hasta la meta.
* **0:** Representa un espacio libre.
* **1:** Representa un obstáculo o pared.

### Características técnicas:
- **Heurística:** Se utiliza la **Distancia Manhattan** ($|x1 - x2| + |y1 - y2|$) por ser ideal para movimientos en cuadrículas de 4 direcciones.
- **Estructura de Datos:** Implementación mediante una **Cola de Prioridad ** para garantizar que siempre se procese el nodo con el menor valor de $f(n)$.
- **Optimización:** A diferencia de DFS, A* garantiza encontrar el camino más corto siempre que la heurística sea admisible.

---

## Estructura del Repositorio

.
├── main.cpp        # Código fuente del algoritmo A* (C++)
├── a.txt           # Archivo de entrada con el laberinto
├── Makefile        # Automatización de compilación
└── README.md       # Documentación de esta unidad

---

## Compilación y Ejecución 
Para compilar el proyecto en Ubuntu, asegúrate de tener instalado g++ y make. Sigue estos comandos en la terminal dentro de la carpeta A*:

# 1. Compilar el código usando el Makefile
make

# 2. Ejecutar el buscador de rutas óptimas
./a_estrella_laberinto

# 3. Limpiar los archivos ejecutables (opcional)
make clean