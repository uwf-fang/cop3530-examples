TARGETS = test-ll
CXXFLAGS = -Wall -std=c++14
RM = rm -rf

.PHONY: all clean

test-all : test-singly test-doubly

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $<

test-doubly: test-doubly.o
	$(CXX) -o $@ $<
	./test-doubly

test-singly: test-singly.o
	$(CXX) -o $@ $<
	./test-singly

clean :
	$(RM) $(TARGETS) *.o
