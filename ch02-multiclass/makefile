CXX = g++
FLAGS = -Wall -std=c++11

test: test.o store.o store-item.o
	$(CXX) -o $@ $^

test.o: test.cpp store.hpp store-item.hpp
	$(CXX) $(FLAGS) -c $<

store.o: store.cpp store.hpp
	$(CXX) $(FLAGS) -c $<

store-item.o: store-item.cpp store-item.hpp
	$(CXX) $(FLAGS) -c $<

clean:
	rm -rf *.o *.gc* test *.dSYM
