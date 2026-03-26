# Makefile para BFS en C++

CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2
TARGET := bfs
SRC := main.cpp
OBJ := $(SRC:.cpp=.o)

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)
