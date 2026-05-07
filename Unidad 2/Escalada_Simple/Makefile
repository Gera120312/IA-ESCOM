CXX = g++
CXXFLAGS = -Wall -std=c++17
TARGET = escalada_simple

all: $(TARGET)

$(TARGET): main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o $(TARGET)

clean:
	rm -f $(TARGET)

run: all
	./$(TARGET)