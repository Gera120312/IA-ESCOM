# Servicio Social: Inteligencia Artificial - ESCOM IPN

---

## Descripción del ejercicio
En esta sección se ha implementado el algoritmo **Primero el Mejor (Best-First Search)**, clasificado dentro de los métodos de búsqueda informada. A diferencia de la Escalada Simple, este algoritmo cuenta con memoria a través de una cola de prioridad, lo que le permite recuperarse de caminos sin salida.

El objetivo es navegar un laberinto con obstáculos, seleccionando siempre el nodo que parece estar más cerca de la meta según la función heurística.

## Algoritmo Implementado: Primero el Mejor (Best-First Search)
Este algoritmo expande el nodo que tiene el menor valor en la función de evaluación, la cual se define exclusivamente por la heurística:
**$f(n) = h(n)$**

### Características técnicas:
- **Estructura de Datos:** Se emplea una **Cola de Prioridad (Min-Heap)** para organizar los nodos descubiertos.
- **Heurística:** Utiliza la **Distancia Manhattan** para estimar el costo restante.
- **Diferencia con A*:** Al ignorar el costo acumulado $g(n)$, el algoritmo busca la meta de manera más agresiva, pero **pierde la optimalidad** (puede encontrar la meta, pero no garantiza que sea por el camino más corto).
- **Recuperación:** Si entra en un callejón sin salida, extraerá de la cola el siguiente mejor nodo disponible que no haya sido explorado, permitiéndole continuar la búsqueda.

---

## Estructura del Repositorio

.
├── main.cpp        # Código fuente (C++)
├── a.txt           # Archivo de entrada con el laberinto
├── Makefile        # Automatización de compilación
└── README.md       # Documentación del ejercicio

---

## Compilación y Ejecución
Para compilar el proyecto en Ubuntu, asegúrate de tener instalado `g++` y `make`. Ejecuta los siguientes comandos:

```bash
# 1. Compilar el código usando el Makefile
make

# 2. Ejecutar el buscador de laberintos
./primero_mejor

# 3. Limpiar los archivos ejecutables (opcional)
make clean