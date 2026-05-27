# Servicio Social: Inteligencia Artificial - ESCOM IPN

---

## Descripción del ejercicio
En esta etapa, iniciamos con la **Unidad 4: Aprendizaje de Máquina**. Se ha implementado un clasificador basado en el algoritmo **K-Vecinos Más Cercanos (KNN)**, perteneciente a la categoría de aprendizaje supervisado.

El objetivo del programa es predecir una clase (en este caso, la **talla de zapato**) de una persona, basándose en dos características numéricas: su estatura (cm) y su peso (kg).

## Algoritmo Implementado: K-Nearest Neighbors (KNN)
KNN es un método de clasificación no paramétrico que asigna una clase a un dato nuevo basándose en la etiqueta de los "K" puntos de entrenamiento que se encuentren más próximos a él en el espacio de características.

### Características técnicas:
- **Medida de similitud:** Se utiliza la **Distancia Euclidiana** en un espacio bidimensional (Estatura, Peso) mediante la fórmula:
  $d = \sqrt{(x_2 - x_1)^2 + (y_2 - y_1)^2}$
- **Parámetro K:** El algoritmo selecciona a los $K$ individuos con menor distancia al punto objetivo. Es recomendable usar valores impares (ej. K=3) para evitar empates en clasificaciones binarias.
- **Votación por mayoría:** Las etiquetas de los $K$ vecinos se cuentan, y la etiqueta con mayor frecuencia se asigna como predicción final.

---

## Estructura del Repositorio

.
├── main.cpp        # Código fuente del clasificador KNN (C++)
├── a.txt           # Archivo de entrada (Parámetros, Dato de prueba y Dataset)
├── Makefile        # Automatización de compilación
└── README.md       # Documentación del ejercicio

---

## Compilación y Ejecución
Para compilar el proyecto en Ubuntu, ejecuta los siguientes comandos:

```bash
# 1. Compilar el código
make

# 2. Ejecutar el clasificador
./knn_tallas

# 3. Limpiar ejecutables
make clean