TARGETS=main
CXX=g++
FLAGS=-std=c++11 -Wall
RM=rm -rf

.PHONY: clean

all: $(TARGETS)

# Target rules
main: main.o grade-book.o student.o grades.o
	$(CXX) -o $@ $^

# General compilation rules
%.o: %.cpp
	$(CXX) $(FLAGS) -c $<

clean:
	$(RM) *.o $(TARGETS) *.gc* *.dSYM
