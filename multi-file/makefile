CXX = g++
FLAGS = -Wall -std=c++11 -g

store_print: driver.o store.o store_item.o
	$(CXX) -o $@ $^

driver.o: driver.cpp
	$(CXX) $(FLAGS) -c $^

store.o: store.cpp store.hpp
	$(CXX) $(FLAGS) -c $^

store_item.o: store_item.cpp store_item.hpp
	$(CXX) $(FLAGS) -c $^

clean:
	rm -rf *.dSYM
	rm -f *.o *.gc* store_print