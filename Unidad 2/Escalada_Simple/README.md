# Servicio Social: Inteligencia Artificial - ESCOM IPN

---

## Descripción del ejercicio
Consiste en la implementación de algoritmos de búsqueda informada. En esta etapa se ha desarrollado un buscador de rutas basado en el algoritmo de **Escalada Simple (Hill Climbing)** aplicado a la navegación de laberintos.

El objetivo es que el programa intente alcanzar la meta moviéndose siempre hacia la posición vecina que reduzca la distancia estimada al objetivo, basándose únicamente en información local.

## Algoritmo Implementado: Escalada Simple (Hill Climbing)
La Escalada Simple es una técnica de búsqueda local que toma decisiones de manera "codiciosa" (greedy). En cada paso, el algoritmo evalúa a sus vecinos inmediatos y se desplaza al que ofrece una mejor mejora respecto al estado actual.

### Características técnicas:
- **Heurística:** Se utiliza la **Distancia Manhattan** ($h(n) = |x_{meta} - x_{actual}| + |y_{meta} - y_{actual}|$) para evaluar la cercanía al objetivo.
- **Búsqueda Local:** El algoritmo no mantiene un registro de los estados anteriores (no tiene memoria de ruta), lo que lo hace muy eficiente en uso de memoria pero propenso a errores.
- **Limitación (Máximos Locales):** Si el agente llega a una posición donde todos sus vecinos tienen una peor heurística que la suya (como un callejón sin salida que apunta hacia la meta), el algoritmo se detiene aunque no haya llegado al objetivo.

---

## Estructura del Repositorio

.
├── main.cpp        # Código fuente del algoritmo (C++)
├── a.txt           # Archivo de entrada con el laberinto
├── Makefile        # Automatización de compilación
└── README.md       # Documentación del ejercicio

---

## Compilación y Ejecución
Para compilar el proyecto en Ubuntu, asegúrate de tener instalado `g++` y `make`. Sigue estos comandos en la terminal dentro de la carpeta `Escalada_Simple`:

```bash
# 1. Compilar el código usando el Makefile
make

# 2. Ejecutar el buscador
./escalada_simple

# 3. Limpiar los archivos ejecutables (opcional)
make clean