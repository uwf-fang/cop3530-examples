CXXFLAGS = -Wall -std=c++14
RM = rm -rf
TARGETS = test-quicksort test-ll-sorting

.PHONY: all clean

test-all : $(TARGETS)

# compile cpp files to object files
%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $<

# link and run all targets
$(TARGETS): % : %.o
	$(CXX) -o $@ $^
	./$@

test-quicksort: test-quicksort.o quicksort.o

clean :
	$(RM) $(TARGETS) *.o
