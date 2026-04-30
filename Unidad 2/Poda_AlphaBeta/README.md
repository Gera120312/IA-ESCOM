# Servicio Social: Inteligencia Artificial - ESCOM IPN

---

## Descripción del ejercicio
Se ha implementado una versión optimizada de la búsqueda adversaria utilizando el algoritmo **Minimax con Poda Alfa-Beta**. El objetivo es reducir el número de nodos explorados en el árbol de decisión del juego del Gato.

## Algoritmo Implementado: Poda Alfa-Beta
La Poda Alfa-Beta es una variante del Minimax que busca detener la evaluación de movimientos que ya se han demostrado peores que otros examinados previamente.
* **Alfa ($\alpha$):** El mejor valor que el jugador MAX puede asegurar.
* **Beta ($\beta$):** El mejor valor que el jugador MIN puede asegurar.

### Características técnicas:
- **Eficiencia:** Cuando $\alpha \geq \beta$, se descarta el resto de la rama actual (poda), ya que el jugador correspondiente no elegirá ese camino.
- **Optimización de búsqueda:** Mantiene la garantía de encontrar el movimiento óptimo pero procesando significativamente menos estados.
- **Complejidad:** Reduce el factor de ramificación efectivo del árbol de juego.

---

## Estructura del Repositorio
.
├── main.cpp        # Código fuente con lógica de poda (C++)
├── Makefile        # Automatización de compilación
└── README.md       # Documentación del ejercicio

---

## Compilación y Ejecución
Para compilar en Ubuntu, ejecuta dentro de esta carpeta:
```bash
# 1. Compilar
make
# 2. Ejecutar
./minimax_poda
# 3. Limpiar
make clean