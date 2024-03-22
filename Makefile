# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -Wall # Updated to C++17

# Program name
TARGET = programa

# Object files list - added funkcijos.o
OBJS = main.o app.o funkcijosVECTOR.o funkcijosLIST.o funkcijosDEQUE.o studentas.o funkcijos.o

# Main rule for program compilation
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Individual file compilation rules
main.o: main.cpp app.h
	$(CXX) $(CXXFLAGS) -c main.cpp

app.o: app.cpp app.h funkcijosVECTOR.h funkcijosLIST.h funkcijosDEQUE.h studentas.h
	$(CXX) $(CXXFLAGS) -c app.cpp

funkcijosVECTOR.o: funkcijosVECTOR.cpp funkcijosVECTOR.h studentas.h
	$(CXX) $(CXXFLAGS) -c funkcijosVECTOR.cpp

funkcijosLIST.o: funkcijosLIST.cpp funkcijosLIST.h studentas.h
	$(CXX) $(CXXFLAGS) -c funkcijosLIST.cpp

funkcijosDEQUE.o: funkcijosDEQUE.cpp funkcijosDEQUE.h studentas.h
	$(CXX) $(CXXFLAGS) -c funkcijosDEQUE.cpp

studentas.o: studentas.cpp studentas.h
	$(CXX) $(CXXFLAGS) -c studentas.cpp

# Added compilation rule for funkcijos.cpp
funkcijos.o: funkcijos.cpp funkcijos.h
	$(CXX) $(CXXFLAGS) -c funkcijos.cpp

# Clean rule
clean:
	rm -f $(TARGET) $(OBJS)
