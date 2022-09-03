TARGETS = test
CXXFLAGS = -Wall -std=c++14
RM = rm -rf

.PHONY: all clean

all : $(TARGETS)

test: list-test.cpp singly-ll.hpp
	g++ -o $@ $<

%.o : %.cpp
	g++ -c -o $@ $< $(CXXFLAGS)

clean :
	$(RM) $(TARGETS) *.o