# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -Wall # Updated to C++17

# Program name
TARGET = programa

# Object files list - added zmogus.o
OBJS = main.o app.o funkcijos.o funkcijosVECTOR.o studentas.o

# Main rule for program compilation
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# Individual file compilation rules
main.o: main.cpp app.h funkcijos.h zmogus.h
	$(CXX) $(CXXFLAGS) -c main.cpp

app.o: app.cpp app.h funkcijos.h funkcijosVECTOR.h studentas.h zmogus.h
	$(CXX) $(CXXFLAGS) -c app.cpp

funkcijos.o: funkcijos.cpp funkcijos.h studentas.h zmogus.h
	$(CXX) $(CXXFLAGS) -c funkcijos.cpp

funkcijosVECTOR.o: funkcijosVECTOR.cpp funkcijosVECTOR.h studentas.h zmogus.h
	$(CXX) $(CXXFLAGS) -c funkcijosVECTOR.cpp

studentas.o: studentas.cpp studentas.h zmogus.h
	$(CXX) $(CXXFLAGS) -c studentas.cpp

# Rule to compile with different optimization levels
optimize: clean
	@echo "Optimization level -O1"
	$(CXX) $(CXXFLAGS) -O1 $(OBJS) -o $(TARGET)_O1
	@echo "Optimization level -O2"
	$(CXX) $(CXXFLAGS) -O2 $(OBJS) -o $(TARGET)_O2
	@echo "Optimization level -O3"
	$(CXX) $(CXXFLAGS) -O3 $(OBJS) -o $(TARGET)_O3

# Clean rule
clean:
	rm -f $(TARGET) $(TARGET)_O1 $(TARGET)_O2 $(TARGET)_O3 $(OBJS)
