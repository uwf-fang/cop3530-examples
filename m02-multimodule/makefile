TARGETS = main test
CXXFLAGS = -Wall -std=c++14
RM = rm -rf

all : $(TARGETS)

test: test.o three-ints.o
	g++ -o $@ $^

test.o: test.cpp three-ints.hpp
	g++ $(CXXFLAGS) -c $<

main : main.o three-ints.o
	g++ -o $@ $^

main.o : main.cpp three-ints.hpp
	g++ $(CXXFLAGS) -c $<

three-ints.o : three-ints.cpp three-ints.hpp
	g++ $(CXXFLAGS) -c $<

clean :
	$(RM) $(TARGETS) *.o
