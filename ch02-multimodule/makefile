TARGETS = main test
CXXFLAGS = -Wall -std=c++11
RM = rm -rf

all : $(TARGETS)

test: test.o threeintsfcts.o
	g++ -o $@ $^

test.o: test.cpp threeintsfcts.hpp
	g++ $(CXXFLAGS) -c $<

main : main.o threeintsfcts.o
	g++ -o $@ $^

main.o : main.cpp threeintsfcts.hpp
	g++ $(CXXFLAGS) -c $<

threeintsfcts.o : threeintsfcts.cpp threeintsfcts.hpp
	g++ $(CXXFLAGS) -c $<

clean :
	$(RM) $(TARGETS) *.o
