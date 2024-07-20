CXXFLAGS = -Wall -std=c++14
RM = rm -rf
TARGETS = test-quicksort test-ll-sorting

.PHONY: all clean

test-all : $(TARGETS)

# compile cpp files to object files
test-ll-sorting.o: test-ll-sorting.cpp llist.hpp
	$(CXX) $(CXXFLAGS) -c $<

test-quicksort.o: test-quicksort.cpp
	$(CXX) $(CXXFLAGS) -c $<

quicksort.o: quicksort.cpp quicksort.hpp
	$(CXX) $(CXXFLAGS) -c $<

# link and run all targets
$(TARGETS): % : %.o
	$(CXX) -o $@ $^
	./$@

test-quicksort: test-quicksort.o quicksort.o

test-ll-sorting: test-ll-sorting.o

clean :
	$(RM) $(TARGETS) *.o
