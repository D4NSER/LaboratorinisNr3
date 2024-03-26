# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -Wall # Updated to C++17

# Program name
TARGET = programa

# Object files list - added funkcijos.o
OBJS = main.o app.o funkcijos.o funkcijosVECTOR.o studentas.o

# Main rule for program compilation
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Individual file compilation rules
main.o: main.cpp app.h funkcijos.h
	$(CXX) $(CXXFLAGS) -c main.cpp

app.o: app.cpp app.h funkcijos.h funkcijosVECTOR.h studentas.h
	$(CXX) $(CXXFLAGS) -c app.cpp

funkcijos.o: funkcijos.cpp funkcijos.h studentas.h
	$(CXX) $(CXXFLAGS) -c funkcijos.cpp

funkcijosVECTOR.o: funkcijosVECTOR.cpp funkcijosVECTOR.h studentas.h
	$(CXX) $(CXXFLAGS) -c funkcijosVECTOR.cpp

studentas.o: studentas.cpp studentas.h
	$(CXX) $(CXXFLAGS) -c studentas.cpp

# Clean rule
clean:
	rm -f $(TARGET) $(OBJS)
