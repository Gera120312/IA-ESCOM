# Servicio Social: Inteligencia Artificial - ESCOM IPN

---

## Descripción del ejercicio
Inicio del módulo de **Aprendizaje No Supervisado** (Sección 4.4 del temario). En esta etapa se implementó el algoritmo de agrupamiento **K-Medias (K-Means)**. 

A diferencia de los modelos de clasificación anteriores que requerían datos etiquetados (Aprendizaje Supervisado), este algoritmo busca descubrir la estructura oculta de los datos por sí mismo, agrupando las instancias basándose puramente en su similitud geométrica.

## Algoritmo Implementado: K-Medias (K-Means)
El modelo particiona un conjunto de $N$ observaciones en $K$ grupos (clusters), de manera que cada observación pertenece al grupo cuyo valor medio (centroide) es el más cercano espacialmente.

### Características técnicas:
- **Inicialización Estocástica:** Los $K$ centroides iniciales son seleccionados de forma aleatoria desde el propio conjunto de datos de entrenamiento mediante la siembra de una semilla temporal (`srand`).
- **Métrica Espacial:** Implementación generalizada de la **Distancia Euclidiana N-Dimensional**, permitiendo al algoritmo procesar bases de datos con cualquier número de atributos numéricos.
- **Ciclo de Convergencia:** El sistema itera matemáticamente entre dos pasos clave: la *Asignación* (asociar cada punto a su centroide más cercano) y la *Actualización* (recalcular el centro de masa de cada cluster). El bucle termina automáticamente cuando se alcanza la convergencia (ningún punto cambia de grupo).
- **Compatibilidad STL:** Código C++ estandarizado y libre de directivas específicas de sistema, validado para compilar  mediante `g++` (Linux) y `clang` (macOS).

---

## Estructura del Repositorio

.
├── main.cpp        # Código fuente del algoritmo K-Means (C++)
├── a.txt           # Base de datos sin etiquetar (Estatura, Peso, etc.)
├── Makefile        # Automatización de compilación
└── README.md       # Documentación técnica

---

## Compilación y Ejecución (Entorno Linux)

```bash
# 1. Compilar el código fuente
make

# 2. Ejecutar el modelo de agrupamiento
./kmeans

# 3. Limpiar los archivos binarios generados
make clean