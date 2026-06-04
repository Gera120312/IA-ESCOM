# Servicio Social: Inteligencia Artificial - ESCOM IPN

---

## Descripción del ejercicio
Como parte de la **Unidad 3: Modelos de representación del conocimiento**, se ha desarrollado un Sistema Experto interactivo basado en el clásico programa **ELIZA** (desarrollado originalmente en 1966 por Joseph Weizenbaum).

El objetivo es demostrar el funcionamiento del **razonamiento basado en reglas**, donde un agente inteligente procesa lenguaje natural simulando ser un psicoterapeuta mediante la búsqueda de patrones lógicos en las cadenas de texto del usuario.

## Algoritmo Implementado: Sistema Basado en Reglas (Pattern Matching)
El programa utiliza un motor de inferencia simplificado operando bajo una estrategia de encadenamiento hacia adelante. Evalúa los hechos (la entrada del usuario) contra una base de conocimientos (reglas predefinidas).

### Características técnicas:
- **Normalización de datos:** Las cadenas de entrada se procesan eliminando la sensibilidad a mayúsculas y minúsculas para asegurar coincidencias precisas.
- **Búsqueda de Patrones (Pattern Matching):** Se evalúa la presencia de secuencias de caracteres clave (tokens) utilizando la función `std::string::find`.
- **Estructura Lógica:** Las reglas operan en una jerarquía condicional. Si se cumple la premisa (ej. `SI "triste" ESTÁ EN entrada`), el sistema detona una conclusión o acción de respuesta (`ENTONCES imprimir "Siento escuchar eso"`).
- **Regla por defecto:** Incorpora una respuesta comodín para escenarios donde la entrada no coincide con ninguna regla de la base de conocimientos, permitiendo que la interacción no se interrumpa.

---

## Estructura del Repositorio

.
├── main.cpp        # Código fuente del motor de reglas (C++)
├── Makefile        # Automatización de compilación
└── README.md       # Documentación del ejercicio

---

## Compilación y Ejecución
Para compilar y probar el sistema experto en Ubuntu, ejecuta los siguientes comandos en la terminal:

```bash
# 1. Compilar el código
make

# 2. Iniciar la sesión con el terapeuta virtual
./eliza_bot

# 3. Limpiar los archivos ejecutables
make clean