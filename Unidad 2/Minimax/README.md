# Servicio Social: Inteligencia Artificial - ESCOM IPN


## Descripción del ejercicio
Consiste en la implementación de un agente inteligente capaz de jugar al "Gato" (Tic-Tac-Toe) de forma óptima. Se utiliza una técnica de **Búsqueda Adversaria** para anticipar los movimientos del oponente y asegurar que el adversario nunca pierda.

El objetivo es que el programa evalúe todos los estados posibles del tablero para elegir el movimiento que maximice sus oportunidades de victoria o, en su defecto, asegure un empate.

## Algoritmo Implementado: Minimax
El algoritmo Minimax es un método de decisión para juegos de dos jugadores de suma cero e información perfecta. Funciona mediante la simulación de turnos alternados:
* **MAX (IA):** Busca el movimiento que devuelva el valor máximo.
* **MIN (Humano):** Busca el movimiento que devuelva el valor mínimo.

### Características técnicas:
- **Recursividad y Backtracking:** El algoritmo explora el árbol de juego de forma recursiva, probando movimientos y deshaciéndolos para evaluar otras ramas.
- **Función de Utilidad:** Se asignan valores de **+10** para la victoria de la IA, **-10** para la victoria del humano y **0** para el empate.
- **Factor de Profundidad:** Se resta la profundidad al puntaje de victoria para que la IA priorice ganar en el menor número de movimientos posibles (estrategia eficiente).

---

## Estructura del Repositorio

.
├── main.cpp        # Código fuente del juego y algoritmo (C++)
├── Makefile        # Automatización de compilación
└── README.md       # Documentación del ejercicio

## Notas
Para acceder a la posición de la matriz, los valores van del 0 al 2.
Ejemplo de una posición valida: 1 1, 0 2, 2 1


## Compilación y Ejecución
Para compilar el proyecto en Ubuntu, asegúrate de tener instalado `g++` y `make`. Sigue estos comandos en la terminal dentro de la carpeta `Minimax`:

```bash
# 1. Compilar el código usando el Makefile
make

# 2. Ejecutar el juego del Gato
./minimax_gato

# 3. Limpiar los archivos ejecutables (opcional)
make clean

----- 


