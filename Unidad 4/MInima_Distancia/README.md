# Servicio Social: Inteligencia Artificial - ESCOM IPN

---

## Descripción del ejercicio
Implementación del **Clasificador de Mínima Distancia**, un algoritmo de aprendizaje supervisado basado en instancias. Este desarrollo complementa la subsección 4.3.1 del temario oficial, fungiendo como un modelo alternativo y más eficiente en consumo de recursos que el K-Nearest Neighbors (KNN).

El programa predice la talla de calzado de un usuario basándose en su peso y estatura, abstrayendo primero las clases del conjunto de datos en puntos representativos.

## Algoritmo Implementado: Clasificador de Mínima Distancia
A diferencia de los modelos basados en vecindad local que retienen todos los datos de entrenamiento en memoria, este clasificador calcula el vector promedio de los atributos para cada clase durante una fase de pre-procesamiento.

### Características técnicas:
- **Cálculo de Centroides:** Agrupa los datos históricos por su etiqueta (Talla) y calcula la media aritmética de sus características espaciales (Estatura Promedio, Peso Promedio). 
- **Optimización de Complejidad (Big O):** Reduce la complejidad temporal de las consultas de $O(N)$ a $O(C)$, donde $N$ es la cantidad total de registros y $C$ es el número total de clases (tallas distintas).
- **Función de Similitud:** Utiliza la **Distancia Euclidiana** bidimensional para medir la divergencia entre el nuevo vector de características y los centroides de cada clase, asignando la etiqueta del centroide con la menor magnitud escalar.

---

## Estructura del Repositorio

.
├── main.cpp        # Código fuente del clasificador (C++)
├── a.txt           # Base de datos histórica (Estatura, Peso, Talla)
├── Makefile        # Automatización de compilación
└── README.md       # Documentación técnica

---

## Compilación y Ejecución

```bash
# 1. Compilar el código fuente
make

# 2. Ejecutar el modelo predictivo
./minima_distancia

# 3. Eliminar binarios generados
make clean