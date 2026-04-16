# Nombre del compilador
CXX = g++

# Banderas del compilador (Warnings activados y estándar C++17)
CXXFLAGS = -Wall -std=c++17

# Nombre del ejecutable final
TARGET = dfs_laberinto

# Archivos fuente
SRCS = main.cpp

# Regla por defecto: compila el proyecto
all: $(TARGET)

# Cómo construir el ejecutable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# Regla para limpiar los archivos generados
clean:
	rm -f $(TARGET)

# Regla para ejecutar el programa directamente
run: all
	./$(TARGET)