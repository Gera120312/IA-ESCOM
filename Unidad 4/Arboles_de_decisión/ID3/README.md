# Servicio Social: Inteligencia Artificial - ESCOM IPN

---

**Descripción del ejercicio**
Implementación del algoritmo **ID3 (Iterative Dichotomiser 3)** para la generación automática de Árboles de Decisión, abarcando el tema 4.3.2 del temario oficial. Este modelo de aprendizaje supervisado clasifica instancias mediante la creación de una estructura de árbol basada en reglas lógicas.

**Algoritmo Implementado: Árbol de Decisión ID3**
El algoritmo divide el conjunto de datos de entrenamiento en subconjuntos progresivamente más puros evaluando métricas basadas en la teoría de la información.

**Características técnicas:**
* **Entropía:** Mide matemáticamente el nivel de impureza o mezcla de clases en el conjunto de datos actual.
* **Ganancia de Información:** Evalúa la reducción de entropía lograda al segmentar los datos utilizando un atributo específico. El atributo que maximiza esta ganancia se selecciona como el nodo de decisión en la iteración actual.
* **Recursividad:** El proceso de partición se repite en cada rama hija hasta alcanzar una entropía nula (nodo hoja puro) o agotar los atributos disponibles.

---

**Compilación y Ejecución**
```bash
make
./arbol_id3
make clean