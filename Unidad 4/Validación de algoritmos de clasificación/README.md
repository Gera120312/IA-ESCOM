# Servicio Social: Inteligencia Artificial - ESCOM IPN

---

## Descripción del Módulo
Implementación de la sección **4.5.1 Métodos de validación de algoritmos de clasificación**. Este módulo estadístico evalúa la capacidad de generalización y la robustez predictiva de los modelos de aprendizaje supervisado, utilizando un algoritmo K-Nearest Neighbors (KNN) como clasificador de prueba para aislar y medir los fenómenos de sobreajuste (overfitting).

## Métodos Implementados
1. **Partición Hold-Out (Entrenamiento y Prueba):** Algoritmo que divide el conjunto de datos de manera estocástica, reservando el 80% de los registros para la construcción del espacio de conocimiento del modelo y aislando el 20% restante para evaluar su precisión predictiva ante datos no observados.
2. **Validación Cruzada (K-Fold Cross Validation):** Técnica de remuestreo iterativo estructurada en 5 pliegues. El conjunto de datos se rota dinámicamente, asegurando que cada registro actúe tanto como dato de entrenamiento como de validación en diferentes ciclos. Esto promedia el rendimiento del clasificador y mitiga sesgos derivados de particiones aleatorias favorables.
3. **Matriz de Confusión:** Estructura de tabulación bidimensional que clasifica las predicciones del modelo en Verdaderos Positivos (VP), Falsos Positivos (FP), Verdaderos Negativos (VN) y Falsos Negativos (FN). A partir de estos tensores, el módulo calcula paramétricamente la métrica de Exactitud (Accuracy) global del modelo.

## Compilación y Ejecución (Entorno Linux)

```bash
# 1. Compilar el código fuente
make

# 2. Ejecutar el módulo de validación
./validacion_clasificadores

# 3. Limpiar los archivos binarios
make clean