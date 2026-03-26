# BFS (Breadth-First Search)

Implementacion del algoritmo BFS en C++ para recorrer un grafo por niveles.

## Funcionamiento

BFS (Busqueda en Anchura) explora primero los vecinos directos del nodo inicial,
luego los vecinos de esos vecinos, y asi sucesivamente. Para hacerlo usa una
cola (FIFO).

Pasos generales:

1. Marcar el nodo inicial como visitado.
2. Insertarlo en la cola.
3. Mientras la cola no este vacia:
   - Sacar el primer nodo.
   - Visitar sus vecinos no visitados.
   - Marcarlos e insertarlos en la cola.

## Complejidad

- Tiempo: O(V + E)
- Espacio: O(V)

Donde:

- V = numero de vertices
- E = numero de aristas

## Archivos

- main.cpp: implementacion de BFS con lectura por consola.
- Makefile: reglas para compilar, ejecutar y limpiar.

## Compilacion

```bash
make
```

Genera el ejecutable:

- bfs

## Ejecucion

```bash
make run
```

## Limpieza

```bash
make clean
```

## Formato de entrada del programa

1. Primera linea: numero de nodos y numero de aristas
2. Siguientes m lineas: aristas en formato `u v`
3. Ultima linea: nodo inicial para BFS

Ejemplo:

```text
5 6
0 1
0 2
1 3
2 3
3 4
1 4
0
```

Salida esperada (puede variar segun orden de adyacencia):

```text
Recorrido BFS: 0 1 2 3 4
```

## Nota

El codigo actual agrega ambas direcciones por cada arista (`u -> v` y `v -> u`),
por lo que trabaja como grafo no dirigido.
Si quieres usar grafo dirigido, comenta la linea:

```cpp
graph[v].push_back(u);
```
