CXXFLAGS = -Wall -std=c++14
RM = rm -rf

.PHONY: clean

test: test.o
	$(CXX) $(CXXFLAGS) -o $@ $^
	./$@

# link and run all targets
test.o: test.cpp singly.hpp doubly.hpp
	$(CXX) $(CXXFLAGS) -c $<

# compile cpp files to object files
%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean :
	$(RM) test *.o
