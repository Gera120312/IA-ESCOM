# Servicio Social: Inteligencia Artificial - ESCOM IPN

---

## Descripción del ejercicio
Implementación del algoritmo de agrupamiento **Min-Max (Max-Min)** correspondiente a la sección 4.4.1 del temario oficial. Este modelo de aprendizaje no supervisado actúa como una optimización determinista frente a la vulnerabilidad de inicialización aleatoria que presenta el algoritmo clásico de K-Medias.

## Algoritmo Implementado: Heurística Max-Min
El objetivo central es seleccionar $K$ centroides iniciales asegurando que estén lo más separados posible en el espacio geométrico, reduciendo el número de iteraciones necesarias para converger y evitando la creación de grupos empalmados o redundantes.

### Características técnicas:
- **Selección Determinista del Primer y Segundo Centroide:** El algoritmo elige el primer registro como centroide inicial. El segundo centroide se asigna al registro que posea la mayor Distancia Euclidiana respecto al primero.
- **Cálculo del Criterio Max-Min:** A partir del tercer centroide, el sistema evalúa la distancia mínima de cada candidato hacia todos los centroides ya establecidos. El registro cuya *distancia mínima* sea la *máxima* de todo el conjunto es promovido como el nuevo centroide.
- **Eficiencia y Compatibilidad:** Al igual que los módulos anteriores, el código fuente prescinde de cabeceras dependientes de plataforma, empleando la biblioteca estándar estricta de C++ para garantizar su compilación nativa en distribuciones Linux (GCC) y entornos macOS (Apple Clang).

---

## Compilación y Ejecución (Entorno Linux)

```bash
# 1. Compilar el código fuente
make

# 2. Ejecutar el modelo
./min_max

# 3. Limpiar los archivos binarios
make clean