# Compiler name
CXX = g++

# Compiler flags
CXXFLAGS = -g -Wall -std=c++17

# Build target executable file; .exe is not required on Unix-based systems
SRC = main.cpp hangman.cpp hangman.h # List all your source code files here
OBJ = $(SRC:.cpp=.o)

PROGRAM = hangman

# List .cpp files separated by space
CPPFILES = hangman.cpp main.cpp

# Make all rule/default rule that will be run when we run "make"
# First compile each file to an object file
# Then make a single binary/executable program
all: $(PROGRAM)

$(PROGRAM): $(CPPFILES:.cpp=.o)
	$(CXX) $(CXXFLAGS) $(CPPFILES:.cpp=.o) -o $(PROGRAM)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Make clean rule
# Delete object and binary files
clean:
	rm -f $(PROGRAM) *.o

# Run Program
run:
	./$(PROGRAM)