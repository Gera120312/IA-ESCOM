# Servicio Social: Inteligencia Artificial - ESCOM IPN

---

## Descripción del ejercicio
Culminación del módulo de **Agrupamiento (Tema 4.4)** con la implementación del **Algoritmo Jerárquico**. A diferencia de los métodos particionales (K-Medias, Min-Max), este algoritmo no requiere la inicialización de centroides ni la especificación previa del número de grupos objetivo, descubriendo de forma iterativa la estructura jerárquica subyacente de los datos.

## Algoritmo Implementado: Jerárquico Aglomerativo (Bottom-Up)
El proceso opera bajo una topología ascendente: inicializa cada instancia como un clúster unitario y procede a fusionar recursivamente los dos clústeres más cercanos hasta mostrar un clúster global unificado (representable mediante un dendrograma).

### Características técnicas:
- **Criterio de Similitud (Single Linkage):** Se implementó la técnica de *Enlace Simple*, donde la métrica de distancia entre dos clústeres se define como la Distancia Euclidiana mínima existente entre cualquier par de instancias de ambos grupos.
- **Complejidad Iterativa:** En cada ciclo iterativo, el algoritmo recalcula la matriz de distancias para evaluar las similitudes entre las agrupaciones recién formadas, priorizando las uniones de vecindad más estrecha.
- **Compatibilidad STL Restricta:** El código fuente C++ mantiene la estandarización multiplataforma, excluyendo directivas dependientes del sistema para posibilitar una compilación sin discrepancias entre el entorno de desarrollo (Ubuntu GCC) y el entorno de revisión (macOS Clang).

---

## Compilación y Ejecución (Entorno Linux)

```bash
# 1. Compilar el código fuente
make

# 2. Ejecutar el modelo aglomerativo
./jerarquico

# 3. Limpiar los archivos binarios
make clean