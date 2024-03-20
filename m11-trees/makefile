CXX=g++
CXXFLAGS=-std=c++14 -Wall
LFLAGS=
TARGETS=test-bst
HEADERS=$(wildcard *.hpp)
SRC=$(wildcard *.cpp)
OBJS=$(SRC:%.cpp=%.o)
RM=rm -rf

all: $(TARGETS)

test-bst: test-bst.o
	$(CXX) $(LFLAGS) -o $@ $^
	./$@

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	$(RM) $(TARGETS) $(OBJS)
