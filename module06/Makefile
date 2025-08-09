# Compiler and flags
CXX     := g++
CXXFLAGS:= -Wall -Wextra -std=c++26

# Common objects (compiled once)
COMMON_OBJS := employee.o

# Exercise programs
EXERCISES := exercise01 exercise02 exercise03 exercise04 exercise05 exercise06 exercise07 exercise08

# Default target
all: $(EXERCISES)

# Build common objects once
$(COMMON_OBJS): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build each exercise directly from .cpp and the shared .o files
$(EXERCISES): %: %.cpp $(COMMON_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Clean target
clean:
	rm -f $(EXERCISES) $(COMMON_OBJS)

.PHONY: all clean
