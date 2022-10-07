TARGETS=main
CXX=g++
FLAGS=-std=c++14 -Wall
RM=rm -rf

.PHONY: clean

all: $(TARGETS)

# Target rules
main: main.o grade-book.o student.o grades.o
	$(CXX) -o $@ $^

# General compilation rules
# Any modification of header files will need recompilation
%.o: %.cpp
	$(CXX) $(FLAGS) -c $<

clean:
	$(RM) *.o $(TARGETS) *.gc* *.dSYM
