# Servicio Social: Inteligencia Artificial - ESCOM IPN

---

## Descripción del ejercicio
En esta etapa de la **Unidad 4: Aprendizaje de Máquina**, se implementó el clasificador probabilístico **Naive Bayes**, abordando el subtema 4.3.3 del temario oficial. A diferencia de los modelos basados en distancia (como KNN o Mínima Distancia) o en partición lógica (ID3/C4.5), este algoritmo fundamenta su clasificación en estadística matemática, utilizando el Teorema de Bayes para calcular probabilidades condicionales.

El objetivo del programa es predecir la viabilidad de un evento (la clase final) basándose en un conjunto de atributos categóricos independientes, calculando las frecuencias históricas de una base de datos de entrenamiento.

## Algoritmo Implementado: Naive Bayes
Este modelo probabilístico calcula la probabilidad de que una nueva instancia pertenezca a una clase específica dada la evidencia de sus atributos. Se denomina "ingenuo" (naive) porque hace la fuerte suposición matemática de que todas las variables de entrada son completamente independientes entre sí.

### Características técnicas:
- **Cálculo Probabilístico Bayesiano:** En lugar de medir distancias espaciales, el programa realiza conteos de frecuencia para determinar la probabilidad a priori de cada clase y el producto de las probabilidades condicionales de los atributos observados.
- **Suavizado de Laplace (Laplace Smoothing):** Se integró un factor de corrección probabilística ($\alpha = 1$). Esto previene el problema del "colapso por frecuencia cero", evitando que una multiplicación por cero anule toda la probabilidad acumulada si se evalúa un valor de atributo que no existía en el conjunto de entrenamiento original.
- **Compatibilidad Multiplataforma (GCC / Clang):** El código fuente fue refactorizado para eliminar dependencias exclusivas de compiladores específicos (como la cabecera `<bits/stdc++.h>`). Se utilizan estrictamente las bibliotecas estándar de C++ (STL), lo que garantiza su compilación nativa y sin errores de dependencias tanto en distribuciones Linux como en entornos macOS.

---

## Estructura del Repositorio

.
├── main.cpp        # Código fuente del clasificador Naive Bayes (C++)
├── a.txt           # Base de datos histórica categórica (Atributos y Clase)
├── Makefile        # Automatización de compilación
└── README.md       # Documentación técnica

---

## Compilación y Ejecución (Entorno Linux)
Para compilar y ejecutar el proyecto nativamente en distribuciones Linux (Ubuntu), asegúrate de tener `g++` y `make` instalados, y ejecuta los siguientes comandos en la terminal de tu distribución:

```bash
# 1. Compilar el código fuente
make

# 2. Ejecutar el modelo interactivo
./naive_bayes

# 3. Limpiar los archivos binarios generados
make clean