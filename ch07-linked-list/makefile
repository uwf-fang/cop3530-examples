TARGETS = test-ll
CXXFLAGS = -Wall -std=c++14
RM = rm -rf

.PHONY: all clean

all : $(TARGETS)

test-ll: list-test.cpp singly-ll.hpp
	$(CXX) -o $@ $<
	./test-ll

clean :
	$(RM) $(TARGETS) *.o
