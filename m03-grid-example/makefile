TARGETS = grid-driver
CXXFLAGS = -Wall -std=c++14
RM = rm -rf

.PHONY: all clean

all : $(TARGETS)

grid-driver : grid-driver.o grid.o
	g++ -o $@ $^

%.o : %.cpp
	g++ -c -o $@ $< $(CXXFLAGS)

clean :
	$(RM) $(TARGETS) *.o

test-memory : grid-driver
	valgrind --leak-check=full ./grid-driver
