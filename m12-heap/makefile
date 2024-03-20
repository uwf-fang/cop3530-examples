CXX=g++
CXXFLAGS=-std=c++14 -Wall
LFLAGS=
HEADERS=$(wildcard *.hpp)
SRC=$(wildcard *.cpp)
OBJS=$(SRC:%.cpp=%.o)
RM=rm -rf

# Compile and run the test
test: $(OBJS)
	$(CXX) $(LFLAGS) -o $@ $^
	./$@

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	$(RM) test $(OBJS)
