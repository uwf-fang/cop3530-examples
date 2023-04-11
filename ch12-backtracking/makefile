CXX=g++
CXXFLAGS=-std=c++14 -Wall
LFLAGS=
TARGET=main
HEADERS=
SRC=sudoku.cpp
OBJS=$(SRC:%.cpp=%.o)
RM=rm -rf

$(TARGET): $(OBJS)
	$(CXX) $(LFLAGS) -o $@ $^

$(OBJS): %.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	$(RM) $(TARGET) $(OBJS)
