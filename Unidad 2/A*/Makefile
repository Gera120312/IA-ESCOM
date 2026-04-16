# Compilador a utilizar
CXX = g++

# Banderas del compilador:
CXXFLAGS = -Wall -std=c++17

# Nombre del ejecutable que se generará
TARGET = a_estrella_laberinto

# Archivo fuente
SRCS = main.cpp

# --- Reglas de Compilación ---

# Regla principal (la que se ejecuta al escribir 'make')
all: $(TARGET)

# Cómo construir el ejecutable a partir del código fuente
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# Regla para ejecutar el programa después de compilar
run: all
	./$(TARGET)

# Regla para limpiar archivos ejecutables y temporales
clean:
	rm -f $(TARGET)
	@echo "Limpieza completada."

# Indica que estas reglas no son archivos físicos
.PHONY: all clean run